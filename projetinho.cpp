#include "./declaracoes/paleta.h"
#include "./declaracoes/criar_imagem.h"
#include <bits/stdc++.h>

int main()
{
    int largura = 500;
    int altura = 500;

    // Cria imagem preta de 100x100
    Imagem img(largura, altura);

    // Pinta um quadrado vermelho no canto superior esquerdo (20x20)
    Cores vermelho = {255, 0, 0};
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            img.setPixel(i, j, vermelho);
        }
    }

    // Salva a imagem no formato PPM
    img.salvarPPM("teste.ppm", 255);

    return 0;
}
