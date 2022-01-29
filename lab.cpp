#include "lab.h"
#include <fstream>
#include <iostream>

using namespace std;

Lab::Lab(const std::string &fich) : fichStock{fich}
{
    ifstream ifs(fichStock);
    stock.resize(4,0);
    if(!ifs) {
        cout << fich << " ainda não existe\n";
        return;
    }

    for(size_t i=Reagente::R1; i<=Reagente::R4; ++i) {
        if(!(ifs>>stock[i])) throw errLab{"Erro na leitura dos stocks"};
    }
}

void Lab::gravarStock() const
{
    ofstream ofs(fichStock);
    if(!ofs) throw errLab{"Não foi possível gravar o stock"};

    for(size_t i=Reagente::R1; i<=Reagente::R4; ++i) {
        if(!(ofs<<stock[i]<<'\n')) throw errLab{"Erro na gravação dos stocks"};
    }

}

void Lab::mostrarStock() const
{
    for(size_t i=Reagente::R1; i<=Reagente::R4;++i) {
        cout <<'R'<<i+1<<": "<<stock[i]<<'\n';
    }
}

void Lab::teste1() {
    usado(Reagente::R1,3);
    usado(Reagente::R2,1);
    usado(Reagente::R4,2);
}

void Lab::teste2() {
    usado(Reagente::R1,1);
    usado(Reagente::R3,5);
    usado(Reagente::R4,3);
}


istream& operator>>(istream& is, Stock& s)
{
    size_t x;
    if(!(is>>x)) return is;
    s.entrada(x);
    return is;
}

ostream& operator<<(ostream& os, const Stock& s)
{
    if(!(os<<s.stock())) return os;
    return os;
}
