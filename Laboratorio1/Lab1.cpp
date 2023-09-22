//Importando las librerias necesarias
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream> 
using namespace std;
// Funcion para generar un punto aleatorio en una dimensión d
vector<double> generarPuntoAleatorio(int d, mt19937& gen, uniform_real_distribution<>& dis) {
    vector<double> punto;
    for (int i = 0; i < d; i++) {
        double coordenada = dis(gen); // Genera un número aleatorio entre 0.0 y 1.0
        punto.push_back(coordenada);
    }
    return punto;
}
// Funcion para calcular la distancia euclidiana entre dos puntos
double DistanciaEuclidiana(const vector<double>& punto1, const vector<double>& punto2) {
    if (punto1.size() != punto2.size()) {
        cerr << "Los puntos tienen diferentes dimensiones." << endl;
        return -1.0; // Manejo de error
    }
    double distancia = 0.0;
    for (int i = 0; i < punto1.size(); i++) {
        double dif = punto1[i] - punto2[i];
        distancia += dif * dif;
    }
    return sqrt(distancia);
}
int main() {
    mt19937 gen(727); // Utilizamos la semilla 727
    uniform_real_distribution<> dis(0.0, 1.0);
    vector<int> dimensiones = {10, 50, 100, 500, 1000, 2000, 5000};
    // Vector de vectores para almacenar las distancias para cada dimensión
    vector<vector<double>> distanciasPorDimension;
    for (int d : dimensiones) {
        // Generando 100 puntos aleatorios de dimensión d
        vector<vector<double>> puntos;
        for (int i = 0; i < 100; i++) {
            vector<double> punto = generarPuntoAleatorio(d, gen, dis);
            puntos.push_back(punto);
        }
        // Calculando la distancia entre todos los pares de puntos y almacenandolas en un vector
        vector<double> distancias;
        for (int i = 0; i < puntos.size(); i++) {
            for (int j = i + 1; j < puntos.size(); j++) {
                double distancia = DistanciaEuclidiana(puntos[i], puntos[j]);
                distancias.push_back(distancia);
            }
        }
        // Almacenar el vector de distancias en el vector de vectores
        distanciasPorDimension.push_back(distancias);
        // Creando un archivo de texto con las distancias de su respectiva dimension d
        string nombreArchivo = "distancias_d" + to_string(d) + ".txt";
        ofstream archivo(nombreArchivo);
        // Guardando las distancias
        for (double distancia : distancias) {
            archivo << distancia << endl;
        }
        // Cerrar el archivo
        archivo.close();
        cout << "Dimension " << d << ": Distancias generadas y almacenadas en " << nombreArchivo << endl;
    }
    return 0;
}
