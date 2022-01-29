#ifndef LAB_H
#define LAB_H

#include <stdexcept>
#include <vector>
#include <string>

enum Reagente {R1,R2,R3,R4};

class errLab : public std::runtime_error
{
public:
    errLab(const std::string& erro) : std::runtime_error(erro) {}
};

class Stock
{
private:
    size_t quantidade;
public:
    Stock(size_t x):quantidade{x} {}
    size_t stock() const {return quantidade;}
    void entrada(size_t x) {quantidade+=x;}
    void saida(size_t x) {
        if(x>quantidade) throw errLab{"Stock insuficiente"};
        quantidade-=x;
    }
};
std::istream& operator>>(std::istream&, Stock&);
std::ostream& operator<<(std::ostream&, const Stock&);

class Lab
{
private:
    std::vector<Stock> stock;
    const std::string fichStock;
public:
    Lab(const std::string& fich);
    ~Lab() {gravarStock();}

    void compra(Reagente r, size_t x) {stock[r].entrada(x);}

    void teste1();
    void teste2();

    void mostrarStock() const;

private:
    void usado(Reagente r, size_t x) {stock[r].saida(x);}
    void gravarStock() const;
};


#endif // LAB_H
