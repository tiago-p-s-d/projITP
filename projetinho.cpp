#include "declaracoes/paleta.h" 
#include <bits/stdc++.h>

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
    
    std::cout << " {" << teste.getCorByAltura(255).green << "}" ;

    

    return 0;
}
