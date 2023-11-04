#include "ordenar.h"

namespace bry
{
    Ordenar::Ordenar(int tamanho):tamanho(0),array(0)
    {
        try
        {
            array=new int[tamanho];
            this->tamanho=tamanho;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Não foi possível criar.");
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        for(int i=0;i<tamanho;i++)
        {
            int random=std::rand()%101;

            *(array+i)=random;
        }
    }

    Ordenar::~Ordenar()
    {
        if(array)
        {
            delete []array;
        }
    }

    QString Ordenar::ordenarPilha()const
    {
        bry::Pilha p1(tamanho);
        bry::Pilha aux(tamanho);
        int ordenado[tamanho];
        QString saida="";

        for(int i=0;i<tamanho;i++)
        {
            p1.empilhar(*(array+i));
        }

        while(!p1.estaVazia())
        {
            int temp=p1.acessar();
            p1.desempilhar();

            while(!aux.estaVazia() && aux.acessar()>temp)
            {
                p1.empilhar(aux.acessar());
                aux.desempilhar();
            }

            aux.empilhar(temp);
        }

        while(!aux.estaVazia())
        {
            p1.empilhar(aux.acessar());
            aux.desempilhar();
        }


        for(int i=0;i<tamanho;i++)
        {
            saida+=QString::number(ordenado[i]=p1.acessar())+"|";
            p1.desempilhar();
        }

        return saida;
    }

    QString Ordenar::getDesordenado()const
    {
        QString saida="";

        for(int i=0;i<tamanho;i++)
        {
            saida+=QString::number(*(array+i))+"|";
        }

        return saida;
    }
}


