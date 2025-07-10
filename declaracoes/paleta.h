#ifndef paleta_h
#define paleta_h

#include <string>

struct Cores {
    int red;
    int green;
    int blue;
};

class Paleta {
    private:
        int qnt_cores;
        Cores cores[100];
        int valores[100];

    public:
        Paleta(int qnt = 0, Cores cores[] = {}, int val[] = {});
        
        void setColorQuantity(int qnt);
        void setCores(Cores corlegal[100]);
        void setValores(int val[100]);
        
        int getColorQuantity();
        Cores* getCores();  // Changed to return pointer
        int* getValores();   // Changed to return pointer
        
        Cores getCorByAltura(int altura);
};

#endif