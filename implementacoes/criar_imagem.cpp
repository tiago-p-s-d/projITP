#include "criar_imagem.h"
#include <fstream>

/**
 Construtor da classe Imagem.
 Inicializa a matriz de pixels com as dimensões fornecidas e preenche com a cor preta (0,0,0).
 @param l Largura da imagem (número de colunas)
 @param a Altura da imagem (número de linhas)
 */
Imagem::Imagem(int l, int a) {
    largura = l;
    altura = a;

    matriz = new Cores*[altura];
    for (int i = 0; i < altura; ++i) {
        matriz[i] = new Cores[largura];
        for (int j = 0; j < largura; ++j) {
            matriz[i][j] = {0, 0, 0};
        }
    }
}

/**
 Destrutor da classe Imagem.
 Libera a memória alocada para a matriz de pixels.
 */
Imagem::~Imagem() {
    for (int i = 0; i < altura; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

/**
 Retorna a cor de um pixel específico da imagem.
 @param linha Linha (altura) do pixel
 @param coluna Coluna (largura) do pixel
 @return A cor do pixel na posição especificada; retorna preto (0,0,0) se a posição for inválida
 */
Cores Imagem::returnPixel(int linha, int coluna) {
    if (linha >= 0 && linha < altura && coluna >= 0 && coluna < largura) {
        return matriz[linha][coluna];
    }
    return {0, 0, 0};
}

/**
 Define a cor de um pixel específico da imagem.
 @param linha Linha (altura) do pixel
 @param coluna Coluna (largura) do pixel
 @param cor A cor a ser atribuída ao pixel
 */
void Imagem::setPixel(int linha, int coluna, Cores cor) {
    if (linha >= 0 && linha < altura && coluna >= 0 && coluna < largura) {
        matriz[linha][coluna] = cor;
    }
}

/**
 Salva a imagem no formato PPM (P3).
 @param nome_arquivo Nome do arquivo a ser salvo (com extensão .ppm)
 @param valor_max Valor máximo para cada componente de cor (normalmente 255)
 */
void Imagem::salvarPPM(const std::string& nome_arquivo, int valor_max) {
    std::ofstream out(nome_arquivo);

    out << "P3\n";
    out << largura << " " << altura << "\n";
    out << valor_max << "\n";

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            out << matriz[i][j].red << " "
                << matriz[i][j].green << " "
                << matriz[i][j].blue << " ";
        }
        out << "\n";
    }

    out.close();
}
