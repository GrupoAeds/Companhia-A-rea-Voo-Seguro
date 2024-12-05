#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Voo;

class Assento{
    private:
        int numero_assento, codigo_voo;
        bool status;
        Voo* voo; 
    public:
        Assento();
        Assento(int numero_assento, int codigo_voo, bool status);

        void setNumero_assento(const int numero_assento);
        int getNumero_assento() const;

        void setCodigo_voo(const int codigo_voo);
        int getCodigo_voo() const;

        void setStatus(const bool status);
        bool getStatus() const;

        void verificarStatus() const;

        static Assento cadastrarAssento(const vector<Voo*>& voos);
        
        void exibirInformacoes() const;

        static void salvarAssentos(const vector<Assento>& assentos, const string& nomeArquivo);
        static vector<Assento> carregarAssentos(const string& nomeArquivo);
        void salvarTexto(ofstream& out) const;
        void carregarTexto(ifstream& in);
    
};



#endif // ASSENTO_H