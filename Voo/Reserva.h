#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passageiro;
class Voo;
class Tripulante;

class Reserva{
    private:
        int numero_assento, codigo_voo, codigo_passageiro;
        
    public:
        Reserva(int numero_assento, int codigo_voo, int codigo_passageiro);

        void setNumero_assento(const int numero_assento);
        int getNumero_assento() const;

        void setCodigo_voo(const int codigo_voo);
        int getCodigo_voo() const;

        void setCodigo_passageiro(const int codigo_passageiro);
        int getCodigo_passageiro() const;

        void imprimirReserva(const vector<Voo*>& voos, const Passageiro* passageiro) const;

        static void PesquisarPassageiro(const vector<Passageiro*>& passageiros);
        static void PesquisarTripulante(const vector<Tripulante*>& tripulantes);
        static void PesquisarReservas(const vector<Passageiro*>& passageiros, vector<Voo*>& voos);
};



#endif // RESERVA_H
