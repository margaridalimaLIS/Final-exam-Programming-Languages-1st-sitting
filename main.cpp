#include "lab.h"
#include <iostream>
using namespace std;

int main()
try{
    Lab l("stocks.txt");
    cout << "Stock inicial:\n";
    l.mostrarStock();
    cout << "Comprar reagentes (s/n): ";
    char r;
    cin >> r;
    if(r=='s' || r=='S') {
        l.compra(Reagente::R1,8);
        l.compra(Reagente::R2,8);
        l.compra(Reagente::R3,8);
        l.compra(Reagente::R4,8);
    }
    cout << "fazendo o teste1\n";
    l.teste1();
    cout << "fazendo o teste2\n";
    l.teste2();
    cout << "Stock final:\n";
    l.mostrarStock();
    return 0;
}
catch(const errLab& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Erro inesperado\n";
    return 2;
}
