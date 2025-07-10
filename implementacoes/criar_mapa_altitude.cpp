#include "criar_mapa_altitude.h"
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include <ctime> 

MapaAltitudes::MapaAltitudes() {
    mapa_altitudes = nullptr;
}


int MapaAltitudes::gerarMapa(int n, int rugosidade){
    tamanho = pow(2, n)+1;

    srand(time(0)); // inicializa o gerador com o segundo atual
    int min = 1;
    int max = 100;
    // gera um número aleatório no intervalo [min, max]
    int c1 = (rand() % (max - min + 1)) + min;
    int c2 = (rand() % (max - min + 1)) + min;
    int c3 = (rand() % (max - min + 1)) + min;
    int c4 = (rand() % (max - min + 1)) + min;

     // Alocar memória para a matriz
    mapa_altitudes = new int*[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        mapa_altitudes[i] = new int[tamanho];
    }

    // Inicializar os 4 cantos com valores aleatórios
    mapa_altitudes[0][0] = c1;
    mapa_altitudes[0][tamanho - 1] = c2;
    mapa_altitudes[tamanho - 1][0] = c3;
    mapa_altitudes[tamanho - 1][tamanho - 1] = c4;

    // A continuação será o algoritmo Diamond-Square, mas isso completa a parte dos cantos

    

}


MapaAltitudes::~MapaAltitudes() {
    if (mapa_altitudes) {
        for (int i = 0; i < tamanho; ++i) {
            delete[] mapa_altitudes[i];
        }
        delete[] mapa_altitudes;
    }
}

