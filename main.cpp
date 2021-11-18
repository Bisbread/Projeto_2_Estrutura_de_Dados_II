#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include "hash.h"
using namespace std;


int main(){

  struct spessoa{
  string nome;
  string sobrenome;
  };

  string nomeCompleto;
	string temp;
	ifstream arq("test.csv");
	int i, numPessoa = 0;

  int tam_vetor = 38000, ID = 0;
  int max = 19171;
  Hash alunohash(tam_vetor, max);

  string Name;

	spessoa pessoa[38000];
	if (arq.is_open()) {
		while (getline(arq, nomeCompleto) ) {
			temp = "";
			for (i = 0; i < nomeCompleto.size(); i++) {
				if (nomeCompleto[i] != ',') {
					temp = temp + nomeCompleto[i];
				} else {
					break;
				}
      }

			pessoa[numPessoa].nome = temp;
			temp = "";
			for (i = i+1; i < nomeCompleto.size(); i++) {
				temp = temp + nomeCompleto[i];
			}
			pessoa[numPessoa].sobrenome = temp;
      ID += 1;
      Aluno aluno(ID, temp);
      alunohash.inserir(aluno);
			numPessoa++;
		}
	} else {
		cout << "Arquivo inválido!";
	}
	arq.close();

  int opcao;
  int ra;
  string nome;
  bool busca;

  cout << "\n----------------------------------------------";
  cout << "\n              AUTORES DO CODIGO               ";
  cout << "\n----------------------------------------------";

  cout << "\n\n Nome: Gabriel Bispo dos Santos";
  cout << "\n TIA: 32016549";
  cout << "\n\n Nome: Guilherme Brito Rodrigues";
  cout << "\n TIA: 41929748";
  cout << "\n\n Nome: Lucas Lemos Kihara de Matos";
  cout << "\n TIA: 32042167";

  cout << "\n\n----------------------------------------------";
  cout << "\n               PROJETO HASH TABLE               ";
  cout <<"\n----------------------------------------------\n";

  cout << "\n FATOR DE CARGA: " << (float)max / (float)tam_vetor << endl;
  
  do {

    cout << "\n\n----------------------------------------------";
    cout << "\n                     MENU                     ";
    cout <<"\n----------------------------------------------\n";
    cout << " 0 - encerrar o programa!\n";
    cout << " 1 - inserir um dado!\n";
    cout << " 2 - remover um dado!\n";
    cout << " 3 - buscar um dado!\n";
    cout << " 4 - imprimir a Hash Table!\n";
    cout << "\nEscolha: ";
    cin >> opcao;

    if (opcao == 1){
      cout << "Qual e o ID do jogador?\n";
      cout << "ID: ";
      cin >> ra;
      cout << "Digite os dados correspondentes as outras 9 colunas separado por virgulas\n";
      cout << "Dados: ";
      cin >> nome;
      Aluno aluno(ra, nome);
      alunohash.inserir(aluno);
      } else if (opcao == 2){
        cout << "Qual e o ID do jogador a ser removido?\n";
        cout << "ID: ";
        cin >> ra;
        Aluno aluno(ra, " ");
        alunohash.deletar(aluno);
      } else if (opcao == 3){
        cout << "Qual e o ID do jogador a ser buscado?\n";
        cout << "ID: ";
        cin >> ra;
        Aluno aluno(ra, " ");
          alunohash.buscar(aluno, busca);
          if (busca){
            cout << "Jogador encontrado:\n";
            cout << "ID: " << aluno.obterID() << endl;
            cout << "Nome: " << aluno.obterName() << endl;
          } else{
            cout << "Jogador nao encontrado!\n";
          }
      } else if (opcao == 4){
          alunohash.imprimir();
      }

    } while (opcao != 0);


    return(0);
}   

