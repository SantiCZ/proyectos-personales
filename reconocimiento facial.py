import face_recognition
import cv2

# Carga la imagen de referencia con el rostro que quieres reconocer
known_image = face_recognition.load_image_file("known_face.jpg")
known_face_encodings = face_recognition.face_encodings(known_image)

# Asegurate de que se encontro al menos un rostro en la imagen conocida
if len(known_face_encodings) > 0:
    known_face_encoding = known_face_encodings[0]
else:
    raise ValueError("No se encontro ningun rostro en la imagen conocida.")

# Inicializa el video (0 usa la camara predeterminada)
video_capture = cv2.VideoCapture(0)

# Verifica si la camara se abrio correctamente
if not video_capture.isOpened():
    raise Exception("No se puede abrir la camara")

# Lista de rostros conocidos y nombres
known_face_encodings = [known_face_encoding]
known_face_names = ["Nombre de la Persona"]

while True:
    # Captura un frame del video
    ret, frame = video_capture.read()

    # Verifica si la captura del frame fue exitosa
    if not ret:
        print("Error al capturar el frame del video")
        break

    # Convierte la imagen del frame a RGB
    rgb_frame = frame[:, :, ::-1]

    # Encuentra todas las caras en el frame y codificalas
    face_locations = face_recognition.face_locations(rgb_frame)
    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

    for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
        # Compara la cara encontrada con las caras conocidas
        matches = face_recognition.compare_faces(known_face_encodings, face_encoding)

        name = "Desconocido"

        # Si hay una coincidencia, usa el primer rostro conocido coincidente
        if True in matches:
            first_match_index = matches.index(True)
            name = known_face_names[first_match_index]

        # Dibuja un rectangulo alrededor de la cara y el nombre
        cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 2)
        cv2.putText(frame, name, (left, top - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)

    # Muestra el video en una ventana
    cv2.imshow("Video", frame)

    # Termina el programa al presionar la tecla 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libera la camara y cierra las ventanas
video_capture.release()
cv2.destroyAllWindows()
