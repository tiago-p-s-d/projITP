#include <bits/stdc++.h>


struct Cores{

    int red;
    int blue;
    int green;

};

class Paleta{
    private: int qnt_cores;
    private: Cores cores[100];
    private: int valores[100];


    public:
        Paleta(int qnt = 0, Cores cores[] = {}, int val[] = {}){
            setColorQuantity(qnt);
            setCores(cores);
            setValores(val);
        }



    void setColorQuantity(int qnt){
        this->qnt_cores = qnt;
    }
    void setCores(Cores corlegal[100]){
        for (int i = 0; i < qnt_cores; ++i) {
            this->cores[i] = corlegal[i];
        }  
    }
    void setValores(int val[100]){   
        for (int i = 0; i < qnt_cores; ++i) {
            this->valores[i] = val[i];
        }
    }
    
    int getColorQuantity(){return this->qnt_cores;}
    Cores getCores(){return this->cores[100];}
    int getValores(){return this->valores[100];}

    Cores getCorByAltura(int altura){
        for (int i = 0; i < this->qnt_cores; i++)
        {
            if(altura == valores[i]){
                return cores[i];
                break;
            }
        }
        return {0, 0, 0};
    }
};

int main()
{
    Cores red = {255, 0, 0};
    Cores green = {0, 255, 0};
    Cores blue = {0, 0, 255};
    Cores blorb= {255, 0, 255};
    Cores azulbebejujubademacaverde = {255, 255, 255};

    Cores arrc[] = {red, green, blue,blorb, azulbebejujubademacaverde};
    int arri[]={0,10, 15, 20, 255};
    
    Paleta teste(
        5,
        arrc, 
        arri
    );
    /*Paleta teste2{
        2,
        {{255,0,0}, {0, 255, 0}},
        {0,10}
    };
    */
   
   
    std::cout << " {" << teste.getCorByAltura(20).red << ","; 
    std::cout << " " << teste.getCorByAltura(20).green << ","; 
    std::cout << " " << teste.getCorByAltura(20 ).blue << "}"; 

    

    return 0;
}
