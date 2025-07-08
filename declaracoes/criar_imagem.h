#ifndef criar_imagem_h
#define criar_imagem_h

#include "paleta.h"
#include <string>

class Imagem {
    int largura;
    int altura;
    Cores** matriz;

public:
    Imagem(int l, int a);
    ~Imagem();

    Cores returnPixel(int l, int a);
    void setPixel(int l, int a, Cores cor);
    void salvarPPM(const std::string& nome_arquivo, int valor_max);
};

#endif
