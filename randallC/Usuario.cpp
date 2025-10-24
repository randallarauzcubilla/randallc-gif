#include "pch.h"
#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int _id, std::string _nombre, int _edad, float _saldo) {
    id = _id;
    nombre = _nombre;
    edad = _edad;
    saldo = _saldo;
    izq = nullptr;
    der = nullptr;
}

// Método auxiliar: muestra los datos del usuario en consola
void Usuario::mostrarDatos() {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Edad: " << edad << " anios\n";
    std::cout << "Saldo: " << saldo << " colones.\n";
}