#include "pch.h"
#include "GrafoRutas.h"
#include <iostream>
#include <queue>
#include <limits>
#include <stack>
#include <fstream>
#include <sstream>

GrafoRutas::GrafoRutas() {
    cantidad = 0;
    matriz = new int* [MAX_ESTACIONES];
    for (int i = 0; i < MAX_ESTACIONES; ++i) {
        matriz[i] = new int[MAX_ESTACIONES];
        for (int j = 0; j < MAX_ESTACIONES; ++j)
            matriz[i][j] = (i == j) ? 0 : INF;
    }
}

GrafoRutas::~GrafoRutas() {
    for (int i = 0; i < MAX_ESTACIONES; ++i)
        delete[] matriz[i];
    delete[] matriz;
}

int GrafoRutas::obtenerIndice(const std::string& nombre) {
    for (int i = 0; i < cantidad; ++i)
        if (estaciones[i] == nombre)
            return i;
    return -1;
}

void GrafoRutas::agregarEstacion(const std::string& nombre) {
    if (cantidad >= MAX_ESTACIONES) {
        std::cout << "Limite de estaciones alcanzado.\n";
        return;
    }
    if (obtenerIndice(nombre) != -1) {
        //std::cout << "Estacion ya existe.\n";
        return;
    }
    estaciones.push_back(nombre);
    cantidad++;
}

void GrafoRutas::mostrarEstaciones() const {
    std::cout << "Estaciones cargadas:\n";
    for (const auto& est : estaciones)
        std::cout << "- " << est << "\n";
}

void GrafoRutas::agregarRuta(const std::string& origen, const std::string& destino, int peso) {
    int i = obtenerIndice(origen);
    int j = obtenerIndice(destino);
    if (i == -1 || j == -1) {
        std::cout << "Una o ambas estaciones no existen.\n";
        return;
    }
    matriz[i][j] = peso;
    matriz[j][i] = peso; // Si es bidireccional
}

void GrafoRutas::mostrarMatriz() {
    imprimirMatrizAdyacencia(std::cout);
}

void GrafoRutas::dijkstra(const std::string& origen, const std::string& destino) {
    int n = cantidad;
    std::vector<int> dist(n, INF);
    std::vector<int> previo(n, -1);
    std::vector<bool> visitado(n, false);

    int inicio = obtenerIndice(origen);
    int fin = obtenerIndice(destino);

    if (inicio == -1 || fin == -1) {
        std::cout << "Una o ambas estaciones no existen.\n";
        return;
    }

    dist[inicio] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visitado[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (u == -1 || dist[u] == INF) break;
        visitado[u] = true;

        for (int v = 0; v < n; ++v) {
            if (matriz[u][v] != INF && dist[u] + matriz[u][v] < dist[v]) {
                dist[v] = dist[u] + matriz[u][v];
                previo[v] = u;
            }
        }
    }

    if (dist[fin] == INF) {
        std::cout << "No hay ruta entre " << origen << " y " << destino << ".\n";
        return;
    }

    std::cout << "Distancia minima: " << dist[fin] << " km.\nRuta: ";
    std::stack<int> ruta;
    for (int v = fin; v != -1; v = previo[v])
        ruta.push(v);

    while (!ruta.empty()) {
        int idx = ruta.top();
        ruta.pop();
        if (idx < 0 || idx >= estaciones.size()) {
            std::cout << "[Error: indice fuera de rango]\n";
            return;
        }
        std::cout << estaciones[idx];
        if (!ruta.empty()) std::cout << " -> ";
    }
    std::cout << "\n";
}

void GrafoRutas::bfs(const std::string& inicio) {
    int n = cantidad;
    int idx = obtenerIndice(inicio);
    if (idx == -1) {
        std::cout << "Estacion no encontrada.\n";
        return;
    }

    std::vector<bool> visitado(n, false);
    std::queue<int> cola;

    visitado[idx] = true;
    cola.push(idx);

    std::cout << "Recorrido BFS desde " << inicio << ": ";

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        std::cout << estaciones[u] << " ";

        for (int v = 0; v < n; ++v) {
            if (matriz[u][v] != INF && !visitado[v]) {
                visitado[v] = true;
                cola.push(v);
            }
        }
    }
    std::cout << "\n";
}

void GrafoRutas::dfs(const std::string& inicio) {
    int n = cantidad;
    int idx = obtenerIndice(inicio);
    if (idx == -1) {
        std::cout << "Estacion no encontrada.\n";
        return;
    }

    std::vector<bool> visitado(n, false);
    std::stack<int> pila;

    pila.push(idx);

    std::cout << "Recorrido DFS desde " << inicio << ": ";

    while (!pila.empty()) {
        int u = pila.top();
        pila.pop();

        if (!visitado[u]) {
            visitado[u] = true;
            std::cout << estaciones[u] << " ";

            for (int v = n - 1; v >= 0; --v) {
                if (matriz[u][v] != INF && !visitado[v]) {
                    pila.push(v);
                }
            }
        }
    }
    std::cout << "\n";
}

void GrafoRutas::prim() {
    int n = cantidad;
    std::vector<int> key(n, INF);
    std::vector<bool> mstSet(n, false);
    std::vector<int> padre(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mstSet[u] = true;

        for (int v = 0; v < n; ++v) {
            if (matriz[u][v] != INF && !mstSet[v] && matriz[u][v] < key[v]) {
                padre[v] = u;
                key[v] = matriz[u][v];
            }
        }
    }

    std::cout << "Arbol de expansion minima (Prim):\n";
    for (int i = 1; i < n; ++i) {
        if (padre[i] != -1)
            std::cout << estaciones[padre[i]] << " - " << estaciones[i]
            << " : " << matriz[i][padre[i]] << " km\n";
    }
}

void GrafoRutas::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivoRutas(nombreArchivo);
    if (!archivoRutas.is_open()) {
        std::cout << "No se pudo abrir el archivo de rutas.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivoRutas, linea)) {
        std::stringstream ss(linea);
        std::string origen, destino, pesoStr;
        int peso;

        std::getline(ss, origen, ',');
        std::getline(ss, destino, ',');
        std::getline(ss, pesoStr);

        try {
            peso = std::stoi(pesoStr);
        }
        catch (...) {
            std::cout << "Error al convertir el peso en la línea: " << linea << "\n";
            continue;
        }

        agregarEstacion(origen);
        agregarEstacion(destino);
        agregarRuta(origen, destino, peso);
    }

    archivoRutas.close();
}

void GrafoRutas::imprimirMatrizAdyacencia(std::ostream& out) {
    out << "\nMatriz de adyacencia (distancias en km):\n   ";
    for (int i = 0; i < cantidad; ++i)
        out << estaciones[i] << " ";
    out << "\n";

    for (int i = 0; i < cantidad; ++i) {
        out << estaciones[i] << " ";
        for (int j = 0; j < cantidad; ++j) {
            if (matriz[i][j] == INF)
                out << "INF ";
            else
                out << matriz[i][j] << " ";
        }
        out << "\n";
    }
}