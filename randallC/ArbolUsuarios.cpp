#include "pch.h"
#include "ArbolUsuarios.h"
#include <map>
#include <fstream>
#include <sstream>

ArbolUsuarios::ArbolUsuarios() : raiz(nullptr) {}

void ArbolUsuarios::insertar(Usuario*& nodo, Usuario* nuevo) {
    if (!nodo) {
        nodo = nuevo;
    }
    else if (nuevo->id < nodo->id) {
        insertar(nodo->izq, nuevo);
    }
    else {
        insertar(nodo->der, nuevo);
    }
}

void ArbolUsuarios::insertarUsuario(int id, std::string nombre, int edad, float saldo) {
    bool idValido = id > 0;
    bool edadValida = edad >= 0 && edad <= 120;
    bool saldoValido = saldo >= 0;

    if (!idValido) {
        std::cout << "ID invalido: debe ser un numero positivo.\n";
        return;
    }

    if (!edadValida) {
        std::cout << "Edad invalida: debe ser un numero positivo mayor a 0.\n";
        return;
    }

    if (!saldoValido) {
        std::cout << "Saldo invalido: no puede ser negativo.\n";
        return;
    }

    Usuario* nuevo = new Usuario(id, nombre, edad, saldo);
    insertar(raiz, nuevo);
}

Usuario* ArbolUsuarios::buscar(Usuario* nodo, int id) {
    if (!nodo || nodo->id == id) return nodo;
    return (id < nodo->id) ? buscar(nodo->izq, id) : buscar(nodo->der, id);
}

Usuario* ArbolUsuarios::buscarUsuario(int id) {
    return buscar(raiz, id);
}

Usuario* ArbolUsuarios::encontrarMinimo(Usuario* nodo) {
    while (nodo && nodo->izq) nodo = nodo->izq;
    return nodo;
}

Usuario* ArbolUsuarios::eliminar(Usuario* nodo, int id) {
    if (!nodo) return nullptr;
    if (id < nodo->id) {
        nodo->izq = eliminar(nodo->izq, id);
    }
    else if (id > nodo->id) {
        nodo->der = eliminar(nodo->der, id);
    }
    else {
        if (!nodo->izq) {
            Usuario* temp = nodo->der;
            delete nodo;
            return temp;
        }
        else if (!nodo->der) {
            Usuario* temp = nodo->izq;
            delete nodo;
            return temp;
        }
        else {
            Usuario* temp = encontrarMinimo(nodo->der);
            nodo->id = temp->id;
            nodo->nombre = temp->nombre;
            nodo->edad = temp->edad;
            nodo->saldo = temp->saldo;
            nodo->der = eliminar(nodo->der, temp->id);
        }
    }
    return nodo;
}

void ArbolUsuarios::eliminarUsuario(int id) {
    raiz = eliminar(raiz, id);
}

void ArbolUsuarios::recorrerInOrden(Usuario* nodo, std::function<void(Usuario*)> f) {
    if (nodo) {
        recorrerInOrden(nodo->izq, f);
        f(nodo);
        recorrerInOrden(nodo->der, f);
    }
}

void ArbolUsuarios::recorrerPreOrden(Usuario* nodo, std::function<void(Usuario*)> f) {
    if (nodo) {
        f(nodo);
        recorrerPreOrden(nodo->izq, f);
        recorrerPreOrden(nodo->der, f);
    }
}

void ArbolUsuarios::recorrerPostOrden(Usuario* nodo, std::function<void(Usuario*)> f) {
    if (nodo) {
        recorrerPostOrden(nodo->izq, f);
        recorrerPostOrden(nodo->der, f);
        f(nodo);
    }
}

void ArbolUsuarios::mostrarInOrden() {
    if (!raiz) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }
    recorrerInOrden(raiz, [](Usuario* u) {
        std::cout << u->id << " - " << u->nombre << " - " << u->edad << " anios " << u->saldo << " colones.\n";
        });
}

void ArbolUsuarios::mostrarPreOrden() {
    if (!raiz) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }
    recorrerPreOrden(raiz, [](Usuario* u) {
        std::cout << u->id << " - " << u->nombre << "\n";
        });
}

void ArbolUsuarios::mostrarPostOrden() {
    if (!raiz) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }
    recorrerPostOrden(raiz, [](Usuario* u) {
        std::cout << u->id << " - " << u->nombre << "\n";
        });
}

void ArbolUsuarios::mostrarOrdenadosPorNombre() {
    if (!raiz) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    std::map<std::string, Usuario*> mapa;
    recorrerInOrden(raiz, [&](Usuario* u) {
        mapa[u->nombre] = u;
        });

    std::cout << "\nUsuarios ordenados por nombre:\n";
    for (auto& par : mapa) {
        Usuario* u = par.second;
        std::cout << u->id << " - " << u->nombre << " - " << u->edad << " anios - saldo: " << u->saldo << " colones.\n";
    }
}

void ArbolUsuarios::guardarEnArchivo(const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo para guardar.\n";
        return;
    }

    recorrerInOrden(raiz, [&](Usuario* u) {
        archivo << u->id << "," << u->nombre << "," << u->edad << "," << u->saldo << "\n";
        });

    archivo.close();
}

void ArbolUsuarios::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo de usuarios.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string idStr, nombre, edadStr, saldoStr;
        int id, edad;
        float saldo;

        std::getline(ss, idStr, ',');
        std::getline(ss, nombre, ',');
        std::getline(ss, edadStr, ',');
        std::getline(ss, saldoStr);

        try {
            id = std::stoi(idStr);
            edad = std::stoi(edadStr);
            saldo = std::stof(saldoStr);
            insertarUsuario(id, nombre, edad, saldo);
        }
        catch (...) {
            std::cout << "Error al leer usuario: " << linea << "\n";
        }
    }

    archivo.close();
}

void ArbolUsuarios::exportarOrdenadosPorNombre(std::ostream& out) {
    if (!raiz) {
        out << "No hay usuarios registrados.\n";
        return;
    }

    std::map<std::string, Usuario*> mapa;
    recorrerInOrden(raiz, [&](Usuario* u) {
        mapa[u->nombre] = u;
        });

    out << "Usuarios ordenados por nombre:\n";
    for (auto& par : mapa) {
        Usuario* u = par.second;
        out << u->id << " - " << u->nombre << " - " << u->edad
            << " anios - saldo: " << u->saldo << " colones.\n";
    }
}

