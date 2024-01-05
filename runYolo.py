#README
# Run $ pip install ultralytics 
# If there's AttributeError and some libraries are missing, such as cv2, cpuinfo, ultralytics, you're missing some libraries then just 
# search the libaries and pip install them back.
# Simple python3 runYolo.py, then it will display your webcam with detection boxes, terminal will show each detected box name and bounding box coordinates.
# for more information in working with the result detection, follow documentations in https://docs.ultralytics.com/reference/engine/results/#ultralytics.engine.results.Results.verbose
from ultralytics import YOLO
import cv2
from ultralytics.utils.plotting import Annotator 

model = YOLO('yolov8n.pt')
cap = cv2.VideoCapture(0)
cap.set(3, 640)
cap.set(4, 480)

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