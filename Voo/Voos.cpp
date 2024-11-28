#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Pessoa {
    private:
        string nome, telefone;
        int codigo;
        static int contadorCodigo;

    public:
        Pessoa(string nome, string telefone) {
            setNome(nome);
            setTelefone(telefone);
            codigo = ++contadorCodigo;
        }

        void setTelefone(const string& telefone) {
            if (telefone.size() == 13) {
                this->telefone = telefone;
            } else {
                cout << "Telefone inválido! Certifique-se de que tenha 11 números e esteja no formato correto (XX)XXXXXXXXXXX.\n";
            }
        }

        string getTelefone() {
            return telefone;
        }

        void setNome(const string& nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        int getCodigo() {
            return codigo;
        }

        static Pessoa cadastrarNovaPessoa() {
            cin.ignore();
            string nome, telefone;
            cout << "Informe os dados da pessoa\nNome: ";
            getline(cin, nome);
            cout << "Telefone: ";
            getline(cin, telefone);
            Pessoa pessoa(nome, telefone);
            return pessoa;
        }

        virtual void imprimirInformacoes() const {
            cout << "Nome: " << nome << ", Telefone: " << telefone << ", Código: " << codigo << endl;
        }
};

class Passageiro : public Pessoa {
    private:
        bool neymar;
        int pontosFidelidade;
        string endereco;

    public:
        Passageiro(string nome, string telefone, string endereco, bool neymar, int pontosFidelidade)
            : Pessoa(nome, telefone) {
            setEndereco(endereco);
            setNeymar(neymar);
            setPontosFidelidade(pontosFidelidade);
        }

        void setNeymar(const bool &neymar) {
            this->neymar = neymar;
        }

        bool getNeymar() {
            return neymar;
        }

        void setPontosFidelidade(const int &pontosFidelidade) {
            this->pontosFidelidade = pontosFidelidade;
        }

        int getPontosFidelidade() {
            return pontosFidelidade;
        }

        void setEndereco(const string &endereco) {
            this->endereco = endereco;
        }

        string getEndereco() {
            return endereco;
        }

        void adicionarPontos(int pontosAdicionados) {
            if (neymar) {
                pontosFidelidade += pontosAdicionados;
            }
        }

        void mostrarPontos() {
            cout << "Pontos de fidelidade: " << pontosFidelidade << endl;
        }

        static Passageiro cadastrarNovaPessoa() {
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
            cout << "Pontos de fidelidade iniciais: ";
            cin >> pontosFidelidade;
            cout << endl;
            cin.ignore();
            Passageiro passageiro(nome, telefone, endereco, neymar, pontosFidelidade);
            return passageiro;
        }

        void imprimirInformacoes() const override {
            Pessoa::imprimirInformacoes();
            cout << "Endereço: " << endereco << ", Possui o plano fidelidade: " << (neymar ? "Sim" : "Não") << ", Pontos de Fidelidade: " << pontosFidelidade << endl;
        }
};

class Tripulante : public Pessoa {
    private:
        string cargo;

    public:
        Tripulante(string nome, string telefone, string cargo)
        : Pessoa(nome, telefone) {
            setCargo(cargo);
        }

        void setCargo(const string& Novocargo){  // metodo para validar se o cargo informado eh valido 
            if(Novocargo=="Piloto"|| Novocargo=="piloto" || Novocargo=="Copiloto"|| Novocargo=="copiloto" || Novocargo=="Comissario" || Novocargo=="comissario"){
                cargo=Novocargo;
            } else {
                cout<<"O cargo informado nao eh valido, por favor informe o cargo correto"<<endl;
            }
        }
        string getCargo() const {
            return cargo;
        }

        static Tripulante cadastrarNovaPessoa() {
            string nome, telefone, cargo;
            cin.ignore();
            cout << "Informe os dados do tripulante \nNome: ";
            getline(cin, nome);
            cout << "Telefone: ";
            getline(cin, telefone);
            cout << "Cargo (Piloto, Copiloto, Comissario): ";
            getline(cin, cargo);
            Tripulante tripulante(nome, telefone, cargo);
            return tripulante;
        }

        void imprimirInformacoes() const override {
            Pessoa::imprimirInformacoes();
            cout << "Cargo: " << cargo << endl;
        }
};

class Voo {
private:
    int codigo_voo;
    string data;
    string hora;
    string origem;
    string destino;
    int codigo_aviao;
    int codigo_piloto;
    int codigo_copiloto;
    int codigo_comissario;
    string status;
    float tarifa;

    vector<Assento> assentos; // Associação com a classe Assento
    static set<int> codigos_voo_usados;
    static set<int> codigos_aviao_usados;
    static set<int> codigos_piloto_usados;
    static set<int> codigos_comissario_usados;

    // Função auxiliar para validar códigos únicos
    bool validarCodigoUnico(int codigo, set<int>& conjunto, const string& nome) {
        if (conjunto.count(codigo)) {
            cout << "Erro: Código de " << nome << " já utilizado. Tente novamente.\n";
            return false;
        }
        conjunto.insert(codigo);
        return true;
    }

public:
    // Construtor
    Voo() : codigo_voo(0), tarifa(0.0), status("Inativo") {}

