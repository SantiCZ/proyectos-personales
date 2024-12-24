import time
import mediapipe as mp #pip install mediapipe
import cv2 as cv #pip install opencv-pyhton


# Configuracion de captura de video
cap = cv.VideoCapture(0)

# Inicializacion de MediaPipe Hands
mphands = mp.solutions.hands
hands = mphands.Hands(False)
mpDraw = mp.solutions.drawing_utils

pTime = 0
cTime = 0

while True:
    success, img = cap.read()

    # Conversion de BGR a RGB
    imgRGB = cv.cvtColor(img, cv.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    if results.multi_hand_landmarks:
        for handLms in results.multi_hand_landmarks:
            for id, lm in enumerate(handLms.landmark):
                h, w, c = img.shape
                cx, cy = int(lm.x * w), int(lm.y * h)
                print(id, cx, cy)
                if id == 0:  # Dibujar un circulo en el punto 0
                    cv.circle(img, (cx, cy), 10, (255, 0, 255), cv.FILLED)

            # Dibujar las conexiones de la mano
            mpDraw.draw_landmarks(img, handLms, mphands.HAND_CONNECTIONS)

    # Calculo de FPS
    cTime = time.time()
    fps = 1 / (cTime - pTime)
    pTime = cTime

    # Mostrar FPS en la imagen
    cv.putText(img, str(int(fps)), (10, 70), cv.FONT_HERSHEY_PLAIN, 3, (255, 0, 255), 3)

    # Mostrar imagen
    cv.imshow("Image", img)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Liberar recursos
cap.release()
cv.destroyAllWindows()
