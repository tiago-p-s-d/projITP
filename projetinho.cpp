#include "./declaracoes/paleta.h"
#include "./declaracoes/criar_imagem.h"
#include "./declaracoes/criar_mapa_altitude.h"
#include <bits/stdc++.h>

int main()
{
    int n = 8;
    float rugosidade = 30;

    // 1. Criar mapa e gerar matriz com o algoritmo diamond-square
    MapaAltitudes mapa;
    mapa.gerarMapa(n, rugosidade);

    // 2. Salvar mapa em arquivo (opcional, mas recomendado para inspeção)
    mapa.salvarMatriz("mapa.txt");

    Cores azul_escuro = {0, 0, 128};
    Cores azul_claro = {43, 50, 255};
    Cores areia =  {210, 180, 140};
    Cores verde_terra = {102, 153, 0};
    Cores neve = {255, 255, 255};

    // Valores são os limites superiores de cada faixa
    int valores[] = {20, 50, 65, 90, 100};
    Cores cores[] = {azul_escuro, azul_claro, areia, verde_terra, neve};

    // Instanciar a paleta
    Paleta paleta(5, cores, valores);
    // 4. Gerar a imagem direto com o mapa já na memória, sem ler do arquivo
    int tamanho = mapa.consultarQntLinhas();
    Imagem imagem(tamanho, tamanho);

    for (int i = 0; i < tamanho; ++i)
    {
        for (int j = 0; j < tamanho; ++j)
        {
            int alt = mapa.consultarAltitude(i, j);
            Cores cor = paleta.getCorByAltura(alt);
            imagem.setPixel(i, j, cor);
        }
    }

    imagem.salvarPPM("saida.ppm", 255);

    std::cout << "Imagem gerada em saida.ppm" << std::endl;

    return 0;
}