#ifndef PILHA_H
#define PILHA_H
#include <QString>

namespace bry
{
    class Pilha
    {
    private:
        int tamanho;
        int topo; //ocupação ou indice
        int *array;
    public:
        Pilha(int tamanho);
        ~Pilha();
        int getTamanho()const {return tamanho;}

        void empilhar(int elemento);
        void desempilhar();
        bool estaCheia()const {return (topo==(tamanho-1));}
        bool estaVazia()const {return (topo==-1);}
        int acessar()const;
    };
}

#endif // PILHA_H
