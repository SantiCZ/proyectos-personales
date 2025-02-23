function updateTime() {
    const nycTime = new Date().toLocaleString("en-US", { timeZone: "America/New_York" });//hora en nueva york
    const londonTime = new Date().toLocaleString("en-GB", { timeZone: "Europe/London" });//hora en londres
    const tokyoTime = new Date().toLocaleString("ja-JP", { timeZone: "Asia/Tokyo" });//hora en tokyo
  //se puede poner cualquier ciudad que se quiera, pero se necesita modificar el HTML  y el CSS tambien
    document.getElementById("time-nyc").textContent = new Date(nycTime).toLocaleTimeString();
    document.getElementById("time-london").textContent = new Date(londonTime).toLocaleTimeString();
    document.getElementById("time-tokyo").textContent = new Date(tokyoTime).toLocaleTimeString();
  }
  
  // Actualiza el reloj cada segundo
  setInterval(updateTime, 1000);
  
  // Llama a updateTime inmediatamente para que el reloj se muestre de inmediato
  updateTime();
  
