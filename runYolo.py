from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator
import time

model = YOLO('yolov8n.pt')
print("model =", model)

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error opening video capture.")
    exit()

prev_b = None  # Variable to store previous frame's boundary box coordinates
degree_constant = 0.036
while True:
    _, img = cap.read()

    if img.shape[0] > 0 and img.shape[1] > 0:
        results = model.predict(img)
        
        for r in results:
            annotator = Annotator(img)
            boxes = r.boxes
            
            for box in boxes:
                b = box.xyxy[0]  # get box coordinates in (left, top, right, bottom) format
                c = box.cls  # get box class value
                class_name = model.names[int(c)]
                if class_name == 'person':
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
                    annotator.box_label(b, class_name)  # display the bounding box on screen
                    print(class_name, ":", b)  # Print the box coordinate

                    prev_b = b  # Store current frame's boundary box coordinates as previous

        img = annotator.result()
        cv2.imshow('YOLO V8 Detection', img)

    time.sleep(1)

    if cv2.waitKey(1) & 0xFF == ord(' '):
        break

cap.release()
cv2.destroyAllWindows()
