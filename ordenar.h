#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include <pilha.h>
#include <ctime>
#include <cstdlib>

namespace bry
{
    class Ordenar
    {
    private:
        int tamanho;
        int *array;

    public:
        Ordenar(int tamanho);
        ~Ordenar();

        int getTamanho()const {return tamanho;}

        QString getDesordenado()const;
        QString ordenarPilha()const;

    };
}

#endif // ORDENAR_H
