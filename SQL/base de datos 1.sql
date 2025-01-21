-- Crear la base de datos llamada 'Inventario' 
CREATE DATABASE Inventario;

-- Seleccionar la base de datos para usarla
USE Inventario;

-- Crear la tabla 'Productos' con columnas para id, nombre, descripcion, precio, cantidad y fecha de registro
CREATE TABLE Productos (
    id INT NOT NULL IDENTITY PRIMARY KEY, -- Identificador unico para cada producto
    nombre VARCHAR(100) NOT NULL,         -- Nombre del producto
    descripcion TEXT,                           -- Descripcion del producto
    precio DECIMAL(10,2) NOT NULL,              -- Precio del producto
    cantidad INT NOT NULL,                      -- Cantidad disponible en el inventario
    fecha_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP -- Fecha y hora de registro del producto
);

-- Insertar nuevos productos en la tabla 'Productos'
INSERT INTO Productos (nombre, descripcion, precio, cantidad) VALUES
('Producto 1', 'Descripcion del producto 1', 10.99, 100),
('Producto 2', 'Descripcion del producto 2', 15.50, 200),
('Producto 3', 'Descripcion del producto 3', 7.25, 150);

-- Actualizar la cantidad del producto con id 1
UPDATE Productos
SET cantidad = 120
WHERE id = 1;

-- Actualizar el precio del producto con id 2
UPDATE Productos
SET precio = 12.99
WHERE id = 2;

-- Consultar todos los productos en la tabla 'Productos'
SELECT * FROM Productos;

-- Consultar productos con cantidad mayor a 100
SELECT * FROM Productos
WHERE cantidad > 100;

-- Consultar un producto por su nombre
SELECT * FROM Productos
WHERE nombre = 'Producto 1';

-- Eliminar el producto con id 3
DELETE FROM Productos
WHERE id = 3;
