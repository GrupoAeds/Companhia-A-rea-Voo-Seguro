#include "Voo.h"
#include <iostream>
#include <string>
#include "Assento.h"
#include "Tripulante.h"
#include <algorithm>
using namespace std;

int Voo::contadorCodigoVoo = 0;

Voo::Voo(int codigo_aviao, int codigo_piloto, int codigo_copiloto, int codigo_comissario, Data data, Hora hora, string origem, string destino, bool status, double tarifa){
    setCodigo_aviao(codigo_aviao);
    setCodigo_piloto(codigo_piloto);
    setCodigo_copiloto(codigo_copiloto);
    setCodigo_comissario(codigo_comissario);
    setData(data);
    setHora(hora);
    setOrigem(origem);
    setDestino(destino);
    setStatus(status);
    setTarifa(tarifa);
    codigo_voo = ++contadorCodigoVoo;
}

int Voo::getCodigo_voo() const{
    return codigo_voo;
}

void Voo::setCodigo_aviao(int codigo_aviao) {
    this->codigo_aviao = codigo_aviao;
}
int Voo::getCodigo_aviao() const{
    return codigo_aviao;
}

void Voo::setCodigo_piloto(int codigo_piloto) {
    this->codigo_piloto = codigo_piloto;
}
int Voo::getCodigo_piloto() const{
    return codigo_piloto;
}

void Voo::setCodigo_copiloto(int codigo_copiloto) {
    this->codigo_copiloto = codigo_copiloto;
}
int Voo::getCodigo_copiloto() const{
    return codigo_copiloto;
}

void Voo::setCodigo_comissario(int codigo_comissario) {
    this->codigo_comissario = codigo_comissario;
}
int Voo::getCodigo_comissario() const{
    return codigo_comissario;
}

void Voo::setData(const Data& data) {
    this->data = data;
}
Data Voo::getData() const{
    return data;
}

void Voo::setHora(const Hora& hora) {
    this->hora = hora;
}
Hora Voo::getHora() const{
    return hora;
}

void Voo::setOrigem(const string& origem) {
    this->origem = origem;
}
string Voo::getOrigem() const{
    return origem;
}

void Voo::setDestino(const string& destino) {
    this->destino = destino;
}
string Voo::getDestino() const{
    return destino;
}

void Voo::setStatus(bool status) {
    this->status = status;
}
bool Voo::getStatus() const{
    return status;
}

void Voo::setTarifa(double tarifa) {
    this->tarifa = tarifa;
}
double Voo::getTarifa() const{
    return tarifa;
}

vector<Assento>& Voo::getAssentos(){
    return assentos;
}
        
Voo Voo::cadastrarVoo(const vector<Tripulante>& tripulantes) {
    int codigo_aviao, codigo_piloto, codigo_copiloto, codigo_comissario;
    Data data;
    Hora hora;
    std::string origem, destino;
    bool status = true;
    double tarifa;

    cout << "Informe os dados do voo \nOrigem: ";
    getline(cin, origem);
    cout << "Destino: ";
    getline(cin, destino);
    cout << "Ano: ";
    cin >> data.ano;
    cout << "Mês: ";
    cin >> data.mes;
    cout << "Dia: ";
    cin >> data.dia;
    cout << "Horas: ";
    cin >> hora.horas;
    cout << "Minutos: ";
    cin >> hora.minutos;
    
    cout << "Lista de pilotos disponíveis:\n";
    for (const auto& tripulante : tripulantes) {
        if (tripulante.getCargo() == "Piloto" || tripulante.getCargo() == "piloto") {
            tripulante.imprimirInformacoes();
        }
    }
    cout << "Código do piloto: ";
    cin >> codigo_piloto;

    cout << "\nLista de copilotos disponíveis:\n";
    for (const auto& tripulante : tripulantes) {
        if (tripulante.getCargo() == "Copiloto" || tripulante.getCargo() == "copiloto") {
            tripulante.imprimirInformacoes();
        }
    }
    cout << "Código do copiloto: ";
    cin >> codigo_copiloto;

    cout << "\nLista de comissários disponíveis:\n";
    for (const auto& tripulante : tripulantes) {
        if (tripulante.getCargo() == "Comissario" || tripulante.getCargo() == "comissario") {
            tripulante.imprimirInformacoes();
        }
    }
    cout << "Código do comissário: ";
    cin >> codigo_comissario;

    cout << "Código do avião: ";
    cin >> codigo_aviao;
    cout << "Tarifa: ";
    cin >> tarifa;

    cin.ignore(); // Limpa o buffer de entrada
    Voo novoVoo(codigo_aviao, codigo_piloto, codigo_copiloto, codigo_comissario, data, hora, origem, destino, status, tarifa);
    return novoVoo;
}

void Voo::verificarStatus() const{
    if(status){
        cout << "Voo está ativo";
    } else {
        cout << "Voo inativo";
    }
}

void Voo::exibirInformacoes() const{
    cout << "Código do Voo: " << getCodigo_voo() << endl;
    cout << "Código do Avião: " << getCodigo_aviao() << endl;
    cout << "Código do Piloto: " << getCodigo_piloto() << endl;
    cout << "Código do Copiloto: " << getCodigo_copiloto() << endl;
    cout << "Código do Comissário: " << getCodigo_comissario() << endl;
    cout << "Data: " << getData().dia << "/" << getData().mes << "/" << getData().ano << endl;
    cout << "Hora: " << getHora().horas << ":" << getHora().minutos << endl;
    cout << "Origem: " << getOrigem() << endl;
    cout << "Destino: " << getDestino() << endl;
    cout << "Status: " << (getStatus() ? "Ativo" : "Inativo") << endl;
    cout << "Tarifa: R$ " << getTarifa() << endl;
}

void Voo::adicionarAssento(Assento& assento) {
    assentos.push_back(assento);
}

void Voo::exibirAssentos() const{
    for (auto& assento : assentos) {
        if(assento.getStatus() == true){
            assento.exibirInformacoes(); 
        }
    }
}

