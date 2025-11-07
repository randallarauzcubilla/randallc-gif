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
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    void mostrarEstaciones() const;
    void imprimirMatrizAdyacencia(std::ostream& out);

    std::string dijkstra(const std::string& origen, const std::string& destino);
    std::string bfs(const std::string& inicio);
    std::string dfs(const std::string& inicio);
    std::string prim();
    std::string mostrarMatriz();
    bool existeEstacion(const std::string& nombre);
    std::string obtenerEstacionesComoLinea() const;

    int getCantidad() const { return cantidad; }
    int getPeso(int i, int j) const { return matriz[i][j]; }
    std::string getNombreEstacion(int i) const { return estaciones[i]; }
};

#endif