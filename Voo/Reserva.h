#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
using namespace std;

class Passageiro;
class Voo;

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

        void imprimirReserva(const Passageiro& passageiro, const Voo& voo) const;
};



#endif // RESERVA_H
