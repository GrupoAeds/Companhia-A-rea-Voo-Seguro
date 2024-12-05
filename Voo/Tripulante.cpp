#include "Tripulante.h"
#include "Pessoa.h"
#include <iostream>
#include <fstream>

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

void Tripulante::salvarTripulantes(const vector<Tripulante>& tripulantes, const string& arquivo) {
    ofstream outFile(arquivo);

    if (!outFile) {
        cout << "Erro ao abrir o arquivo para salvar os tripulantes." << endl;
        return;
    }

    // Escrever os dados dos tripulantes no arquivo
    for (const auto& tripulante : tripulantes) {
        outFile << tripulante.getNome() << endl;
        outFile << tripulante.getTelefone() << endl;
        outFile << tripulante.getCargo() << endl;
    }

    outFile.close();
    cout << "Tripulantes salvos com sucesso!" << endl;
}

vector<Tripulante> Tripulante::carregarTripulantes(const string& arquivo) {
    ifstream inFile(arquivo);
    vector<Tripulante> tripulantes;

    if (!inFile) {
        cout << "Erro ao abrir o arquivo para carregar os tripulantes." << endl;
        return tripulantes;  // Retorna um vetor vazio se não for possível abrir o arquivo
    }

    string nome, telefone, cargo;
    while (getline(inFile, nome) && getline(inFile, telefone) && getline(inFile, cargo)) {
        Tripulante tripulante(nome, telefone, cargo);
        tripulantes.push_back(tripulante);
    }

    inFile.close();
    cout << "Tripulantes carregados com sucesso!" << endl;
    return tripulantes;
}