    // Setters com validações
    void setCodigo_voo(int cv) {
        if (validarCodigoUnico(cv, codigos_voo_usados, "voo")) {
            codigo_voo = cv;
        }
    }

    void setCodigo_aviao(int ca) {
        if (validarCodigoUnico(ca, codigos_aviao_usados, "avião")) {
            codigo_aviao = ca;
        }
    }

    void setCodigo_piloto(int cp) {
        if (validarCodigoUnico(cp, codigos_piloto_usados, "piloto")) {
            codigo_piloto = cp;
        }
    }

    void setCodigo_copiloto(int cc) {
        if (cc == codigo_piloto) {
            cout << "Erro: Copiloto não pode ser o mesmo que o piloto. Tente novamente.\n";
        } else {
            codigo_copiloto = cc;
        }
    }

    void setCodigo_comissario(int comissario) {
        if (validarCodigoUnico(comissario, codigos_comissario_usados, "comissário")) {
            codigo_comissario = comissario;
        }
    }

    void setOrigem(const string& o) {
        origem = o;
    }

    void setDestino(const string& d) {
        destino = d;
    }

    void setStatus(const string& s) {
        if (s == "Ativo" || s == "Inativo") {
            status = s;
        } else {
            cout << "Erro: Status inválido. O status deve ser 'Ativo' ou 'Inativo'.\n";
        }
    }

    void setTarifa(float t) {
        tarifa = t;
    }

    void setData(const string& d) {
        // Validação simplificada para exemplo
        if (d.length() == 8 && d[2] == '/' && d[5] == '/') {
            data = d;
        } else {
            cout << "Erro: Data inválida. Use o formato dd/mm/aa.\n";
        }
    }

    void setHora(const string& h) {
        // Validação simplificada para exemplo
        if (h.length() == 5 && h[2] == ':') {
            hora = h;
        } else {
            cout << "Erro: Hora inválida. Use o formato hh:mm.\n";
        }
    }

    // Getters
    int getCodigo_voo() const { return codigo_voo; }
    int getCodigo_aviao() const { return codigo_aviao; }
    int getCodigo_piloto() const { return codigo_piloto; }
    int getCodigo_copiloto() const { return codigo_copiloto; }
    int getCodigo_comissario() const { return codigo_comissario; }
    string getOrigem() const { return origem; }
    string getDestino() const { return destino; }
    string getData() const { return data; }
    string getHora() const { return hora; }
    float getTarifa() const { return tarifa; }
    string getStatus() const { return status; }

    // Métodos de cadastro e exibição
    void cadastro_voo() {
        cout << "------------- CADASTRO DE VOO ----------\n";

        int temp;
        cout << "Digite o código do voo: ";
        cin >> temp;
        setCodigo_voo(temp);

        cout << "Digite o código do avião: ";
        cin >> temp;
        setCodigo_aviao(temp);

        cout << "Digite o código do piloto: ";
        cin >> temp;
        setCodigo_piloto(temp);

        cout << "Digite o código do copiloto: ";
        cin >> temp;
        setCodigo_copiloto(temp);

        cout << "Digite o código do comissário: ";
        cin >> temp;
        setCodigo_comissario(temp);

        cout << "Digite a data (dd/mm/aa): ";
        string tempStr;
        cin >> tempStr;
        setData(tempStr);

        cout << "Digite a hora do voo (hh:mm): ";
        cin >> tempStr;
        setHora(tempStr);

        cout << "Digite a origem: ";
        cin.ignore();
        getline(cin, origem);

        cout << "Digite o destino: ";
        getline(cin, destino);

        cout << "Digite o status (Ativo/Inativo): ";
        getline(cin, tempStr);
        setStatus(tempStr);

        cout << "Digite a tarifa: ";
        cin >> tarifa;
    }

    void exibirDados() const {
        cout << "\n=== Dados do Voo ===\n";
        cout << "Código do Voo: " << codigo_voo << "\n"
             << "Código do Avião: " << codigo_aviao << "\n"
             << "Código do Piloto: " << codigo_piloto << "\n"
             << "Código do Copiloto: " << codigo_copiloto << "\n"
             << "Código do Comissário: " << codigo_comissario << "\n"
             << "Data: " << data << "\n"
             << "Hora: " << hora << "\n"
             << "Origem: " << origem << "\n"
             << "Destino: " << destino << "\n"
             << "Tarifa: " << tarifa << "\n"
             << "Status: " << status << "\n";
    }

    // Métodos para gerenciar os assentos
    void adicionarAssento(const Assento& assento) {
        assentos.push_back(assento);
        cout << "Assento " << assento.getNumero() << " adicionado ao voo.\n";
    }

    void exibirAssentos() const {
        if (assentos.empty()) {
            cout << "Nenhum assento cadastrado para este voo.\n";
            return;
        }
        cout << "\n=== Assentos do Voo ===\n";
        for (const auto& assento : assentos) {
            assento.exibirDados();
        }
    }

    vector<Assento> getAssentos() const {
        return assentos;
    }
};

// Inicializando membros estáticos
set<int> Voo::codigos_voo_usados;
set<int> Voo::codigos_aviao_usados;
set<int> Voo::codigos_piloto_usados;
set<int> Voo::codigos_comissario_usados;

int Pessoa::contadorCodigo = 0;
