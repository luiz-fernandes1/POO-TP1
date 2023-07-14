#ifndef PAGAMENTOS_HPP
#define PAGAMENTOS_HPP

#include <iostream>
#include <string>

using namespace std;
//---
class Pagamentos{
    private:
        double valor;
        bool foiPago;
    public:
        Pagamentos();
        Pagamentos(double valor = 0, bool foiPago = 0);
        ~Pagamentos();
        void setValor(double valor);
        void setFoiPago(bool foiPago);

        double getValor() const;
        bool getFoiPago() const;
};
#endif