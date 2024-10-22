create database Acceso;

use Acceso;

-- Creación de la tabla tipoUsuario
CREATE TABLE tipoUsuario (
    id INT AUTO_INCREMENT PRIMARY KEY,
    descripcion VARCHAR(50) NOT NULL
);

-- Creación de la tabla usuario
CREATE TABLE usuario (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    codigo_rfid VARCHAR(50) NOT NULL UNIQUE,
    tipoUsuario INT,
    FOREIGN KEY (tipoUsuario) REFERENCES tipoUsuario(id) ON DELETE CASCADE
);

-- Creación de la tabla reserva (para visitas)
CREATE TABLE reserva (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    fecha_reserva DATE NOT NULL,
    hora_entrada TIME NOT NULL,
    hora_salida TIME NOT NULL,
    FOREIGN KEY (usuario_id) REFERENCES usuario(id) ON DELETE CASCADE
);

-- Creación de la tabla horarios (para empleados)
CREATE TABLE horarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    hora_inicio TIME NOT NULL,
    hora_fin TIME NOT NULL,
    FOREIGN KEY (usuario_id) REFERENCES usuario(id) ON DELETE CASCADE
);

-- Creación de la tabla registroacceso
CREATE TABLE registroacceso (
    id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT,
    hora_entrada DATETIME NOT NULL,
    hora_salida DATETIME NULL,
    estado ENUM('Permitido', 'Denegado') NOT NULL,
    nivel_bateria DECIMAL(5, 2) NOT NULL,
    FOREIGN KEY (usuario_id) REFERENCES usuario(id) ON DELETE CASCADE
);

-- Insertar tipos de usuario
INSERT INTO tipoUsuario (descripcion) VALUES ('Propietario'), ('Empleado'), ('Visitante');

-- Insertar usuarios
INSERT INTO usuario (nombre, codigo_rfid, tipoUsuario) 
VALUES 
('Juan Pérez', 'RFID001', 1),  -- Propietario
('Maria López', 'RFID002', 2),  -- Empleado
('Carlos Sánchez', 'RFID003', 3);  -- Visitante

-- Insertar horarios permitidos para empleados
INSERT INTO horarios (usuario_id, hora_inicio, hora_fin) 
VALUES (2, '08:00:00', '17:00:00');  -- Maria López, que es una empleada

-- Insertar una reserva para un visitante
INSERT INTO reserva (usuario_id, fecha_reserva, hora_entrada, hora_salida) 
VALUES (3, '2024-10-06', '14:00:00', '18:00:00');  -- Carlos Sánchez, que es un visitante


SELECT * FROM registroacceso;
