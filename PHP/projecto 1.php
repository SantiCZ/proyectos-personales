<?php
// Conexion a la base de datos 
$host = 'localhost'; // Nombre del host 
$user = 'root'; // Usuario de la base de datos 
$password = ''; // Contraseña del usuario
$database = 'sistema_encuestas'; // Nombre de la base de datos
$conn = new mysqli($host, $user, $password, $database); // Crear conexion

// Verificar si la conexion fue exitosa
if ($conn->connect_error) {
    die("Conexion fallida: " . $conn->connect_error); // Mostrar mensaje de error si falla
}

// Crear la tabla para encuestas si no existe
$conn->query("CREATE TABLE IF NOT EXISTS encuestas (
    id INT AUTO_INCREMENT PRIMARY KEY, // Identificador unico para cada encuesta
    titulo VARCHAR(255) NOT NULL // Titulo de la encuesta
)");

// Crear la tabla para opciones de las encuestas si no existe
$conn->query("CREATE TABLE IF NOT EXISTS opciones (
    id INT AUTO_INCREMENT PRIMARY KEY, // Identificador unico para cada opcion
    encuesta_id INT NOT NULL, // ID de la encuesta a la que pertenece la opcion
    texto VARCHAR(255) NOT NULL, // Texto de la opcion
    votos INT DEFAULT 0, // Contador de votos para la opcion
    FOREIGN KEY (encuesta_id) REFERENCES encuestas(id) // Relacion con la tabla encuestas
)");

// Manejar la creacion de encuestas
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['crear_encuesta'])) {
    $titulo = $conn->real_escape_string($_POST['titulo']); // Escapar el titulo para evitar inyeccion SQL
    $opciones = $_POST['opciones']; // Obtener las opciones enviadas

    // Insertar la nueva encuesta en la base de datos
    $conn->query("INSERT INTO encuestas (titulo) VALUES ('$titulo')");
    $encuesta_id = $conn->insert_id; // Obtener el ID de la encuesta recien creada

    // Insertar cada opcion en la base de datos
    foreach ($opciones as $opcion) {
        $opcion = $conn->real_escape_string($opcion); // Escapar el texto de la opcion
        $conn->query("INSERT INTO opciones (encuesta_id, texto) VALUES ($encuesta_id, '$opcion')");
    }

    echo "<p>Encuesta creada exitosamente!</p>"; // Mostrar mensaje de exito
}

// Manejar los votos de los usuarios
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['votar'])) {
    $opcion_id = (int) $_POST['opcion_id']; // Obtener el ID de la opcion seleccionada
    $conn->query("UPDATE opciones SET votos = votos + 1 WHERE id = $opcion_id"); // Incrementar el contador de votos
    echo "<p>Voto registrado!</p>"; // Mostrar mensaje de confirmacion
}

// Obtener todas las encuestas disponibles
$encuestas = $conn->query("SELECT * FROM encuestas");
?>

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Sistema de Encuestas</title>
</head>
<body>
    <h1>Sistema de Encuestas</h1>

    <!-- Formulario para crear una nueva encuesta -->
    <h2>Crear una nueva encuesta</h2>
    <form method="post">
        <label for="titulo">Titulo de la encuesta:</label><br>
        <input type="text" name="titulo" id="titulo" required><br><br> <!-- Campo para el titulo -->

        <label>Opciones:</label><br>
        <input type="text" name="opciones[]" placeholder="Opcion 1" required><br> <!-- Primera opcion -->
        <input type="text" name="opciones[]" placeholder="Opcion 2" required><br> <!-- Segunda opcion -->
        <button type="button" onclick="agregarOpcion()">Agregar otra opcion</button><br><br> <!-- Boton para agregar mas opciones -->

        <button type="submit" name="crear_encuesta">Crear Encuesta</button> <!-- Boton para enviar el formulario -->
    </form>

    <script>
        // Funcion para agregar un campo de opcion adicional
        function agregarOpcion() {
            const nuevaOpcion = document.createElement('input'); // Crear un nuevo campo de entrada
            nuevaOpcion.type = 'text'; // Tipo de entrada
            nuevaOpcion.name = 'opciones[]'; // Nombre del campo
            nuevaOpcion.placeholder = 'Nueva opcion'; // Texto de ejemplo
            document.querySelector('form').insertBefore(nuevaOpcion, document.querySelector('form button')); // Insertar antes del boton
            document.querySelector('form').insertBefore(document.createElement('br'), document.querySelector('form button')); // Agregar un salto de linea
        }
    </script>

    <!-- Listar las encuestas disponibles -->
    <h2>Encuestas disponibles</h2>
    <?php while ($encuesta = $encuestas->fetch_assoc()) { ?>
        <div>
            <h3><?php echo htmlspecialchars($encuesta['titulo']); ?></h3> <!-- Mostrar el titulo de la encuesta -->
            <form method="post">
                <?php
                // Obtener las opciones de la encuesta actual
                $opciones = $conn->query("SELECT * FROM opciones WHERE encuesta_id = " . $encuesta['id']);
                while ($opcion = $opciones->fetch_assoc()) {
                    // Mostrar cada opcion con un radio button
                    echo "<label><input type='radio' name='opcion_id' value='" . $opcion['id'] . "'> " . htmlspecialchars($opcion['texto']) . "</label><br>";
                }
                ?>
                <button type="submit" name="votar">Votar</button> <!-- Boton para votar -->
            </form>

            <!-- Mostrar los resultados de la encuesta -->
            <h4>Resultados:</h4>
            <ul>
                <?php
                $opciones->data_seek(0); // Reiniciar el cursor de resultados
                while ($opcion = $opciones->fetch_assoc()) {
                    // Mostrar los votos de cada opcion
                    echo "<li>" . htmlspecialchars($opcion['texto']) . ": " . $opcion['votos'] . " votos</li>";
                }
                ?>
            </ul>
        </div>
    <?php } ?>
</body>
</html>
