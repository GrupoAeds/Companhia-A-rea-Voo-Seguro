#include "Tripulante.h"
#include "Pessoa.h"
#include <iostream>

Tripulante::Tripulante(string nome, string telefone, string cargo)
    : Pessoa(nome, telefone) {
    setCargo(cargo);
}

void Tripulante::setCargo(const string& Novocargo){  // metodo para validar se o cargo informado eh valido 
    if(Novocargo=="Piloto"|| Novocargo=="piloto" || Novocargo=="Copiloto"|| Novocargo=="copiloto" || Novocargo=="Comissario" || Novocargo=="comissario"){
        cargo=Novocargo;
    } else {
        cout<<"O cargo informado nao eh valido, por favor informe o cargo correto"<<endl;
    }
    }
    string Tripulante::getCargo() const {
    return cargo;
}

Tripulante Tripulante::cadastrarNovaPessoa() {
    string nome, telefone, cargo;
    cout << "Informe os dados do tripulante \nNome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Cargo (Piloto, Copiloto, Comissario): ";
    getline(cin, cargo);
    Tripulante tripulante(nome, telefone, cargo);
    return tripulante;
}

void Tripulante::imprimirInformacoes() const {
    Pessoa::imprimirInformacoes();
    cout << "Cargo: " << cargo << endl;
}