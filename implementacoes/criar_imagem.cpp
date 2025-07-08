#include "declaracoes/criar_imagem.h"
#include <fstream>

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

Imagem::~Imagem() {
    for (int i = 0; i < altura; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

Cores Imagem::returnPixel(int l, int a) {
    if (l >= 0 && l < altura && a >= 0 && a < largura) {
        return matriz[l][a];
    }
    return {0, 0, 0};
}

void Imagem::setPixel(int l, int a, Cores cor) {
    if (l >= 0 && l < altura && a >= 0 && a < largura) {
        matriz[l][a] = cor;
    }
}

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
