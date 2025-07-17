#include "criar_mapa_altitude.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/**
 Construtor da classe MapaAltitudes.
 Inicializa o ponteiro da matriz como nulo.
 */
MapaAltitudes::MapaAltitudes() {
    mapa_altitudes = nullptr;
}

/**
 Gera um número float aleatório entre -range e +range.
 @param range Valor máximo (positivo) da faixa
 @return Número float aleatório no intervalo [-range, range]
 */
float MapaAltitudes::randomFloat(float range) {
    return ((float(rand()) / float(RAND_MAX)) * 2 - 1) * range;
}

/**
 Gera o mapa de altitudes com o algoritmo Diamond-Square.
 @param n Nível de detalhamento do mapa (tamanho será 2^n + 1)
 @param rugosidade Fator de variação aleatória entre os pontos
 @return 0 em caso de sucesso
 */
int MapaAltitudes::gerarMapa(int n, float rugosidade) {
    tamanho = pow(2, n) + 1;

    srand(time(0)); // Inicializa o gerador de números aleatórios

    // Valores aleatórios iniciais para os cantos
    double c1 = rand() % 100;
    double c2 = rand() % 100;
    double c3 = rand() % 100;
    double c4 = rand() % 100;

    // Aloca a matriz de altitudes
    mapa_altitudes = new double*[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        mapa_altitudes[i] = new double[tamanho];
    }

    // Define os cantos
    mapa_altitudes[0][0] = c1;
    mapa_altitudes[0][tamanho - 1] = c2;
    mapa_altitudes[tamanho - 1][0] = c3;
    mapa_altitudes[tamanho - 1][tamanho - 1] = c4;

    int passo = tamanho - 1;
    diamondSquare(passo, rugosidade);

    return 0;
}

/**
 Aplica o algoritmo Diamond-Square recursivamente.
 @param passo Distância entre os pontos em cada iteração
 @param rugosidade Valor máximo da perturbação aleatória
 */
void MapaAltitudes::diamondSquare(int passo, float rugosidade) {
    if (passo <= 1) return;

    int metade = passo / 2;

    // Etapa Diamond
    for (int y = 0; y < tamanho - 1; y += passo) {
        for (int x = 0; x < tamanho - 1; x += passo) {
            diamondStep(x, y, passo, rugosidade);
        }
    }

    // Etapa Square
    for (int y = 0; y < tamanho; y += metade) {
        for (int x = (y + metade) % passo; x < tamanho; x += passo) {
            squareStep(x, y, passo, rugosidade);
        }
    }

    // Recursão para passo menor
    diamondSquare(passo / 2, rugosidade / 2);
}

/**
 Executa a etapa Diamond do algoritmo.
 @param x Coordenada x do quadrado
 @param y Coordenada y do quadrado
 @param passo Tamanho do quadrado
 @param rugosidade Rugosidade atual a ser aplicada
 */
void MapaAltitudes::diamondStep(int x, int y, int passo, float rugosidade) {
    int metade = passo / 2;

    float media = (mapa_altitudes[y][x] +
                   mapa_altitudes[y + passo][x] +
                   mapa_altitudes[y][x + passo] +
                   mapa_altitudes[y + passo][x + passo]) / 4.0f;

    double newpoint = media + randomFloat(rugosidade);
    newpoint = std::clamp(newpoint, 0.0, 100.0);

    mapa_altitudes[y + metade][x + metade] = newpoint;
}

/**
 Executa a etapa Square do algoritmo.
 @param x Coordenada x do ponto
 @param y Coordenada y do ponto
 @param passo Tamanho do intervalo atual
 @param rugosidade Rugosidade atual a ser aplicada
 */
void MapaAltitudes::squareStep(int x, int y, int passo, float rugosidade) {
    int metade = passo / 2;
    float soma = 0.0f;
    int contagem = 0;

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

    double newpoint = (soma / contagem) + randomFloat(rugosidade);
    newpoint = std::clamp(newpoint, 0.0, 100.0);

    mapa_altitudes[y][x] = newpoint;
}

/**
 Retorna a altitude de um ponto específico da matriz.
 @param lin Linha da matriz
 @param col Coluna da matriz
 @return Valor de altitude
 */
int MapaAltitudes::consultarAltitude(int lin, int col) {
    return mapa_altitudes[lin][col];
}

/**
 Retorna a quantidade de linhas do mapa.
 @return Número de linhas
 */
int MapaAltitudes::consultarQntLinhas() {
    return tamanho;
}

/**
 Retorna a quantidade de colunas do mapa.
 @return Número de colunas
 */
int MapaAltitudes::consultarQntColunas() {
    return tamanho;
}

/**
 Salva a matriz de altitudes em um arquivo texto.
 @param name Nome do arquivo a ser salvo
 @return 0 em caso de sucesso, -1 em caso de erro
 */
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

/**
 Lê a matriz de altitudes de um arquivo.
 @param name Nome do arquivo a ser lido
 @return 0 em caso de sucesso, -1 em caso de erro
 */
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

/**
 Destrutor da classe MapaAltitudes.
 Libera a memória alocada para a matriz de altitudes.
 */
MapaAltitudes::~MapaAltitudes() {
    if (mapa_altitudes) {
        for (int i = 0; i < tamanho; ++i) {
            delete[] mapa_altitudes[i];
        }
        delete[] mapa_altitudes;
    }
}
