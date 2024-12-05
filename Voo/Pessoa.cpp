#include "Pessoa.h"
int Pessoa:: contadorCodigo = 0;

//Construtor
Pessoa::Pessoa(string nome, string telefone) {
    setNome(nome);
    setTelefone(telefone);
    codigo = ++contadorCodigo;
}
Pessoa::Pessoa(){}

void Pessoa::setTelefone(const string& telefone) {
    if (telefone.size() == 13) {
            this->telefone = telefone;
     } else {
        cout << "Telefone inválido! Certifique-se de que tenha 11 números e esteja no formato correto (XX)XXXXXXXXXXX.\n";
    }
}
string Pessoa::getTelefone() const{
    return telefone;
}

void Pessoa::setNome(const string& nome){
    this->nome = nome;
}

string Pessoa::getNome() const{
    return nome;
}

int Pessoa::getCodigo() const{
    return codigo;
}


Pessoa Pessoa::cadastrarNovaPessoa(){
    string nome, telefone;
    cout << "Informe os dados da pessoa\nNome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);
    Pessoa pessoa(nome, telefone);
    return pessoa;
}

void Pessoa::imprimirInformacoes() const {
    cout << "Nome: " << nome << ", Telefone: " << telefone << ", Código: " << codigo << endl;
}