from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator
import time 
import glob
from PIL import Image
import os
import numpy as np
import time
from transformers import CLIPProcessor, CLIPModel

# need to change the following code, see TODO at bottom
def update_shifting(b,prev_b):
    degree_constant = 0.036
    if prev_b is not None:
        prev_left, prev_left_top, prev_right, prev_right_bottom= prev_b
        curr_left, curr_left_top, curr_right, curr_right_bottom = b

        # Calculate the offset between previous and current frame boundary box
        left_offset = curr_left - prev_left
        right_offset = curr_right - prev_right
        left_top_offset = curr_left_top - prev_left_top
        right_bottom_offset = curr_right_bottom - prev_right_bottom
        # Determine the movement based on the offset
        if left_offset > 17:
            print("Target shifted left")
        elif left_offset < -17:
            print("Target shifted right")
        else:
            print("Target did not move horizontally")
        print("degree shifted =",left_offset*degree_constant)


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


model_yolo = YOLO('yolov8n.pt')
model_clip = CLIPModel.from_pretrained("openai/clip-vit-base-patch32")
processor = CLIPProcessor.from_pretrained("openai/clip-vit-base-patch32")
directory = 'new_directory/'

def main():
    cap = cv2.VideoCapture('http://172.20.10.2:80/mjpeg') #default 1, 'http://172.20.10.2:80/mjpeg'
    cap.set(3, 640)
    cap.set(4, 480)

    # img_paths = glob.glob(f"{}*", directory)
    img_paths = glob.glob(f"{directory}*")

    if not os.path.exists(directory):
        os.makedirs(directory)


    prev_b = None  # Variable to store previous frame's boundary box coordinates

    while True:

        # Iterate over the files in the directory and remove them
        for filename in os.listdir(directory):
            file_path = os.path.join(directory, filename)
            os.remove(file_path)

        # capture the image
        _, img = cap.read()
        coordinate_list = []
        class_list = []

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
        instructions = "human eyes"
        tensor = clip_selection(instructions,len(coordinate_list))
        if tensor == 'error':
            continue
        index = tensor.item()
        b = coordinate_list[index]
        print(index)
        class_name = class_list[index]
        print(class_name)

        # step 3: update the shifting issue and only display the image with the target 
        # update shifting
        update_shifting(b,prev_b)
        prev_b = b  # Store current frame's boundary box coordinates as previous

        # display the image with the target
        # annotator.box_label(b, class_name)  # display the bounding box on screen
        annotator.box_label(b, instructions)  # display the bounding box on screen
        print(class_name, ":", b)  # Print the box coordinate
        img = annotator.result()  
        cv2.imshow('YOLO V8 Detection', img)   

        if cv2.waitKey(1) & 0xFF == ord(' '):
            break
        # time.sleep(0.5)

    cap.release()
    cv2.destroyAllWindows()
if __name__ == "__main__":
    main()
"""
TODO:
1. the shifting issue should figure out how to make the target in the center of the image, but not compare with the previous frame
2. reorganize the code, make it more readable (finished)
3. write the ros2 interface for the servo use
3.1 should be mainly program in the micro_ros side, act as a client to ask eye camera to get the image
3.2 write the server side for the camera (should be the esp32 camera) for client to get the image from the camera
4. find some way to make the esp32 camera work 

kenny
"""
