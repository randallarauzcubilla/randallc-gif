#include "pch.h"
using namespace System;
#include "ArbolUsuarios.h"
#include "GrafoRutas.h"
#include <iostream>


// Declaraciones antes del main
void menuUsuarios(ArbolUsuarios& arbol);
void menuRutas(GrafoRutas& grafo);

int main() {
    ArbolUsuarios arbol;
    arbol.cargarDesdeArchivo("usuarios.txt");
    GrafoRutas grafo;
    grafo.cargarDesdeArchivo("rutas.txt");
    grafo.mostrarEstaciones(); 
    int opcionPrincipal;

    do {
        std::cout << "\n--- MENU PRINCIPAL ---\n";
        std::cout << "1. Gestionar usuarios\n";
        std::cout << "2. Consultar rutas\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1:
            menuUsuarios(arbol);
            break;
        case 2:
            menuRutas(grafo);
            break;
        case 0:
            std::cout << "Saliendo del programa...\n";
            arbol.guardarEnArchivo("usuarios.txt");
            break;
        default:
            std::cout << "Opcion invalida.\n";
            break;
        }
    } while (opcionPrincipal != 0);

    return 0;
}

void menuUsuarios(ArbolUsuarios& arbol) {
    int opcion;
    do {
        std::cout << "\n--- MENU DE USUARIOS ---\n";
        std::cout << "1. Insertar usuario\n";
        std::cout << "2. Buscar usuario por ID\n";
        std::cout << "3. Eliminar usuario por ID\n";
        std::cout << "4. Mostrar recorrido (inOrden, preOrden, postOrden)\n";
        std::cout << "5. Mostrar usuarios ordenados por nombre\n";
        std::cout << "0. Volver\n";
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
            std::cout << "ID a eliminar: ";
            std::cin >> id;

            Usuario* u = arbol.buscarUsuario(id);
            if (u) {
                arbol.eliminarUsuario(id);
                std::cout << "Usuario eliminado exitosamente.\n";
            }
            else {
                std::cout << "No se encontro ningun usuario con ese ID.\n";
            }
            break;
        }

        case 4: {
            int tipo;
            std::cout << "Tipo de recorrido:\n";
            std::cout << "1. inOrden\n";
            std::cout << "2. preOrden\n";
            std::cout << "3. postOrden\n";
            std::cout << "Opcion: "; std::cin >> tipo;

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
            std::cout << "Volviendo al menu principal...\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
            break;
        }
    } while (opcion != 0);
}

void menuRutas(GrafoRutas& grafo) {
    int opcion;
    do {
        std::cout << "\n--- MENU DE RUTAS ---\n";
        std::cout << "1. Mostrar matriz de adyacencia\n";
        std::cout << "2. Calcular ruta mas corta (Dijkstra)\n";
        std::cout << "3. Recorrido en anchura (BFS)\n";
        std::cout << "4. Recorrido en profundidad (DFS)\n";
        std::cout << "5. Arbol de expansion minima (Prim)\n";
        std::cout << "0. Volver\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            grafo.mostrarMatriz();
            break;
        case 2: {
            std::string origen, destino;
            std::cin.ignore();
            std::cout << "Estacion de origen: ";
            std::getline(std::cin, origen);
            std::cout << "Estacion de destino: ";
            std::getline(std::cin, destino);
            grafo.dijkstra(origen, destino);
            break;
        }
        case 3: {
            std::string inicio;
            std::cin.ignore();
            std::cout << "Estacion de inicio: ";
            std::getline(std::cin, inicio);
            grafo.bfs(inicio);
            break;
        }
        case 4: {
            std::string inicio;
            std::cin.ignore();
            std::cout << "Estacion de inicio: ";
            std::getline(std::cin, inicio);
            grafo.dfs(inicio);
            break;
        }
        case 5:
            grafo.prim();
            break;
        case 0: break;
        default: std::cout << "Opcion invalida.\n"; break;
        }
    } while (opcion != 0);
}