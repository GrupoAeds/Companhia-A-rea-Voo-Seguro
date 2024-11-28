#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Pessoa {
    protected:
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

        string getTelefone() const{
            return telefone;
        }

        void setNome(const string& nome) {
            this->nome = nome;
        }

        string getNome() const{
            return nome;
        }

        int getCodigo() const{
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
        vector<Reserva> reservas;

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

        bool getNeymar() const{
            return neymar;
        }

        void setPontosFidelidade(const int &pontosFidelidade) {
            this->pontosFidelidade = pontosFidelidade;
        }

        int getPontosFidelidade() const{
            return pontosFidelidade;
        }

        void setEndereco(const string &endereco) {
            this->endereco = endereco;
        }

        string getEndereco() const{
            return endereco;
        }

        vector<Reserva> getReservas() const{
            return reservas;
        }
        void adicionarPontos(int pontosAdicionados) {
            if (neymar) {
                pontosFidelidade += pontosAdicionados;
            }
        }

        void mostrarPontos() const{
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

// Agora vamos testar os métodos da classe "Pessoa".

//Classe "Pessoa"


// Os casos de teste para este método são: 

// O código deve ser único e positivo.
// O nome não pode estar vazio ou nulo.
// O telefone deve seguir um formato válido ( (XX) XXXXX-XXXX).
// O endereço não pode estar vazio.

//Código para teste:

// int main(){

    // Pessoa pessoa("João", "(31)998861895"); Para este caso, o código roda ok.
    // Pessoa pessoa("João", "(31998861895"); Para este caso também, pois o código pede que seja inserido o número de acordo com o formato cadastrado ( (XX) XXXXX-XXXX).
    // Pessoa pessoa("João", "31998861895"); //Se eu não insiro os "()", o programa me retorna o erro de formatação (OK), mas, se eu insiro 2 caracteres no lugar dos '()', exemplo 00, o programa não dá erro (Defeito).
    // Pessoa pessoa("", "(31)998861895"); //Neste código há um erro: Parametro “nome” está nulo e o código rodou.
    // Pessoa pessoa("(31)998861895"); Este código não roda sem o parametro “nome” estar pelo menos nulo (OK);

// }

// Método "CadastrarNovaPessoa": e imprimirInformações

//int main(){

    //Pessoa pessoa1 = pessoa1.cadastrarNovaPessoa();
    //pessoa1.imprimirInformacoes();

    //Pessoa pessoa2 = pessoa2.cadastrarNovaPessoa();
    //pessoa2.imprimirInformacoes();

    //Pessoa pessoa3 = pessoa3.cadastrarNovaPessoa();
    //pessoa3.imprimirInformacoes();

    // Para os códigos acima: 
    // Para começar a imprimir as orientações do cout, é necessário receber um valor antes (Enter, caracter...). (Defeito);
    // Os códigos criado estão vindo com o código diferente. Não há duplicação. (OK)
//}

// Método imprimirInformacoes:

//int main(){

   //Pessoa pessoa("", "(31)998861895");  
   //pessoa.imprimirInformacoes(); - Este método aceita o parâmetro "Nome" nulo e portanto imprime ele (Defeito) e os outros; 
                                        

  // Pessoa pessoa("","(31998861895");
  // Pessoa pessoa();
  // pessoa.imprimirInformacoes();        | O método roda sem o parâmetro "Telefone" estar no formato correto, mas imprime mensagem de erro de formatação(OK).

//}                                       | E também não aceita o objeto com parâmetros vazios.(OK);
//                                      | O método não mensagem de erro se o parâmetro "Nome" estiver nulo e o de "Telefone" estiver OK (Defeito - No parâmetro, no caso).


// Agora vamos testar os métodos da classe "Passageiro".

 //   int main(){

    //Passageiro passageiro("", "1119123456789","", -3,-15);
    //passageiro.imprimirInformacoes();
    
    // Para o código acima:

    // a classe herda os atributos da classe "Pessoa" e só adiciona outros atributos específicos, como "Endereço", "Plano de Fidelidade" e "Pontos de fidelidade". (OK)
    // O programa roda sem problema. Ele aceita números negativos (Defeito).
    // Com o parâmetro "Telefone "vazio, o programa dá pau, mas com ele nulo, o teste roda sem problema. (Defeito).
    // E o programa continua rodando sem erro com o parâmetro "Nome" nulo.(Defeito/Avaliar).
//}


// Metodo adicionarPontos

//int main(){

     // Passageiro passageiro("", "1119123456789","", -3,-15);
     // passageiro.adicionarPontos("1"); //Para este método, o código não roda com caracteres especiais ou letras, apenas números (OK).

//}


// Método mostrarPontos

//int main(){

    // Passageiro passageiro("", "1119123456789","", 0, 3);
    // passageiro.mostrarPontos();
    
    //Para este método:
    
    // O código mostra os pontos e não roda com caracteres especiais ou letras, não aceita parâmetro vazio ou char, apenas números. (OK);
    // O código recebe o valor de 3 pontos de fidelidade e os imprime, mesmo que o plano receba 0.  (Defeito).

//}


// Método cadastrarNovaPessoa e imprimirInformacoes()

//int main(){

    //Passageiro passageiro1 = passageiro1.cadastrarNovaPessoa();
    //passageiro1.imprimirInformacoes();

    //No código acima:
    
    // Ao digitar um valor diferente de 0 ou 1 (caracter, numero negativo..), o programa para de aceitar entradas e finaliza, imprimindo todo os outros textos;
    // Ao digitar o valor 0 para o plano de fidelidade, o programa ainda pede os pontos de fidelidade. O mesmo para os demais objetos criados (Defeito).
    // O código gera números de códigos diferentes para cada passageiro. (OK).

    //Passageiro passageiro2 = passageiro2.cadastrarNovaPessoa(); ""
    //passageiro2.imprimirInformacoes();  // Método OK, imprime tudo. ""

    //Passageiro passageiro3 = passageiro3.cadastrarNovaPessoa(); ""
    //passageiro3.imprimirInformacoes();  // Método OK, imprime tudo. ""
    
//}


// Agora vamos testar os métodos da classe "Tripulante".

//int main(){

    // Tripulante tripulante("Diogo","3100123456789", "Garçonete"); Para este caso, o código não aceitou o cargo "Garçonete". (OK)
    // Tripulante tripulante("Diogo","3100123456789", "Piloto"); Para este caso o código roda OK, e para o cargo "piloto" também. (OK)
    // Tripulante tripulante("Diogo","3100123456789", "copiloto"); Para este caso o código roda OK, e para o cargo "Copiloto" também. (OK)
    // Tripulante tripulante("Diogo","3100123456789", "comissario"); Para este caso o código roda OK, e para o cargo "Comissario" também.(ok)
    // Tripulante tripulante("Diogo","3100123456789", "COMISSARIO"); Para este caso, o código não aceita todas as maiusculas, e quando se coloca outra letra maiuscula além do "C", o código não reconhece o cargo. Ex: COmissario. E assim para todos os demais cargos também. (Defeito)
    // Tripulante tripulante("Diogo","3100123456789", ""); Para este caso, o código dá erro, pois o cargo está nulo (OK).
    // Tripulante tripulante("Diogo","3100123456789");Para este caso, o código dá erro, pois o parâmetro "Cargo" está vazio (OK).
    // Tripulante tripulante("Diogo","3100123456789", "Comissário"); Para este caso, o parâmetro "Cargo" não aceita o caracter "´" na letra "a", constando que o cargo não está correto. (Defeito)
//}

// Método cadastrarNovaPessoa e imprimirInformacoes()

//int main(){

    //Tripulante tripulante1 = tripulante1.cadastrarNovaPessoa();
    //tripulante1.imprimirInformacoes();

    //Tripulante tripulante2 = tripulante2.cadastrarNovaPessoa();
    //tripulante2.imprimirInformacoes();

    //Tripulante tripulante3 = tripulante3.cadastrarNovaPessoa();
    //tripulante3.imprimirInformacoes();

    // Para o método cadastrarNovaPessoa :

    // Para começar a imprimir as orientações do cout, é necessário receber um valor antes (Enter, caracter...). (Defeito);
    // Mesmo que eu insira o número de telefone inválido e/ou cargo inválido, ele apenas informa no final do processo (Defeito).

    // Para o método imprimirInformacoes:

    // O código está imprimindo as informações corretamente e os códigos criados estão vindo com códigos diferentes. Não há duplicação. (OK);

//}

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
    
class Reserva{
    private:
        int numero_assento, codigo_voo, codigo_passageiro;
        
    public:
        void setNumero_assento(int numero_assento) {
            this->numero_assento = numero_assento;
        }
        int getNumero_assento() const{
            return numero_assento;
        }

        void setCodigo_voo(int codigo_voo){
            this->codigo_voo = codigo_voo;
        }
        int getCodigo_voo() const{
            return codigo_voo;
        }

        void setCodigo_passageiro(int codigo_passageiro){
            this->codigo_passageiro = codigo_passageiro; 
        }
        int getCodigo_passageiro() const{
            return codigo_passageiro;
        }

        static void pesquisarPassageiroPorCodigo(int codigo, const vector<Passageiro>& passageiros) {
            for (const auto& passageiro : passageiros) {
                if (passageiro.getCodigo() == codigo) {
                    cout << "Passageiro encontrado:\n";
                     passageiro.imprimirInformacoes();
                    return;
                }
            }
             cout << "Passageiro não encontrado.\n";
        }

        static void pesquisarTripulantePorCodigo(int codigo, const vector<Tripulante>& tripulantes) {
            for (const auto& tripulante : tripulantes) {
                if (tripulante.getCodigo() == codigo) {
                    cout << "Tripulante encontrado:\n";
                    tripulante.imprimirInformacoes();
                    return; 
                }
            }
            cout << "Tripulante não encontrado.\n";
        }

        static void pesquisarVooPorCodigo(int codigo, const vector<Voo>& voos) {
            for (const auto& voo : voos) {
                if (voo.getCodigo_voo() == codigo) {
                    cout << "Voo encontrado:\n";
                    voo.exibirDados();
                    return; 
                }
            }
            cout << "Voo não encontrado.\n";
        }

        void imprimirReserva(const Passageiro& passageiro, const Voo& voo) const {
                cout << "\n=== Reserva ===\n";
                cout << "Nome do Passageiro: " << passageiro.getNome() << " (Código: " << passageiro.getCodigo() << ")\n";
                cout << "Origem: " << voo.getOrigem() << "\n";
                cout << "Destino: " << voo.getDestino() << "\n";
                cout << "Data: " << voo.getData() << "\n";
                cout << "Hora: " << voo.getHora() << "\n";
                cout << "Número do Assento: " << numero_assento << "\n";
                cout << "Tarifa: R$ " << voo.getTarifa() << endl;
        }

            void exibirReservasPassageiro(Passageiro passageiro, const vector<Voo>& voos) {
                if (passageiro.getReservas().empty()) {
                    cout << "O passageiro não fez nenhuma reserva" << endl;
                } else {
                    for (int i = 0; i < passageiro.getReservas().size(); i++) {
                        const Reserva& reserva = passageiro.getReservas()[i];

                        bool vooEncontrado = false;
                        for (const auto& voo : voos) {
                            if (reserva.getCodigo_voo() == voo.getCodigo_voo()) {
                                vooEncontrado = true;

                                imprimirReserva(passageiro, voo);
                                break;
                            }
                        }

                    }
                }
            }




};
// Inicializando membros estáticos
set<int> Voo::codigos_voo_usados;
set<int> Voo::codigos_aviao_usados;
set<int> Voo::codigos_piloto_usados;
set<int> Voo::codigos_comissario_usados;

int Pessoa::contadorCodigo = 0;
