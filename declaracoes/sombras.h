#ifndef sombras_h
#define sombras_h

#include "criar_imagem.h"
#include "criar_mapa_altitude.h"

class Sombras {
    public:
        void aplicarSombra(Imagem& imagem, MapaAltitudes& mapa);
};

#endif
