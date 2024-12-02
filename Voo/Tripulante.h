#ifndef TRIPULANTE_H
#define TRIPULANTE_H

#include "Pessoa.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Tripulante : public Pessoa{
    private:
        string cargo;
    public:
    //Construtor
        Tripulante(string nome, string telefone, string cargo);

        void setCargo(const string& Novocargo);
        string getCargo() const;

        static Tripulante cadastrarNovaPessoa();
        void imprimirInformacoes() const override;

};


#endif // TRIPULANTE_H