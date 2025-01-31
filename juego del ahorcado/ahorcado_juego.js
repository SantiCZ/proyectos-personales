const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Palabras disponibles
const palabras = ['javascript', 'programacion', 'computadora', 'desarrollo', 'web'];
let palabraSecreta = '';
let letrasAdivinadas = [];
let intentosRestantes = 6;

// Inicializar juego
function iniciarJuego() {
    palabraSecreta = palabras[Math.floor(Math.random() * palabras.length)];
    letrasAdivinadas = Array(palabraSecreta.length).fill('_');
    intentosRestantes = 6;
    console.log('\n¡Bienvenido al Ahorcado!\n');
    turnoJuego();
}

// Mostrar estado actual
function mostrarEstado() {
    console.log('\nPalabra:', letrasAdivinadas.join(' '));
    console.log('Intentos restantes:', intentosRestantes);
}

// Proceso del juego
function turnoJuego() {
    mostrarEstado();
    
    rl.question('Ingresa una letra o palabra: ', (respuesta) => {
        if(respuesta.length === 1) {
            // Adivinar letra
            if(palabraSecreta.includes(respuesta)) {
                for(let i = 0; i < palabraSecreta.length; i++) {
                    if(palabraSecreta[i] === respuesta) {
                        letrasAdivinadas[i] = respuesta;
                    }
                }
            } else {
                intentosRestantes--;
                console.log('\n¡Letra incorrecta!');
            }
        } else if(respuesta === palabraSecreta) {
            letrasAdivinadas = palabraSecreta.split('');
        } else {
            intentosRestantes--;
            console.log('\n¡Palabra incorrecta!');
        }

        // Verificar estado del juego
        if(letrasAdivinadas.join('') === palabraSecreta) {
            console.log('\n¡Felicitaciones! ¡Ganaste!');
            console.log('La palabra era:', palabraSecreta);
            rl.close();
        } else if(intentosRestantes === 0) {
            console.log('\n¡Perdiste! La palabra era:', palabraSecreta);
            rl.close();
        } else {
            turnoJuego();
        }
    });
}

// Iniciar juego
iniciarJuego();