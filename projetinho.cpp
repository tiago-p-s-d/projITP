#include "./declaracoes/paleta.h"
#include "./declaracoes/criar_imagem.h"
#include "./declaracoes/criar_mapa_altitude.h"
#include <bits/stdc++.h>

int main()
{
    MapaAltitudes mapa;
    
    // Gera o mapa com tamanho baseado em 2^n + 1 (n = 5) e rugosidade 10
    mapa.gerarMapa(7, 10);




    // Salva o mapa em um arquivo
    mapa.salvarMatriz("mapa.txt");

    return 0;
}
