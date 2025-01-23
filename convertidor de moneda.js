// Configura tu API key obtenida de exchangerate-api.com
const API_KEY = 'bfbd438ffbbb1ce4e8cab9dc'; // Clave de la API para acceder a los datos
const API_URL = `https://v6.exchangerate-api.com/v6/${API_KEY}/latest/`; // URL base de la API con la clave
// Referencias a los elementos del DOM
const fromCurrency = document.getElementById('fromCurrency'); // Selector de la moneda de origen
const toCurrency = document.getElementById('toCurrency'); // Selector de la moneda de destino
const amountInput = document.getElementById('amount'); // Campo de entrada para la cantidad
const convertButton = document.getElementById('convert'); // Boton para iniciar la conversion
const resultDisplay = document.getElementById('result'); // Elemento para mostrar el resultado
// Funcion para llenar los selectores con las monedas disponibles
async function loadCurrencies() {
    try {
        const response = await fetch(`${API_URL}USD`); // Realiza una peticion para obtener datos usando USD como base
        const data = await response.json(); // Convierte la respuesta a formato JSON
        if (data && data.conversion_rates) { // Verifica si los datos contienen tasas de conversion
            const currencies = Object.keys(data.conversion_rates); // Obtiene las claves de las monedas disponibles
            currencies.forEach(currency => {
                fromCurrency.innerHTML += `<option value="${currency}">${currency}</option>`; // Agrega cada moneda al selector de origen
                toCurrency.innerHTML += `<option value="${currency}">${currency}</option>`; // Agrega cada moneda al selector de destino
            });
        }
    } catch (error) {
        console.error('Error al cargar las monedas:', error); // Muestra un error en caso de fallo
    }
}
// Funcion para convertir la moneda
async function convertCurrency() {
    const from = fromCurrency.value; // Obtiene la moneda de origen seleccionada
    const to = toCurrency.value; // Obtiene la moneda de destino seleccionada
    const amount = parseFloat(amountInput.value); // Convierte la cantidad ingresada a un numero
    if (isNaN(amount) || amount <= 0) { // Verifica si la cantidad ingresada es valida
        resultDisplay.textContent = 'Por favor, ingresa una cantidad valida.'; // Muestra un mensaje de error
        return; // Sale de la funcion
    }
    try {
        const response = await fetch(`${API_URL}${from}`); // Realiza una peticion para obtener la tasa de cambio de la moneda de origen
        const data = await response.json(); // Convierte la respuesta a formato JSON

        if (data && data.conversion_rates) { // Verifica si los datos contienen tasas de conversion
            const rate = data.conversion_rates[to]; // Obtiene la tasa de cambio de la moneda de destino
            const convertedAmount = (amount * rate).toFixed(2); // Calcula el monto convertido y lo redondea a 2 decimales
            resultDisplay.textContent = `${amount} ${from} = ${convertedAmount} ${to}`; // Muestra el resultado de la conversion
        } else {
            resultDisplay.textContent = 'No se pudo obtener la tasa de cambio.'; // Muestra un mensaje de error si no se encuentran tasas
        }
    } catch (error) {
        console.error('Error al convertir la moneda:', error); // Muestra un error en caso de fallo
        resultDisplay.textContent = 'Ocurrio un error al realizar la conversion.'; // Muestra un mensaje de error generico
    }
}
// Eventos
convertButton.addEventListener('click', convertCurrency); // Agrega un evento click al boton para iniciar la conversion
// Cargar monedas al iniciar
loadCurrencies(); // Llama a la funcion para cargar las monedas disponibles
