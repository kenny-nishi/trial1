from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator
import time 
import glob
from PIL import Image
import os
import numpy as np
import time

model = YOLO('yolov8n.pt')
print("model =", model)

cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

prev_b = None  # Variable to store previous frame's boundary box coordinates
degree_constant = 0.036
while True:
    _, img = cap.read()
    
    results = model.predict(img)

    for r in results:
        
        annotator = Annotator(img)
        
        boxes = r.boxes
        for box in boxes:
            
            b = box.xyxy[0]  # get box coordinates in (left, top, right, bottom) format
            c = box.cls # get box class value, use model.names[int(c)] to get name of the class, such as person, remote
            annotator.box_label(b, model.names[int(c)]) # display the bounding box on screen 
            print(model.names[int(c)], ":", b) # Print the box coordinate 
          
    img = annotator.result()  
    cv2.imshow('YOLO V8 Detection', img)     
    if cv2.waitKey(1) & 0xFF == ord(' '):
        break
    
cap.release()
cv2.destroyAllWindows()