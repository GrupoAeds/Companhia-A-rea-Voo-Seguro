#include "Passageiro.h"
#include "Pessoa.h"
#include "Voo.h"
#include "Assento.h"
#include "Reserva.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


Passageiro::Passageiro(string nome, string telefone, string endereco, bool neymar, int pontosFidelidade)
    : Pessoa(nome, telefone) {
    setEndereco(endereco);
    setNeymar(neymar);
    setPontosFidelidade(pontosFidelidade);
}

Passageiro::Passageiro():Pessoa(){}

void Passageiro::setNeymar(const bool &neymar) {
    this->neymar = neymar;
}

bool Passageiro::getNeymar() const{
    return neymar;
}

void Passageiro::setPontosFidelidade(const int &pontosFidelidade) {
    this->pontosFidelidade = pontosFidelidade;
}

int Passageiro::getPontosFidelidade() const{
    return pontosFidelidade;
}

void Passageiro::setEndereco(const string &endereco) {
    this->endereco = endereco;
}

string Passageiro::getEndereco() const{
    return endereco;
}

vector<Reserva> Passageiro::getReservas() const {
    std::vector<Reserva> copiaReservas;
    for (const auto& reservaPtr : reservas) {
        if (reservaPtr) { // Verifica se o ponteiro não é nulo
            copiaReservas.push_back(*reservaPtr);
        }
    }
    return copiaReservas;
}

void Passageiro::adicionarPontos(int pontosAdicionados) {
    if (neymar) {
    pontosFidelidade += pontosAdicionados;
    }
}

void Passageiro::mostrarPontos() const{
    cout << "Pontos de fidelidade: " << pontosFidelidade << endl;
}

Passageiro Passageiro::cadastrarNovaPessoa() {
    string nome, telefone, endereco;
    bool neymar;
    int pontosFidelidade;

    cout << "Informe os dados do passageiro \nNome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);

    cout << "Endereco: ";
    getline(cin, endereco);
    cout << "O passageiro tem o plano de fidelidade? (1 - Sim / 0 - Não): ";
    cin >> neymar;
    cin.ignore();

    cout << "Pontos de fidelidade iniciais: ";
    cin >> pontosFidelidade;
    cin.ignore();

    cout << endl;

    Passageiro passageiro(nome, telefone, endereco, neymar, pontosFidelidade);
    return passageiro;
}

void Passageiro::imprimirInformacoes() const {
    Pessoa::imprimirInformacoes();
    cout << "Endereço: " << endereco << ", Possui o plano fidelidade: " << (neymar ? "Sim" : "Não") << ", Pontos de Fidelidade: " << pontosFidelidade << endl;
}

void Passageiro::reservar(vector<Voo>& listaVoos) {
    int codigo_voo = 0, numero_assento = 0;

    // Lista todos os voos disponíveis
    cout << "\nVoos disponíveis:\n";
    for (const auto& voo : listaVoos) {
        voo.exibirInformacoes();
    }

    // Solicita o código do voo
    cout << "Selecione o código do voo: ";
    cin >> codigo_voo;

    // Busca o voo pelo código
    auto vooIt = find_if(listaVoos.begin(), listaVoos.end(), [codigo_voo](const Voo& voo) {
        return voo.getCodigo_voo() == codigo_voo;
    });

    if (vooIt == listaVoos.end()) {
        cout << "Voo com código " << codigo_voo << " não encontrado.\n";
        return;
    }

    // Exibe os assentos disponíveis no voo
    cout << "\nAssentos disponíveis no voo " << codigo_voo << ":\n";
    vooIt->exibirAssentos();

    // Solicita o número do assento
    cout << "Selecione o número do assento: ";
    cin >> numero_assento;

    // Busca o assento selecionado
    vector<Assento>& assentos = vooIt->getAssentos(); // Obtém a lista de assentos
    auto assentoIt = find_if(assentos.begin(), assentos.end(), [numero_assento](const Assento& assento) {
        return assento.getNumero_assento() == numero_assento;
    });

    if (assentoIt == assentos.end()) {
        cout << "Assento " << numero_assento << " não encontrado no voo " << codigo_voo << ".\n";
        return;
    }

    // Reserva o assento
    if (assentoIt->getStatus()) {
        assentoIt->setStatus(false); // Marca como reservado
        cout << "Assento " << numero_assento << " reservado com sucesso.\n";
    } else {
        cout << "O assento " << numero_assento << " já está reservado.\n";
        return;
    }

    // Cria a reserva e adiciona ao passageiro
    auto novaReserva = std::make_shared<Reserva>(codigo_voo, numero_assento, getCodigo());
    reservas.push_back(novaReserva);

    cout << "Reserva adicionada com sucesso para o passageiro " << getNome() << ".\n";
}

