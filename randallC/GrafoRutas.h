#ifndef GRAFO_RUTAS_H
#define GRAFO_RUTAS_H

#include <string>
#include <vector>

const int MAX_ESTACIONES = 100;
const int INF = 1000000000;

class GrafoRutas {
private:
    int** matriz; // ahora en el heap
    std::vector<std::string> estaciones;
    int cantidad;

    int obtenerIndice(const std::string& nombre);

public:
    GrafoRutas();
    ~GrafoRutas(); // destructor para liberar memoria

    void agregarEstacion(const std::string& nombre);
    void agregarRuta(const std::string& origen, const std::string& destino, int peso);
    void mostrarMatriz();
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void mostrarEstaciones() const;

    void dijkstra(const std::string& origen, const std::string& destino);
    void bfs(const std::string& inicio);
    void dfs(const std::string& inicio);
    void prim();
};

#endif