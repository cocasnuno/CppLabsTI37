/**
 * Conversor cambial EUR<->USD. 
 * Exibe um menu com as opções em baixo indicadas.
 *
 *    $ prog.exe
 *
 *    Escolha o sentido da conversão
 *    1. Euros -> Dólares
 *    2. Dólares -> Euros
 *    > 2
 *
 *    Montante em dólares: 2000
 *    Euros -> 1851.85
 *
 *    Pretende efectuar mais conversões (S/N)? n
 *    Fim do programa...
 *
 *    $
 * -------------------------
 * V4:
 *  a) Função confirma
 */

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using money = boost::multiprecision::cpp_dec_float_50;


bool confirma(string pergunta) {
    while (true) {
        cout << pergunta;
        string opcao_repetir;
        cin >> opcao_repetir;
        if (opcao_repetir == "n"   || 
            opcao_repetir == "nao" || 
            opcao_repetir == "N"   ||
            opcao_repetir == "NAO"
        ) {
            return false;
        }
        else if (
            opcao_repetir == "s"   || 
            opcao_repetir == "sim" ||
            opcao_repetir == "S"   || 
            opcao_repetir == "SIM"
        ) {
            return true;
        }
        else {
            cout << "Opção inválida! Introduza apenas (S)im ou (N)ão.\n";
        }
    }
}

int main() {
    money cambio("1.1459");    // em 30/03/2026

    cout.precision(2);
    cout.setf(ios_base::fixed);

    while (true) {
        // 1. Exibir opções do menu
        cout << "Escolha o sentido da conversão\n";
        cout << "1. Euros -> Dólares\n";
        cout << "2. Dólares -> Euros\n";

        // 2. Ler opção introduzida pelo utilizador
        cout << "> ";
        string opcao;
        cin >> opcao;

        // 3. (Analisar e) Executar a opção introduzida
        if (opcao == "1") {
            cout << "Montante em euros: ";
            money euros;
            cin >> euros;
            cout << "Dólares -> " << euros * cambio << '\n';
        }
        else if (opcao == "2") {
            cout << "Montante em dólares: ";
            money dolares;
            cin >> dolares;
            cout << "Euros -> " << dolares / cambio << '\n';
        }
        else {
            cout << "Opção <" << opcao << "> inválida!\n";
        }

        // 4. Deseja continuar ou não?
        if ( !confirma("Deseja efectuar mais conversões (S/N) ? ")) {
            cout << "O programa vai terminar...\n";
            break;
        }

        // em alternativa
        // bool respondeu_sim = confirma("Deseja efectuar mais conversões (S/N) ? ");
        // if ( !respondeu_sim) {
        //     cout << "O programa vai terminar...\n";
        //     break;
        // }
    }
}


/*
else if (opcao == "T" || opcao == "t" || opcao == "F" || opcao == "f") {
    cout << "O programa vai terminar...\n";
    break;
}
*/



// FUNÇÃO:
//      Bloco de código com nome, lista de parâmetros e tipo de dados.
//      Este bloco de código pode ser reutilizado através do nome.
//      Uma função permite reaproveitar funcionalidade e evita duplicação
//      de código.
//      As funções encorajam um estilo de desenvolvimento baseado na 
//      estratégia "dividir-para-conquistar".
// 
// DEFINIÇÃO DE FUNÇÃO:
//
//      TIPO_DADOS NOME_DA_FUNCAO(TIPO_DADOS PARAM1, TIPO_DADOS PARAM2, ...) {
//          INST1;
//          INST2;
//          ...
//          INST_N;
//      }
//
//      Exemplo: função que recebe um valor double e devolve o dobro desse valor.
//
//          double dobro(double valor) {
//              double resultado = 2 *  valor;
//              return resultado;
//          }
//
//      OU, DEFINIÇÃO MAIS COMPACTA:
//
//          double dobro(double valor) {
//              return 2 * valor;
//          }
//
// UTILIZAÇÃO DA FUNÇÃO:
//
//      NOME_DA_FUNCAO(ARG1, ARG2, ...)
//
//      Exemplo: calcular e exibir o dobro de um valor utilizando a função 'dobro':
//
//          cout << dobro(3);       // exibe 6
//          double x = 4.8;
//          double y = dobro(x);
//          cout << y;              // exibe 9.6
//
