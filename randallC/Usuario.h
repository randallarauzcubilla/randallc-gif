#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
public:
    int id;
    std::string nombre;
    int edad;
    float saldo;

    Usuario* izq;
    Usuario* der;

    // Constructor
    Usuario(int _id, std::string _nombre, int _edad, float _saldo);

    // Métodos auxiliares
    void mostrarDatos();
};

#endif