// Generador de contrasenas aleatorias
function generarContrasena(longitud, opciones) {
    // Conjunto de caracteres disponibles para la contrasena
    const caracteres = {
        minusculas: 'abcdefghijklmnopqrstuvwxyz', // Letras minusculas
        mayusculas: 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', // Letras mayusculas
        numeros: '0123456789', // Numeros
        simbolos: '!@#$%^&*()_+[]{}|;:,.<>?/~`', // Simbolos especiales
    };

    // Crear un conjunto de caracteres basado en las opciones seleccionadas
    let conjuntoCaracteres = '';
    if (opciones.incluirMinusculas) conjuntoCaracteres += caracteres.minusculas;
    if (opciones.incluirMayusculas) conjuntoCaracteres += caracteres.mayusculas;
    if (opciones.incluirNumeros) conjuntoCaracteres += caracteres.numeros;
    if (opciones.incluirSimbolos) conjuntoCaracteres += caracteres.simbolos;

    // Verificar que al menos una opcion este seleccionada
    if (!conjuntoCaracteres) {
        throw new Error('Debe seleccionar al menos una opcion de tipo de caracter.');
    }

    // Generar la contrasena inicial
    let contrasena = '';
    for (let i = 0; i < longitud; i++) {
        // Seleccionar un caracter aleatorio del conjunto
        const indiceAleatorio = Math.floor(Math.random() * conjuntoCaracteres.length);
        contrasena += conjuntoCaracteres[indiceAleatorio];
    }

    // Mezclar los caracteres de la contrasena para mayor aleatoriedad
    return mezclarCaracteres(contrasena);
}

// Funcion para mezclar caracteres de una cadena de manera aleatoria
function mezclarCaracteres(cadena) {
    const caracteres = cadena.split(''); // Convertir la cadena en un array
    for (let i = caracteres.length - 1; i > 0; i--) {
        // Generar un indice aleatorio
        const j = Math.floor(Math.random() * (i + 1));
        // Intercambiar los elementos en las posiciones i y j
        [caracteres[i], caracteres[j]] = [caracteres[j], caracteres[i]];
    }
    return caracteres.join(''); // Volver a convertir el array en una cadena
}

// Ejemplo de uso
const opciones = {
    incluirMinusculas: true, // Incluir letras minusculas
    incluirMayusculas: true, // Incluir letras mayusculas
    incluirNumeros: true, // Incluir numeros
    incluirSimbolos: true, // Incluir simbolos especiales
};

const longitud = 12; // Longitud deseada para la contrasena
const contrasenaGenerada = generarContrasena(longitud, opciones);
console.log('Contrasena generada:', contrasenaGenerada); // Mostrar la contrasena generada

// Funcion para copiar el contenido del campo de texto al portapapeles
function copyToClipboard() {
    // Obtener el valor del input con la contraseña
    const passwordInput = document.getElementById('password');
    const password = passwordInput.value;

    // Usar la API Clipboard para copiar el texto al portapapeles
    navigator.clipboard.writeText(password)
        .then(() => {
            // Mostrar un mensaje de exito
            const message = document.getElementById('message');
            message.textContent = '¡Contraseña copiada al portapapeles!';
            message.style.color = '#28a745'; // Verde
        })
        .catch(err => {
            // Mostrar un mensaje de error si algo falla
            const message = document.getElementById('message');
            message.textContent = 'Error al copiar la contraseña.';
            message.style.color = 'red';
            console.error('Error al copiar:', err);
        });
}
