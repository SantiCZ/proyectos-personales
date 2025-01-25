const simulator = document.getElementById('simulator');

const particleCount = 100;
const particles = [];

// Crear partículas
for (let i = 0; i < particleCount; i++) {
  const particle = document.createElement('div');
  particle.classList.add('particle');
  simulator.appendChild(particle);

  // Configuración inicial de cada partícula
  particles.push({
    element: particle,
    x: Math.random() * window.innerWidth,
    y: Math.random() * window.innerHeight,
    vx: (Math.random() - 0.5) * 2,
    vy: (Math.random() - 0.5) * 2
  });
}

// Actualizar posicion de partículas
function updateParticles() {
  particles.forEach(p => {
    p.x += p.vx;
    p.y += p.vy;

    // Rebotar en los bordes
    if (p.x < 0 || p.x > window.innerWidth) p.vx *= -1;
    if (p.y < 0 || p.y > window.innerHeight) p.vy *= -1;

    // Aplicar posiciones
    p.element.style.transform = `translate(${p.x}px, ${p.y}px)`;
  });

  requestAnimationFrame(updateParticles);
}

updateParticles();
