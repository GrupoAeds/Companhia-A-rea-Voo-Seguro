#include "Pessoa.h"
#include "Passageiro.h"
#include "Tripulante.h"
#include "Assento.h"
#include "Voo.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<Passageiro> passageiros;
    vector<Tripulante> tripulantes;
    vector<Voo> voos;
    vector<Assento> assentos;
    int escolha = 0;

    while(true){
        cout << "Seja bem vindo a Companhia Aérea Voo Seguro. O que seja?\n\n"
         << "1 - Cadastrar Passageiro\n"
         << "2 - Cadastrar Tripulação\n"
         << "3 - Cadastrar Voos\n"
         << "4 - Cadastrar Assentos\n"
         << "5 - Realizar uma reserva\n"
         << "6 - Realizar a baixa de uma reserva\n"
         << "7 - Sair\n";

        cin >> escolha;

        cin.ignore();

        if (cin.fail()) {
            cin.clear(); // Limpa o erro de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora o restante da linha
            cout << "Entrada inválida. Tente novamente.\n";
            continue;
        }

        switch (escolha){
            case 1:{
                Passageiro Individuo = Passageiro::cadastrarNovaPessoa();
                Individuo.imprimirInformacoes();
                passageiros.push_back(Individuo);
                break;
            }

            case 2: {
                Tripulante novoTripulante = Tripulante::cadastrarNovaPessoa();
                novoTripulante.imprimirInformacoes();
                tripulantes.push_back(novoTripulante);
            

                break;
            }

            case 3: {
                Voo novoVoo = Voo::cadastrarVoo(tripulantes);
                novoVoo.exibirInformacoes();
                voos.push_back(novoVoo);

                break;
            }

            case 4: {
                // Criando um vetor de ponteiros para os voos
                std::vector<Voo*> voosPtr;
                for (auto& voo : voos) {
                    voosPtr.push_back(&voo); // Adicionando o endereço de cada voo
                }

                // Passando o vetor de ponteiros para cadastrarAssento
                Assento novoAssento = Assento::cadastrarAssento(voosPtr);
                novoAssento.exibirInformacoes();
                assentos.push_back(novoAssento);

                break;
            }

            case 5: {
                int codigo_passageiro;
                cout << "Informe o código do passageiro para realizar a reserva: ";
                cin >> codigo_passageiro;

                // Busca o passageiro pelo código
                auto passageiroIt = find_if(passageiros.begin(), passageiros.end(), [codigo_passageiro](const Passageiro& passageiro) {
                    return passageiro.getCodigo() == codigo_passageiro;
                });

                if (passageiroIt != passageiros.end()) {
                    passageiroIt->reservar(voos);
                } else {
                    cout << "Passageiro não encontrado.\n";
                }
                break;
            }
            
            case 6:{
                int codigo_passageiro;
                cout << "Informe o código do passageiro para realizar fazer a baixa da reserva: ";
                cin >> codigo_passageiro;

                // Busca o passageiro pelo código
                auto passageiroIt = find_if(passageiros.begin(), passageiros.end(), [codigo_passageiro](const Passageiro& passageiro) {
                    return passageiro.getCodigo() == codigo_passageiro;
                });

                if (passageiroIt != passageiros.end()) {
                    passageiroIt->baixarReserva(voos);
                } else {
                    cout << "Passageiro não encontrado.\n";
                }
                break;
            }

            case 7:{
                cout << "Bye Bye!";
                return 0;
            }

            default:{
                cout << "Opção inválida";
            }
        }

    }
    
    return 1;
}

