#include "criar_mapa_altitude.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include <ctime> 

MapaAltitudes::MapaAltitudes() {
    mapa_altitudes = nullptr;
}

float MapaAltitudes::randomFloat(float range) {
    return ((float(rand()) / float(RAND_MAX)) * 2 - 1) * range;
}

int MapaAltitudes::gerarMapa(int n, float rugosidade){
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

    int passo = tamanho - 1;
    diamondSquare(passo, rugosidade);

    return 0;
    

}

void MapaAltitudes::diamondSquare(int passo, float rugosidade) {
    if (passo <= 1) return;  // Condição de parada

    int metade = passo / 2;

    // Etapa Diamond: calcula os pontos centrais dos quadrados
    for (int y = 0; y < tamanho - 1; y += passo) {
        for (int x = 0; x < tamanho - 1; x += passo) {
            diamondStep(x, y, passo, rugosidade);
        }
    }

    // Etapa Square: calcula os pontos centrais das bordas
    for (int y = 0; y < tamanho; y += metade) {
        for (int x = (y + metade) % passo; x < tamanho; x += passo) {
            squareStep(x, y, passo, rugosidade);
        }
    }

    // Chama a função recursivamente para quadrantes menores
    diamondSquare(passo / 2, rugosidade / 2);
}

void MapaAltitudes::diamondStep(int x, int y, int passo, float rugosidade) {
    int metade = passo / 2;

    float media = (mapa_altitudes[y][x] +
                   mapa_altitudes[y + passo][x] +
                   mapa_altitudes[y][x + passo] +
                   mapa_altitudes[y + passo][x + passo]) / 4.0f;

    mapa_altitudes[y + metade][x + metade] = media + randomFloat(rugosidade);
}


void MapaAltitudes::squareStep(int x, int y, int passo, float rugosidade) {
    int metade = passo / 2;

    float soma = 0.0f;
    int contagem = 0;

    // Verifica as bordas
    if (x - metade >= 0) {
        soma += mapa_altitudes[y][x - metade];
        contagem++;
    }
    if (x + metade < tamanho) {
        soma += mapa_altitudes[y][x + metade];
        contagem++;
    }
    if (y - metade >= 0) {
        soma += mapa_altitudes[y - metade][x];
        contagem++;
    }
    if (y + metade < tamanho) {
        soma += mapa_altitudes[y + metade][x];
        contagem++;
    }

    mapa_altitudes[y][x] = (soma / contagem) + randomFloat(rugosidade);
}

int MapaAltitudes::consultarAltitude(int lin, int col) {
    return mapa_altitudes[lin][col];
}
int MapaAltitudes::consultarQntLinhas() {
    return tamanho;
}
int MapaAltitudes::consultarQntColunas() {
    return tamanho;
}


int MapaAltitudes::salvarMatriz(std::string name) {
    std::ofstream arquivo(name);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para salvar o mapa!" << std::endl;
        return -1;
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            arquivo << mapa_altitudes[i][j] << " ";
        }
        arquivo << std::endl;
    }

    arquivo.close();
    return 0;
}
int MapaAltitudes::lerMatriz(std::string name) {
    std::ifstream arquivo(name);
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para ler o mapa!" << std::endl;
        return -1;
    }

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            arquivo >> mapa_altitudes[i][j];
        }
    }

    arquivo.close();
    return 0;
}


MapaAltitudes::~MapaAltitudes() {
    if (mapa_altitudes) {
        for (int i = 0; i < tamanho; ++i) {
            delete[] mapa_altitudes[i];
        }
        delete[] mapa_altitudes;
    }
}

