document.getElementById("convert").addEventListener("click", function() {
    const fromCurrency = document.getElementById("fromCurrency").value;
    const toCurrency = document.getElementById("toCurrency").value;
    const amount = parseFloat(document.getElementById("amount").value);
    const resultElement = document.getElementById("result");

    if (isNaN(amount) || amount <= 0) {
        resultElement.textContent = "Por favor, ingresa una cantidad valida.";
        return;
    }

    // Tu clave API de ExchangeRate-API (reemplazala con tu propia clave)
    const apiKey = "bfbd438ffbbb1ce4e8cab9dc";
    const url = `https://v6.exchangerate-api.com/v6/${apiKey}/latest/${fromCurrency}`;

    // Realizar la solicitud para obtener las tasas de cambio
    fetch(url)
        .then(response => response.json())
        .then(data => {
            // Verificar si la API respondio correctamente
            if (data.result === "success") {
                const rate = data.conversion_rates[toCurrency];

                if (rate) {
                    const convertedAmount = amount * rate;
                    resultElement.textContent = `${amount} ${fromCurrency} es igual a ${convertedAmount.toFixed(2)} ${toCurrency}`;
                } else {
                    resultElement.textContent = `Tasa de cambio no disponible para ${toCurrency}.`;
                }
            } else {
                resultElement.textContent = "Error al obtener las tasas de cambio.";
            }
        })
        .catch(error => {
            resultElement.textContent = "Hubo un error al intentar obtener los datos. Intenta nuevamente más tarde.";
            console.error("Error:", error);
        });
});
