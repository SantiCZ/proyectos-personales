// Simulacion de Datos en Tiempo Real
// Funcion para simular datos de temperatura en tiempo real generando valores aleatorios
const dataSimulator = (callback) => {
    setInterval(() => {
        const newData = {
            timestamp: new Date().toLocaleTimeString(), // Hora actual como cadena
            value: (Math.random() * 15 + 10).toFixed(1), // Temperatura aleatoria entre 10.0 y 25.0 grados Celsius
        };
        callback(newData); // Pasar los nuevos datos a la funcion de callback
    }, 1000); // Simular nuevos datos cada segundo
};

// Simulacion de WebSocket
// Funcion simulada para recibir datos via WebSocket
const mockWebSocket = (onDataReceived) => {
    dataSimulator(onDataReceived); // Usar el simulador de datos para generar datos
};

// Configuracion del Grafico con D3.js
// Funcion para configurar el grafico utilizando D3.js
const setupChart = () => {
    const width = 800; // Ancho del grafico
    const height = 400; // Altura del grafico
    const margin = { top: 20, right: 30, bottom: 30, left: 40 }; // Margenes del grafico

    const svg = d3
        .select("#chart")
        .append("svg")
        .attr("width", width)
        .attr("height", height); // Crear el elemento SVG

    const xScale = d3.scaleTime().range([margin.left, width - margin.right]); // Escala de tiempo para el eje x
    const yScale = d3.scaleLinear().range([height - margin.bottom, margin.top]); // Escala lineal para el eje y

    const xAxis = svg.append("g").attr("transform", `translate(0,${height - margin.bottom})`); // Grupo del eje x
    const yAxis = svg.append("g").attr("transform", `translate(${margin.left},0)`); // Grupo del eje y

    const line = d3
        .line()
        .x((d) => xScale(d.timestamp)) // Definir posicion x basada en la marca de tiempo
        .y((d) => yScale(d.value)); // Definir posicion y basada en el valor

    const path = svg.append("path").attr("class", "line").attr("fill", "none").attr("stroke", "steelblue"); // Elemento path para la linea del grafico

    return { svg, xScale, yScale, xAxis, yAxis, line, path }; // Retornar los componentes del grafico
};

// Actualizar el Grafico con Nuevos Datos
// Funcion para actualizar el grafico con nuevos puntos de datos
const updateChart = (chart, data) => {
    const { xScale, yScale, xAxis, yAxis, line, path } = chart;

    const now = new Date();
    data = data.map((d) => ({ timestamp: new Date(d.timestamp), value: parseFloat(d.value) })); // Convertir marcas de tiempo a objetos Date

    xScale.domain(d3.extent(data, (d) => d.timestamp)); // Actualizar dominio de la escala x
    yScale.domain([10, 25]); // Actualizar dominio de la escala y para temperatura

    xAxis.call(d3.axisBottom(xScale).tickFormat(d3.timeFormat("%H:%M:%S"))); // Actualizar eje x
    yAxis.call(d3.axisLeft(yScale)); // Actualizar eje y

    path.datum(data)
        .attr("d", line) // Actualizar la trayectoria de la linea
        .attr("stroke", "steelblue")
        .attr("stroke-width", 2); // Establecer ancho de la linea
};

// Logica Principal
// Funcion autoejecutable para inicializar y actualizar el grafico
(() => {
    const chart = setupChart(); // Configurar el grafico
    let data = []; // Inicializar un arreglo vacio para los puntos de datos

    mockWebSocket((newData) => {
        data.push(newData); // Agregar un nuevo punto de datos al arreglo
        if (data.length > 50) data.shift(); // Limitar los puntos de datos a los ultimos 50

        updateChart(chart, data); // Actualizar el grafico con los nuevos datos
    });
})();
