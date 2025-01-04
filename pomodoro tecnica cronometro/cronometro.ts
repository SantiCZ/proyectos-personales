class PomodoroTimer {
    private duration: number;
    private remainingTime: number;
    private timerId: NodeJS.Timeout | null = null;
    private isRunning: boolean = false;
  
    constructor(duration: number) {
      this.duration = duration;
      this.remainingTime = duration;
    }
  
    // Metodo para mostrar una notificacion cuando el temporizador termina
    private notify(): void {
      if ("Notification" in window && Notification.permission === "granted") {
        new Notification("Pomodoro terminado!", { body: "Tiempo de descanso." });
      }
    }
  
    // Metodo para actualizar la visualizacion del tiempo restante
    private updateDisplay(): void {
      console.log(`Tiempo restante: ${this.remainingTime}s`);
    }
  
    // Metodo para iniciar el temporizador
    start(): void {
      if (this.isRunning) return;
      this.isRunning = true;
  
      this.timerId = setInterval(() => {
        if (this.remainingTime > 0) {
          this.remainingTime--;
          this.updateDisplay();
        } else {
          this.stop();
          this.notify();
        }
      }, 1000);
    }
  
    // Metodo para pausar el temporizador
    pause(): void {
      if (this.timerId) {
        clearInterval(this.timerId);
        this.timerId = null;
        this.isRunning = false;
      }
    }
  
    // Metodo para detener el temporizador
    stop(): void {
      this.pause();
      this.remainingTime = 0;
      this.updateDisplay();
    }

    // Metodo para reiniciar el temporizador
    reset(): void {
      this.pause();
      this.remainingTime = this.duration;
      this.updateDisplay();
    }
  }
  
  // Solicitar permisos de notificacion al usuario
  if ("Notification" in window) {
    Notification.requestPermission();
  }
  
  // Uso del temporizador con una duracion de 25 minutos
  const pomodoro = new PomodoroTimer(25 * 60);
  pomodoro.start();
  