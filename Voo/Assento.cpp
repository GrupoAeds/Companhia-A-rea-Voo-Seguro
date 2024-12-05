#include "Assento.h"
#include <iostream>
#include "Voo.h"
#include <string>
#include <fstream> // Certifique-se de incluir esta biblioteca para usar ofstream e ifstream

using namespace std;

Assento::Assento(int numero_assento, int codigo_voo, bool status){
    this->numero_assento = numero_assento;
    this->codigo_voo = codigo_voo;
    this->status = status;
}
Assento::Assento(){}

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
        cout << "Assento Ocupado" << endl;
    } else {
        cout << "Assento Disponível" << endl;
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
    cout << "Status: " << (getStatus() ? "Ocupado" : "Disponível") << endl;
}

void Assento::salvarTexto(ofstream& out) const {
    if (!out) {
        cerr << "Erro ao abrir o arquivo para salvar." << endl;
        return;
    }

    // Salvando os dados do assento no arquivo
    out << numero_assento << endl;  // Escreve o número do assento
    out << codigo_voo << endl;      // Escreve o código do voo
    out << (status ? "Ocupado" : "Disponível") << endl;  // Escreve o status (Ocupado ou Disponível)
}

void Assento::carregarTexto(ifstream& in) {
    if (!in) {
        cerr << "Erro ao abrir o arquivo para carregar." << endl;
        return;
    }

    string numeroAssentoStr, codigoVooStr, statusStr;

    // Lê o número do assento
    getline(in, numeroAssentoStr);
    try {
        numero_assento = std::stoi(numeroAssentoStr);
    } catch (const std::invalid_argument& e) {
        cerr << "Erro ao converter o número do assento: " << numeroAssentoStr << endl;
        numero_assento = -1;  // Atribui um valor padrão para indicar erro
    }

    // Lê o código do voo
    getline(in, codigoVooStr);
    try {
        codigo_voo = std::stoi(codigoVooStr);
    } catch (const std::invalid_argument& e) {
        cerr << "Erro ao converter o código do voo: " << codigoVooStr << endl;
        codigo_voo = -1;  // Atribui um valor padrão para indicar erro
    }

    // Lê o status
    getline(in, statusStr);
    if (statusStr == "Ocupado") {
        status = true;
    } else if (statusStr == "Disponível") {
        status = false;
    } else {
        cerr << "Status inválido no arquivo: " << statusStr << endl;
        status = false; // Valor padrão em caso de erro
    }
}

void Assento::salvarAssentos(const vector<Assento>& assentos, const string& nomeArquivo) {
    ofstream out(nomeArquivo);
    if (!out) {
        cerr << "Erro ao abrir o arquivo para salvar os assentos." << endl;
        return;
    }

    // Para cada assento, chamamos o método salvarTexto para gravar as informações
    for (const auto& assento : assentos) {
        assento.salvarTexto(out);
    }

    out.close();
    cout << "Assentos salvos com sucesso em " << nomeArquivo << endl;
}

vector<Assento> Assento::carregarAssentos(const string& nomeArquivo) {
    ifstream in(nomeArquivo);
    vector<Assento> assentos;
    if (!in) {
        cerr << "Erro ao abrir o arquivo para carregar os assentos." << endl;
        return assentos;
    }

    // Ler os assentos um por um do arquivo
    while (in) {
        Assento assento;
        assento.carregarTexto(in);
        if (in) {
            assentos.push_back(assento);  // Adiciona o assento carregado ao vetor
        }
    }

    in.close();
    cout << "Assentos carregados com sucesso de " << nomeArquivo << endl;
    return assentos;
}