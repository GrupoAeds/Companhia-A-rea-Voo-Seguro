#include "Reserva.h"
#include <iostream>
#include <string>
#include "Voo.h"
#include "Passageiro.h"

using namespace std;

Reserva::Reserva(int numero_assento, int codigo_voo, int codigo_passageiro){
    this->numero_assento = numero_assento;
    this->codigo_voo = codigo_voo;
    this->codigo_passageiro = codigo_passageiro;
}

void Reserva::setCodigo_voo(const int codigo_voo) {
    this->codigo_voo = codigo_voo;
}
int Reserva::getCodigo_voo() const{
    return codigo_voo;
}

void Reserva::setNumero_assento(const int numero_assento) {
    this->numero_assento = numero_assento;
}
int Reserva::getNumero_assento() const{
    return numero_assento;
}

void Reserva::setCodigo_passageiro(const int codigo_passageiro) {
    this->codigo_passageiro = codigo_passageiro;
}
int Reserva::getCodigo_passageiro() const{
    return codigo_passageiro;
} 