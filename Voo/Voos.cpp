#include <iostream>
#include <string>

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

int Pessoa::contadorCodigo = 0;