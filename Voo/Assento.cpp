#include "Assento.h"
#include <iostream>
#include "Voo.h"

Assento::Assento(int numero_assento, int codigo_voo, bool status){
    this->numero_assento = numero_assento;
    this->codigo_voo = codigo_voo;
    this->status = status;
}

void Assento::setNumero_assento(const int numero_assento) {
    this->numero_assento = numero_assento;
}
int Assento::getNumero_assento() const{
    return numero_assento;
}

void Assento::setCodigo_voo(const int codigo_voo) {
    this->codigo_voo = codigo_voo;
}
int Assento::getCodigo_voo() const{
    return codigo_voo;
}

void Assento::setStatus(const bool status) {
    this->status = status;
}
bool Assento::getStatus() const{
    return status;
}

void Assento::verificarStatus() const{
    if(status){
        cout << "Voo está ativo";
    } else {
        cout << "Voo inativo";
    }
}

Assento Assento::cadastrarAssento(const vector<Voo*>& voos) {
    int numero_assento, codigo_voo;
    bool status;

    cout << "Selecione o código do voo:\n";

    for (const auto* voo : voos) { 
        if (voo) {
            voo->exibirInformacoes(); // Supondo que exibirInformacoes mostra o código do voo.
        }
    }

    cin >> codigo_voo;

    // Encontrar o voo com o código informado
    Voo* vooSelecionado = nullptr;
    for (auto* voo : voos) {
        if (voo && voo->getCodigo_voo() == codigo_voo) { // getCodigo() deve retornar o código do voo.
            vooSelecionado = voo;
            break;
        }
    }

    if (vooSelecionado == nullptr) {
        cout << "Voo não encontrado.\n";
    }

    cout << "Informe os dados do assento \nNúmero do assento: ";
    cin >> numero_assento;

    status = true;

    Assento novoAssento = Assento(numero_assento, codigo_voo, status);
    vooSelecionado->adicionarAssento(novoAssento);
    return novoAssento;
}
        
void Assento::exibirInformacoes() const{
    cout << "Número do Assento: " << getNumero_assento() << endl;
    cout << "Código do Voo: " << getCodigo_voo() << endl;
    cout << "Status: " << (getStatus() ? "Ativo" : "Inativo") << endl;
}