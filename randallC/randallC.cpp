#include "pch.h"

using namespace System;
#include "ArbolUsuarios.h"
#include <iostream>

int main() {
    ArbolUsuarios arbol;
    int opcion;

    do {
        std::cout << "\n--- MENU DE USUARIOS ---\n";
        std::cout << "1. Insertar usuario\n";
        std::cout << "2. Buscar usuario por ID\n";
        std::cout << "3. Eliminar usuario por ID\n";
        std::cout << "4. Mostrar recorrido (inOrden, preOrden, postOrden)\n";
        std::cout << "5. Mostrar usuarios ordenados por nombre\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int id, edad;
            float saldo;
            std::string nombre;

            std::cout << "ID: "; std::cin >> id;
            std::cout << "Nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);
            std::cout << "Edad: "; std::cin >> edad;
            std::cout << "Saldo: "; std::cin >> saldo;

            arbol.insertarUsuario(id, nombre, edad, saldo);
            break;
        }

        case 2: {
            int id;
            std::cout << "ID a buscar: "; std::cin >> id;
            Usuario* u = arbol.buscarUsuario(id);
            if (u) u->mostrarDatos();
            else std::cout << "Usuario no encontrado.\n";
            break;
        }

        case 3: {
            int id;
            std::cout << "ID a eliminar: "; std::cin >> id;
            arbol.eliminarUsuario(id);
            std::cout << "Usuario eliminado (si existia).\n";
            break;
        }

        case 4: {
            int tipo;
            std::cout << "Tipo de recorrido:\n";
            std::cout << "1. inOrden\n";
            std::cout << "2. preOrden\n";
            std::cout << "3. postOrden\n";
            std::cout << "Opcion: ";
            std::cin >> tipo;

            switch (tipo) {
            case 1: arbol.mostrarInOrden(); break;
            case 2: arbol.mostrarPreOrden(); break;
            case 3: arbol.mostrarPostOrden(); break;
            default: std::cout << "Opcion invalida.\n"; break;
            }
            break;
        }

        case 5:
            arbol.mostrarOrdenadosPorNombre();
            break;

        case 0:
            std::cout << "Saliendo del programa...\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
            break;
        }

    } while (opcion != 0);

    return 0;
}