function updateTime() {
    const nycTime = new Date().toLocaleString("en-US", { timeZone: "America/New_York" });
    const londonTime = new Date().toLocaleString("en-GB", { timeZone: "Europe/London" });
    const tokyoTime = new Date().toLocaleString("ja-JP", { timeZone: "Asia/Tokyo" });
  
    document.getElementById("time-nyc").textContent = new Date(nycTime).toLocaleTimeString();
    document.getElementById("time-london").textContent = new Date(londonTime).toLocaleTimeString();
    document.getElementById("time-tokyo").textContent = new Date(tokyoTime).toLocaleTimeString();
  }
  
  // Actualiza el reloj cada segundo
  setInterval(updateTime, 1000);
  
  // Llama a updateTime inmediatamente para que el reloj se muestre de inmediato
  updateTime();
  