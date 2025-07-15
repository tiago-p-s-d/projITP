#include "paleta.h"
#include <bits/stdc++.h>

Paleta::Paleta(int qnt, Cores cores[], int val[]) {
    setColorQuantity(qnt);
    setCores(cores);
    setValores(val);
}

void Paleta::setColorQuantity(int qnt) {
    this->qnt_cores = qnt;
}

void Paleta::setCores(Cores corlegal[100]) {
    for (int i = 0; i < qnt_cores; ++i) {
        this->cores[i] = corlegal[i];
    }  
}

void Paleta::setValores(int val[100]) {   
    for (int i = 0; i < qnt_cores; ++i) {
        this->valores[i] = val[i];
    }
}

int Paleta::getColorQuantity() { return this->qnt_cores; }

Cores* Paleta::getCores() { return this->cores; }  // Changed to return pointer to array

int* Paleta::getValores() { return this->valores; } // Changed to return pointer to array

Cores Paleta::getCorByAltura(int altura) {
    int limite_inferior = 0;
    for (int i = 0; i < this->qnt_cores; i++) {
        int limite_superior = valores[i];

        // Último intervalo inclui o limite superior
        if (i == qnt_cores - 1) {
            if (altura >= limite_inferior && altura <= limite_superior) {
                return cores[i];
            }
        } else {
            if (altura >= limite_inferior && altura < limite_superior) {
                return cores[i];
            }
        }

        limite_inferior = limite_superior;
    }

    // Se não encontrar, retorna preto
    return {0, 0, 0};
}