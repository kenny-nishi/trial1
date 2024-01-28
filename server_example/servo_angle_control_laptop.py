import rclpy
from rclpy.node import Node
from testing_interfaces.srv import ServoControl

from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator
from PIL import Image
import os
import time
from transformers import CLIPProcessor, CLIPModel
import threading


angle = 90
model_yolo = YOLO('yolov8n.pt')
model_clip = CLIPModel.from_pretrained("openai/clip-vit-base-patch32")
processor = CLIPProcessor.from_pretrained("openai/clip-vit-base-patch32")
directory = 'new_directory/'

message = ''
instructions = "human wear a jacket"
class TakeCameraLatestPictureThread(threading.Thread):
    def __init__(self, camera):
        self.camera = camera
        self.frame = None
        super().__init__()
        # Start thread
        self.start()

    def run(self):
        while True:
            ret, self.frame = self.camera.read()

class ServoClientNode(Node): 
    def __init__(self,name):
        super().__init__(name)
        self.servo_client = self.create_client(ServoControl, '/change_angle')
        while not self.servo_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = ServoControl.Request()

    def send_request(self, angle):
        self.req.angle = angle
        self.future = self.servo_client.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

def send_change_angle_request(angle, node):
    return node.send_request(angle).response

def clip_selection(instructions,index_count):
    image = []
    if index_count == 0:
        return "error"
    for i in range(index_count):
        try:
            img_path = directory + str(i) + '.png'
            image.append(Image.open(img_path))
        except Exception as ex:
            print(f"An error occurred while opening the image: {ex}")
            
    inputs = processor(text=instructions, images=image, return_tensors="pt", padding=True)
    outputs = model_clip(**inputs)
    logits_per_text = outputs.logits_per_text
    probs = logits_per_text.softmax(dim=1)
    print(probs)
    # return the index, which is the file name of that
    return probs.argmax(dim=1)

max_angle_shift = 20
def update_shifting_just_compare_with_center(b, center,height, width):
    print(instructions)
    global angle
    # calculate the center of the boundary box
    # print(height, width) # 480, 640
    x1, y1, x2, y2 = b
    global message
    center_boundary_box = ((x1+x2)/2, (y1+y2)/2)
    # compare it should move right/left
    if(abs(center_boundary_box[0] - center[0]) < 20):
        print("Target in the center")
        message = 'center'
    else:
        if center_boundary_box[0] > center[0]:
            print("Target shifted left")
            message = 'left'
            angle -= max_angle_shift * (width / 640)
        elif center_boundary_box[0] < center[0]:
            print("Target shifted right")
            message = 'right'
            angle += max_angle_shift * (width / 640)
    return int(angle)



def main(args=None):
    print("This is servo_client_node.py")
    global instructions
    instructions = input("Please enter the instructions: ")
    # initialize the ros2 node
    rclpy.init(args=args)
    node = ServoClientNode('servo_client_node')

    # initialize the camera
    video_capture = cv2.VideoCapture("http://192.168.1.103:80/mjpeg")
    video_capture.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
    video_capture.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)
    if not video_capture.isOpened():
        raise Exception("Could not open video device")
    latest_picture = TakeCameraLatestPictureThread(video_capture)

    if not os.path.exists(directory):
        os.makedirs(directory)

    while True:
        # Iterate over the files in the directory and remove them
        for filename in os.listdir(directory):
            file_path = os.path.join(directory, filename)
            os.remove(file_path)

        # capture the image
        # Check if the frame is valid
        while(True):
            if latest_picture.frame is not None and latest_picture.frame.shape[0] > 0 and latest_picture.frame.shape[1] > 0:
                # Display the resulting frame
                img = latest_picture.frame
                break
        coordinate_list = []
        class_list = []

        # compute the size of image
        height, width, _ = img.shape
        # print(height, width) # 480, 640
        
        # the center of the image
        center = (width / 2, height / 2)
        # print(center) # (320.0, 240.0)

        # step 1: using Yolo model to capture the boundary box and find it center + cap the image
        result = model_yolo.predict(img)[0]
        annotator = Annotator(img)
        boxes = result.boxes
        for index, box in enumerate(boxes):
            # save images
            cords = box.xyxy[0].tolist()
            cords = [round(x) for x in cords]
            img = Image.fromarray(result.plot()[..., :: -1]) ## Original image
            img2 = img.crop(cords) ##Croped image
            # img2.save('testing.jpg')
            file_name = directory + str(index) + '.png'
            img2.save(file_name)
            # add the coordinate to the list
            coordinate_list.append(box.xyxy[0])
            class_name = model_yolo.names[int(box.cls)]
            class_list.append(class_name)

        # step 2: using clip model to find the most likely one image
        # instructions = "human eyes"
        tensor = clip_selection(instructions,len(coordinate_list))
        if tensor == 'error':
            continue
        index = tensor.item()
        b = coordinate_list[index]
        # print(index)
        class_name = class_list[index]
        # print(class_name)

        # step 3: update the shifting issue and only display the image with the target 
        angle = update_shifting_just_compare_with_center(b,center,height, width)
        print("angle: ", angle)
        send_change_angle_request(angle, node)

        # display the image with the target
        # annotator.box_label(b, class_name)  # display the bounding box on screen
        # annotator.box_label(b, instructions)  # display the bounding box on screen
        annotator.box_label(b, message)  # display the bounding box on screen
        # print(class_name, ":", b)  # Print the box coordinate
        img = annotator.result()  
        cv2.imshow('YOLO V8 Detection', img)   

        if cv2.waitKey(1) & 0xFF == ord(' '):
            break

    # release the ros2 node
    node.destroy_node()
    rclpy.shutdown()

    # Release the video capture and close the window
    video_capture.release()
    cv2.destroyAllWindows()
if __name__ == '__main__':
    main()


"""
TODO (finished):
1. the shifting issue should figure out how to make the target in the center of the image, but not compare with the previous frame (being fixed by Kenny's version)
2. reorganize the code, make it more readable (finished)
3. write the ros2 interface for the servo use (done)
3.1 should be mainly program in the micro_ros side, act as a client to ask eye camera to get the image
3.2 write the server side for the camera (should be the esp32 camera) for client to get the image from the camera
4. find some way to make the esp32 camera work (done)

kenny

future work; 
1. restructuring the code, make it more using multi-threading, and make it less delay problem
2. make the code more readable
3. make the version of contorling the updown servo
4. readme file setup and explaination required 

"""
