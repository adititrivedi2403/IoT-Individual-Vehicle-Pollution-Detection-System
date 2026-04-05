from ultralytics import YOLO 
import cv2, easyocr, requests 
model = YOLO("yolov8n.pt") 
reader = easyocr.Reader(['en']) 
url = "http://<PHONE_IP>:8080/shot.jpg" 
while True: 
    img_resp = requests.get(url) 
    img_arr = np.array(bytearray(img_resp.content), dtype=np.uint8) 
 
 
    frame = cv2.imdecode(img_arr, -1) 
    results = model(frame) 
    for r in results[0].boxes: 
        x1,y1,x2,y2 = map(int, r.xyxy[0]) 
        plate = frame[y1:y2, x1:x2] 
        text = reader.readtext(plate, detail=0) 
        print("Plate Number: ", text) 
    cv2.imshow("Live", frame) 
    if cv2.waitKey(1)==ord('q'): 
        break