void Passageiro::baixarReserva(vector<Voo>& listaVoos) {
    int codigo_voo, numero_assento;

    // Exibe as reservas do passageiro
    if (reservas.empty()) {
        cout << "O passageiro não possui reservas.\n";
        return;
    }

    cout << "\nReservas do passageiro:\n";
    for (const auto& reservaPtr : reservas) {
        if (reservaPtr) { // Verifica se o ponteiro não é nulo
            cout << "Voo: " << reservaPtr->getCodigo_voo()
                 << ", Assento: " << reservaPtr->getNumero_assento() << endl;
        }
    }

    // Solicita os detalhes da reserva para baixa
    cout << "Informe o código do voo da reserva a ser cancelada: ";
    cin >> codigo_voo;
    cout << "Informe o número do assento da reserva a ser cancelada: ";
    cin >> numero_assento;

    // Busca o voo correspondente
    auto vooIt = find_if(listaVoos.begin(), listaVoos.end(), [codigo_voo](const Voo& voo) {
        return voo.getCodigo_voo() == codigo_voo;
    });

    if (vooIt == listaVoos.end()) {
        cout << "Voo com código " << codigo_voo << " não encontrado.\n";
        return;
    }

    // Busca o assento correspondente no voo
    vector<Assento>& assentos = vooIt->getAssentos();
    auto assentoIt = find_if(assentos.begin(), assentos.end(), [numero_assento](const Assento& assento) {
        return assento.getNumero_assento() == numero_assento;
    });

    if (assentoIt == assentos.end()) {
        cout << "Assento " << numero_assento << " não encontrado no voo " << codigo_voo << ".\n";
        return;
    }

    // Libera o assento
    if (!assentoIt->getStatus()) { // Assento estava reservado
        assentoIt->setStatus(true); // Libera o assento
        cout << "Assento " << numero_assento << " foi liberado.\n";
    } else {
        cout << "Assento " << numero_assento << " já estava livre.\n";
    }

    // Calcula o valor a ser pago com base na tarifa do voo
    double tarifa = vooIt->getTarifa(); // Supondo que exista um método getTarifa no Voo
    cout << "Tarifa do voo: R$ " << tarifa << endl;
    cout << "Valor total a ser pago: R$ " << tarifa << endl;

    // Remove a reserva do passageiro
    auto reservaIt = find_if(reservas.begin(), reservas.end(), [codigo_voo, numero_assento](const std::shared_ptr<Reserva>& reservaPtr) {
        return reservaPtr->getCodigo_voo() == codigo_voo && reservaPtr->getNumero_assento() == numero_assento;
    });

    if (reservaIt != reservas.end()) {
        reservas.erase(reservaIt); // Remove a reserva
        cout << "Reserva removida com sucesso.\n";
    } else {
        cout << "Reserva não encontrada no passageiro.\n";
    }
}

void Passageiro::imprimirReservas(vector <Voo*>& listaVoos) const{
    if (reservas.empty()) {
        cout << "O passageiro não possui reservas.\n";
        return;
    }

    cout << "\nReservas do passageiro:\n";
    for (const auto& reservaPtr : reservas) {
        if (reservaPtr) { // Verifica se o ponteiro não é nulo
            reservaPtr->imprimirReserva(listaVoos, this);
        }
    }
}

void Passageiro::salvarTexto(ofstream& out) const {
    if (!out.is_open()) {
        cerr << "Erro ao abrir arquivo para salvar Passageiro.\n";
        return;
    }

    // Salvar dados básicos em texto
    out << nome << endl;          // Salva o nome
    out << telefone << endl;      // Salva o telefone
    out << endereco << endl;      // Salva o endereço
    out << neymar << endl;        // Salva o neymar (se for um número, pode ser tratado como int ou bool)
    out << pontosFidelidade << endl;  // Salva os pontos de fidelidade

    // Salvar reservas
    out << reservas.size() << endl;  // Escreve o número de reservas
    for (const auto& reserva : reservas) {
        reserva->salvarTexto(out);  // Certifique-se de que `Reserva` também tenha esse método para salvar em texto
    }
}

void Passageiro::salvarPassageiros(const vector<Passageiro>& passageiros, const string& arquivo) {
    ofstream out(arquivo);
    if (!out) {
        cerr << "Erro ao abrir arquivo para salvar passageiros.\n";
        return;
    }

    out << passageiros.size() << endl;  // Escreve o total de passageiros
    for (const auto& passageiro : passageiros) {
        passageiro.salvarTexto(out);
    }

    out.close();
}

vector<Passageiro> Passageiro::carregarPassageiros(const string& arquivo) {
    ifstream in(arquivo);
    if (!in) {
        cerr << "Erro ao abrir arquivo para carregar passageiros.\n";
        return {};
    }

    size_t total;
    in >> total;  // Lê o número de passageiros
    in.ignore();  // Ignora o caractere de nova linha após o número

    vector<Passageiro> passageiros(total);
    for (auto& passageiro : passageiros) {
        passageiro.carregarTexto(in);  // Certifique-se de que `Passageiro` tenha o método `carregarTexto` para carregar de texto
    }

    in.close();
    cout << "Passageiros carregados com sucesso!" << endl;
    return passageiros;
}

void Passageiro::carregarTexto(ifstream& in) {
    if (!in.is_open()) {
        cerr << "Erro ao abrir arquivo para carregar Passageiro.\n";
        return;
    }

    // Carregar dados básicos do Passageiro
    getline(in, nome);             // Lê o nome
    getline(in, telefone);         // Lê o telefone
    getline(in, endereco);         // Lê o endereço
    in >> neymar;                  // Lê o valor de neymar (exemplo de tipo numérico ou booleano)
    in >> pontosFidelidade;        // Lê os pontos de fidelidade
    in.ignore();                   // Para ignorar o caractere de nova linha após os valores numéricos

    // Carregar reservas
    size_t totalReservas;
    in >> totalReservas;           // Lê o número de reservas
    in.ignore();                   // Ignora o caractere de nova linha após o número

    reservas.clear();              // Limpa as reservas existentes
    for (size_t i = 0; i < totalReservas; ++i) {
        auto novaReserva = std::make_shared<Reserva>(); // Cria um novo shared_ptr
        novaReserva->carregarTexto(in);  // Carrega a reserva a partir do arquivo
        reservas.push_back(novaReserva); // Adiciona a reserva ao vetor
    }
}