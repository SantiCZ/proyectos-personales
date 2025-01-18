// Funcion para convertir una fecha gregoriana a dias julianos
function gregorianoAJuliano(fecha) {
    // Obtiene el anio, mes y dia de la fecha proporcionada
    const año = fecha.getFullYear();
    const mes = fecha.getMonth() + 1; // Los meses en JavaScript van de 0 (enero) a 11 (diciembre)
    const dia = fecha.getDate();

    // Realiza el calculo para convertir a dias julianos
    const A = Math.floor((14 - mes) / 12);
    const Y = año + 4800 - A;
    const M = mes + 12 * A - 3;

    const diasJulianos =
        dia + Math.floor((153 * M + 2) / 5) + 365 * Y + Math.floor(Y / 4) 
        - Math.floor(Y / 100) + Math.floor(Y / 400) - 32045;

    return diasJulianos;
}

// Funcion para convertir dias julianos a una fecha gregoriana
function julianoAGregoriano(diasJulianos) {
    // Ajusta el valor inicial de dias julianos
    const J = diasJulianos + 32044;
    const g = Math.floor(J / 146097);
    const dg = J % 146097;
    const c = Math.floor((dg / 36524 + 1) * 3 / 4);
    const dc = dg - c * 36524;
    const b = Math.floor(dc / 1461);
    const db = dc % 1461;
    const a = Math.floor((db / 365 + 1) * 3 / 4);
    const da = db - a * 365;

    // Calcula el año, mes y dia de la fecha gregoriana
    const y = g * 400 + c * 100 + b * 4 + a;
    const m = Math.floor((5 * da + 308) / 153) - 2;
    const d = da - Math.floor((153 * m + 2) / 5) + 1;

    const año = y - 4800 + Math.floor((m + 2) / 12);
    const mes = (m + 2) % 12 + 1;

    // Devuelve la fecha como un objeto Date
    return new Date(año, mes - 1, d);
}

// Ejemplo de uso
const fechaGregoriana = new Date(2025, 0, 18); // Enero es el mes 0
const diasJulianos = gregorianoAJuliano(fechaGregoriana);
console.log(`Dias julianos: ${diasJulianos}`);

const fechaConvertida = julianoAGregoriano(diasJulianos);
console.log(`Fecha gregoriana convertida: ${fechaConvertida.toDateString()}`);
