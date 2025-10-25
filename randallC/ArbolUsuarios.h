#ifndef ARBOL_USUARIOS_H
#define ARBOL_USUARIOS_H

#include "Usuario.h"
#include <iostream>
#include <functional>

class ArbolUsuarios {
private:
    Usuario* raiz;

    void insertar(Usuario*& nodo, Usuario* nuevo);
    Usuario* buscar(Usuario* nodo, int id);
    Usuario* eliminar(Usuario* nodo, int id);
    Usuario* encontrarMinimo(Usuario* nodo);
    void recorrerInOrden(Usuario* nodo, std::function<void(Usuario*)> f);
    void recorrerPreOrden(Usuario* nodo, std::function<void(Usuario*)> f);
    void recorrerPostOrden(Usuario* nodo, std::function<void(Usuario*)> f);

public:
    ArbolUsuarios();
    void insertarUsuario(int id, std::string nombre, int edad, float saldo);
    Usuario* buscarUsuario(int id);
    void eliminarUsuario(int id);
    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    void mostrarOrdenadosPorNombre();
    void guardarEnArchivo(const std::string& nombreArchivo);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
};

#endif