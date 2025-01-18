const apiKey = 'TU_API_KEY'; // Reemplaza con tu clave de API
// Selecciona los elementos del DOM
const searchBar = document.querySelector('.search-bar');// Selecciona la barra de busqueda
const searchButton = document.querySelector('button');// Selecciona el boton de busqueda
const weatherContainer = document.querySelector('.weather-container');// Selecciona el contenedor de clima

searchButton.addEventListener('click', () => {
    const city = searchBar.value;
    if (city) {
        fetchWeather(city);
        searchBar.value = '';
    }
});
// Funcion para obtener el clima de una ciudad
async function fetchWeather(city) {
    try {
        const response = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric&lang=es`);
        const data = await response.json();
        if (data.cod === '404') {
            alert('Ciudad no encontrada');
            return;
        }
        updateWeather(data);
    } catch (error) {
        console.error('Error fetching weather data:', error);
    }
}
// Funcion para actualizar la informacion del clima en la interfaz
function updateWeather(data) {
    const { main, name, weather } = data;
    const { temp } = main;
    const { description, icon } = weather[0];

    const weatherCard = document.createElement('div');
    weatherCard.classList.add('weather-card');

    weatherCard.innerHTML = `
        <img src="http://openweathermap.org/img/wn/${icon}.png" alt="Icono de clima" class="icono-de-clima">
        <h1 class="temp">${Math.round(temp)}°C</h1>
        <h1 class="ciudad">${name}</h1>
        <h3 class="descripcion">${description.charAt(0).toUpperCase() + description.slice(1)}</h3>
    `;

    weatherContainer.appendChild(weatherCard);// Agrega el elemento al contenedor de clima
}