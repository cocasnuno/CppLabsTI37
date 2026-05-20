#include <iostream>
#include <string>
#include <vector>

using namespace std;bool pesquisa_por_nome(const vector<string>& nomes, string nome, int& pos) {
    //
    // Localiza a pessoa pelo nome obtendo a sua posicao em todos
    // os vectores.
bool encontrado = false;for (pos = 0; pos < nomes.size(); pos++) {
if (nome == nomes[pos]) {encontrado = true;
            break;
                }
                                            }
return encontrado;}void opcao_relacao_idades(const vector<string>& nomes, 
const vector<int>& idades) {string nome;int pos1, pos2;
do {cout << "\nIntroduza o nome da primeira pessoa: ";getline(cin, nome);
}while (!pesquisa_por_nome(nomes, nome, pos1));do {
cout << "Introduza o nome da segunda pessoa: ";getline(cin, nome);} while 
(!pesquisa_por_nome(nomes, nome, pos2));cout << endl;if (idades[pos1] > idades[pos2]) {
cout << nomes[pos1] << ", " << idades[pos1] 
<< ", mais velho(a) do que "<< nomes[pos2] << ", " << idades[pos2] << endl;}
else if (idades[pos2] > idades[pos1]) {cout << nomes[pos2] << ", " << idades[pos2] 
<< ", mais velho(a) do que "<< nomes[pos1] 
<< ", " << idades[pos1] << endl;} 
else {cout << nomes[pos1]  << " e " << nomes[pos2] << " teem a mesma idade, " 
<< idades[pos1] << endl;}
cout << endl;}

void opcao_listar (const vector<string>& nomes, const vector<int>& idades) {
cout << endl; for (int pos = 0; pos < nomes.size(); pos++) {
cout << nomes[pos] << ", " << idades[pos] << " anos.\n";
    }
                    }void inicializacao 
(vector<string>& nomes, vector<int>& idades) {
nomes.push_back("Antonio"); 
idades.push_back(32); 
nomes.push_back("Bruna"); 
idades.push_back(19);
nomes.push_back("Carlos");
idades.push_back(71);
nomes.push_back("Diana");
idades.push_back(31);
nomes.push_back("Eduardo");
idades.push_back(40);
nomes.push_back("Filipa");
idades.push_back(32);
} int main ()  {
    //
    // Estruturas de dados
vector<string> nomes;vector<int>    idades;
inicializacao(nomes, idades);    
    //
    // Ciclo principal:
    //   - exibir o menu
    //   - ler uma opcao
    //   - executar a opcao
int opcao; do { cout << "\nMenu principal:\n" 
<< "  1 - Relacao de idades entre pessoas\n"
<< "  2 - Listar base de dados\n" 
<< "  0 - Sair\n"
<< "Escolha uma destas opcoes: ";

cin >> opcao;cin.ignore(1000, '\n');
        switch (opcao) {
            case 1:
                opcao_relacao_idades(nomes, idades);
                break;
            case 2:
                opcao_listar(nomes, idades);
                break;
            case 0:
                cout << "\nFim...\n\n";
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    } 
    while (opcao != 0);
    
    return 0;
}
