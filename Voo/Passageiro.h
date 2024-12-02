#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "Pessoa.h"
#include <string>
#include <vector>
#include <iostream>
#include <memory> // Para usar std::unique_ptr ou std::shared_ptr

using namespace std;

class Reserva;
class Voo;

class Passageiro : public Pessoa{
    private:
        bool neymar;
        int pontosFidelidade;
        string endereco;
        vector<shared_ptr<Reserva>> reservas;
    public:
    //Construtor
        Passageiro(string nome, string telefone, string endereco, bool neymar, int pontosFidelidade);
        void setNeymar(const bool &neymar);
        bool getNeymar() const;

        void setPontosFidelidade(const int &pontosFidelidade);
        int getPontosFidelidade() const;

        void setEndereco(const string &endereco);
        string getEndereco() const;

        vector<Reserva> getReservas() const;

        void adicionarPontos(int pontosAdicionados);
        void mostrarPontos() const;

        static Passageiro cadastrarNovaPessoa();

        void imprimirInformacoes() const override;

        void adicionarReserva(Reserva& reserva);

        void reservar(vector<Voo>& listaVoos);

        void baixarReserva(vector<Voo>& listaVoos);
        

};


#endif // PASSAGEIRO_H