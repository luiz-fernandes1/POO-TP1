#ifndef COMPRAS_HPP
#define COMPRAS_HPP

#include <iostream>
#include <string>
#include "../produto_servico/produtos.hpp"

using namespace std;

class Compras:public Produtos{
        int qtdParaAdd;
    public:
        Compras();
        Compras(int qtdParaAdd);
        ~Compras();

        void setQtdParaAdd(int qtdParaAdd);
        int getQtdParaAdd() const;
        void addNoEstoque(int qtdParaAdd, int quantidade);
};
#endif