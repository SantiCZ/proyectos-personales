-- Crear la base de datos
CREATE DATABASE tienda;

-- Usar la base de datos recien creada
USE tienda;

-- Crear la tabla productos
CREATE TABLE productos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    descripcion TEXT,
    precio DECIMAL(10, 2) NOT NULL,
    stock INT NOT NULL
);

-- Insertar algunos registros en la tabla productos
INSERT INTO productos (nombre, descripcion, precio, stock) VALUES
('Producto 1', 'Descripcion del Producto 1', 10.99, 100),
('Producto 2', 'Descripcion del Producto 2', 19.99, 200),
('Producto 3', 'Descripcion del Producto 3', 5.49, 150);

-- Consultar los registros de la tabla productos
SELECT * FROM productos;

