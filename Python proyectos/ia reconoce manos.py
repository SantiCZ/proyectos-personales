import time # Importa el modulo para trabajar con tiempo
import mediapipe as mp #pip install mediapipe, para procesamiento de video e imagen
import cv2 as cv #pip install opencv-pyhton, vision por computadora


# Configuracion de captura de video
cap = cv.VideoCapture(0) #(indice 0 significa la camara principal)

# Inicializacion de MediaPipe Hands
mphands = mp.solutions.hands 
hands = mphands.Hands(False) #Crea una instancia de Hands; el parametro False desactiva la deteccion continua
mpDraw = mp.solutions.drawing_utils #

pTime = 0 # Tiempo del frame anterior
cTime = 0 # Tiempo actual

while True:
    success, img = cap.read()  # Lee un frame de la camara

    # Conversion de BGR a RGB
    imgRGB = cv.cvtColor(img, cv.COLOR_BGR2RGB)
    results = hands.process(imgRGB)

    if results.multi_hand_landmarks: # Si se detectan manos
        for handLms in results.multi_hand_landmarks: # Itera sobre las manos detectadas
            for id, lm in enumerate(handLms.landmark): #Itera sobre los puntos clave de la mano
                h, w, c = img.shape # Obtiene las dimensiones de la imagen
                cx, cy = int(lm.x * w), int(lm.y * h) # Calcula las coordenadas x e y del punto clave en pixeles
                print(id, cx, cy)  # Muestra el ID del punto y sus coordenadas
                if id == 0:  # Dibujar un circulo en el punto 0
                    cv.circle(img, (cx, cy), 10, (255, 0, 255), cv.FILLED) # Si es el punto clave 0 (muñeca)

            # Dibujar las conexiones de la mano
            mpDraw.draw_landmarks(img, handLms, mphands.HAND_CONNECTIONS)

    # Calculo de FPS
    cTime = time.time() #Tiempo actual
    fps = 1 / (cTime - pTime) #Inverso del tiempo transcurrido entre frames
    pTime = cTime #Actualiza el tiempo del frame anterior

    # Mostrar FPS en la imagen
    cv.putText(img, str(int(fps)), (10, 70), cv.FONT_HERSHEY_PLAIN, 3, (255, 0, 255), 3) 

    # Mostrar imagen
    cv.imshow("Image", img)
    if cv.waitKey(1) & 0xFF == ord('q'): #Sale del bucle si se presiona la tecla 'q'
        break

# Liberar recursos
cap.release()
cv.destroyAllWindows()
