#include "sombras.h"

void Sombras::aplicarSombra(Imagem& imagem, MapaAltitudes& mapa) {
    int linhas = mapa.consultarQntLinhas();
    int colunas = mapa.consultarQntColunas();

    for (int i = 1; i < linhas; ++i) {
        for (int j = 1; j < colunas; ++j) {
            int alt_atual = mapa.consultarAltitude(i, j);
            int alt_superior_esquerda = mapa.consultarAltitude(i - 1, j - 1);

            if (alt_superior_esquerda > alt_atual) {
                Cores pixel = imagem.returnPixel(i, j);
                pixel.red = static_cast<int>(pixel.red * 0.5);
                pixel.green = static_cast<int>(pixel.green * 0.5);
                pixel.blue = static_cast<int>(pixel.blue * 0.5);
                imagem.setPixel(i, j, pixel);
            }
        }
    }
}
