#ifndef criar_mapa_altitude_h
#define criar_mapa_altitude_h

#include "paleta.h"
#include "criar_imagem.h"
#include <string>
#include <cmath>

class MapaAltitudes{
    private:
    int** mapa_altitudes;
    int tamanho;


    int gerarMapa(int n, int rugosidade);
    int consultarAltitude(int lin, int col);
    int consultarQntLinhas();
    int consultarQntColunas();
    int salvarMatriz(std::string name);
    int lerMatriz(std::string name);

    ~MapaAltitudes();
};





#endif
