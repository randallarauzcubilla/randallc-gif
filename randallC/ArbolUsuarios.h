#ifndef ARBOL_USUARIOS_H
#define ARBOL_USUARIOS_H

#include "Usuario.h"
#include <iostream>
#include <functional>
#include <string>
#include <map>

class ArbolUsuarios {
private:
    Usuario* raiz;

    bool insertar(Usuario*& nodo, Usuario* nuevo);
    Usuario* buscar(Usuario* nodo, int id);
    Usuario* eliminar(Usuario* nodo, int id);
    Usuario* encontrarMinimo(Usuario* nodo);

    void recorrerInOrden(Usuario* nodo, std::function<void(Usuario*)> f) const;
    void recorrerPreOrden(Usuario* nodo, std::function<void(Usuario*)> f) const;
    void recorrerPostOrden(Usuario* nodo, std::function<void(Usuario*)> f) const;

public:
    ArbolUsuarios();
    bool insertarUsuario(int id, std::string nombre, int edad, float saldo);
    Usuario* buscarUsuario(int id);
    Usuario* getRaiz() const { return raiz; }
    void eliminarUsuario(int id);

    void mostrarInOrden();
    void mostrarPreOrden();
    void mostrarPostOrden();
    void mostrarOrdenadosPorNombre();

    void guardarEnArchivo(const std::string& nombreArchivo);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void exportarOrdenadosPorNombre(std::ostream& out);

    std::string obtenerRecorridoInOrden() const;
    std::string obtenerRecorridoPreOrden() const;
    std::string obtenerRecorridoPostOrden() const;
    std::string obtenerUsuariosOrdenadosPorNombre() const;
};

#endif