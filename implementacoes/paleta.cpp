#include "paleta.h"
#include <bits/stdc++.h>

/**
 Construtor da classe Paleta.
 Inicializa a paleta com um número de cores, um array de cores e um array de valores de altura.
 @param qnt Quantidade de cores na paleta
 @param cores Array de cores (struct Cores) da paleta
 @param val Array de valores inteiros correspondentes aos limites superiores das faixas de altura
 */
Paleta::Paleta(int qnt, Cores cores[], int val[]) {
    setColorQuantity(qnt);
    setCores(cores);
    setValores(val);
}

/**
 Define a quantidade de cores da paleta.
 @param qnt Quantidade de cores
 */
void Paleta::setColorQuantity(int qnt) {
    this->qnt_cores = qnt;
}

/**
 Define as cores da paleta.
 @param cores Array de cores (struct Cores) com no máximo 100 elementos
 */
void Paleta::setCores(Cores cores[100]) {
    for (int i = 0; i < qnt_cores; ++i) {
        this->cores[i] = cores[i];
    }  
}

/**
 Define os valores de altura para cada cor da paleta.
 @param val Array de inteiros representando os limites superiores das faixas de altura
 */
void Paleta::setValores(int val[100]) {   
    for (int i = 0; i < qnt_cores; ++i) {
        this->valores[i] = val[i];
    }
}

/**
 Retorna a quantidade de cores na paleta.
 @return Quantidade de cores
 */
int Paleta::getColorQuantity() {
    return this->qnt_cores;
}

/**
 Retorna um ponteiro para o array de cores da paleta.
 @return Ponteiro para array de cores
 */
Cores* Paleta::getCores() {
    return this->cores;
}

/**
 Retorna um ponteiro para o array de valores de altura da paleta.
 @return Ponteiro para array de inteiros com os valores de altura
 */
int* Paleta::getValores() {
    return this->valores;
}

/**
 Retorna a cor correspondente a uma determinada altura com base na faixa configurada.
 @param altura Valor de altura a ser avaliado
 @return A cor (struct Cores) correspondente à altura informada
 */
Cores Paleta::getCorByAltura(int altura) {
    int limite_inferior = 0;
    for (int i = 0; i < this->qnt_cores; i++) {
        int limite_superior = valores[i];

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

    // Se não encontrar uma cor correspondente, retorna preto
    return {0, 0, 0};
}
