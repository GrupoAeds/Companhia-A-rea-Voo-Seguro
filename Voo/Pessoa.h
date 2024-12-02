#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome, telefone;
    int codigo;
    static int contadorCodigo;

public:
    Pessoa(string nome, string telefone);
    
    void setTelefone(const string& telefone);
    string getTelefone() const;

    void setNome(const string& nome);
    string getNome() const;

    int getCodigo() const;

    static Pessoa cadastrarNovaPessoa();

    virtual void imprimirInformacoes() const;
};

#endif // PESSOA_H