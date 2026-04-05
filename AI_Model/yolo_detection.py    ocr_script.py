from ultralytics import YOLO 
import cv2 
import warnings 
warnings.filterwarnings("ignore") 
model = YOLO("yolov8n.pt", verbose=False) 
url = "http://10.14.38.16:8080/video" 
cap = cv2.VideoCapture(url) 
while True: 
    ret, frame = cap.read() 
    if not ret: 
        break 
    results = model(frame, verbose=False) 
    annotated = results[0].plot() 
    cv2.imshow("Live YOLO View", annotated) 
    if cv2.waitKey(1) & 0xFF == ord('q'): 
        break 
cap.release() 
cv2.destroyAllWindows()
