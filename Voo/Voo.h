#ifndef VOO_H
#define VOO_H
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;


struct Data{
    int ano;
    int mes;
    int dia;
};
struct Hora{
    int horas;
    int minutos;
};

class Assento;
class Tripulante;

class Voo {
    private:
        vector<Assento> assentos;
        int codigo_voo;
        Data data;
        Hora hora;
        string origem;
        string destino;
        int codigo_aviao;
        int codigo_piloto;
        int codigo_copiloto;
        int codigo_comissario;
        bool status;
        float tarifa;
        static int contadorCodigoVoo;

    public:
        // Construtor
        Voo(int codigo_aviao, int codigo_piloto, int codigo_copiloto, int codigo_comissario, Data data, Hora hora, string origem, string destino, bool status, double tarifa);

        int getCodigo_voo() const;

        void setCodigo_aviao(const int codigo_aviao);
        int getCodigo_aviao() const;

        void setCodigo_piloto(const int codigo_piloto);
        int getCodigo_piloto() const;

        void setCodigo_copiloto(const int codigo_copiloto);
        int getCodigo_copiloto() const;

        void setCodigo_comissario(const int codigo_comissario);
        int getCodigo_comissario() const;

        void setData(const Data& data);
        Data getData() const;

        void setHora(const Hora& hora);
        Hora getHora()const ;

        void setOrigem(const string& origem);
        string getOrigem() const;

        void setDestino(const string& destino);
        string getDestino() const;

        void setStatus(const bool status);
        bool getStatus() const;

        void setTarifa(const double tarifa);
        double getTarifa() const;

        vector<Assento>& getAssentos();
        
        static Voo cadastrarVoo(const vector<Tripulante>& tripulantes);

        void verificarStatus() const;

        void exibirInformacoes() const;

        void adicionarAssento(Assento& assento);

        void exibirAssentos() const;
    
};

#endif // VOO_H