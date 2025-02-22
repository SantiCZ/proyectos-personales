const express = require('express'); // Importa Express
const axios = require('axios'); // Importa Axios
const app = express(); // Crea una instancia de Express
const PORT = 3000; // Define el puerto en el que correra el servidor
// Endpoint para obtener precios de criptomonedas
app.get('/api/crypto-prices', async (req, res) => {
  try {
    // Hace una solicitud a la API de CoinGecko para obtener los precios
    const response = await axios.get('https://api.coingecko.com/api/v3/simple/price', {
      params: {
        ids: 'bitcoin,ethereum,litecoin', // IDs de las criptomonedas
        vs_currencies: 'usd' // Moneda en la que se quieren los precios
      }
    });
    res.json(response.data); // Devuelve los datos en formato JSON
  } catch (error) {
    console.error('Error fetching crypto prices:', error); // Muestra un error en la consola
    res.status(500).send('Error fetching crypto prices'); // Devuelve un error al cliente
  }
});

// Inicia el servidor
app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`); // Muestra un mensaje cuando el servidor esta corriendo
});
