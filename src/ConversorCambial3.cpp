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
 * V3:
 *  a) Opção terminar sai do menu
 *  b) Confirmar se pretende mais conversões.
 */

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using money = boost::multiprecision::cpp_dec_float_50;

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
        while (true) {
            cout << "Deseja efectuar mais conversões (S/N) ? ";
            string opcao_repetir;
            cin >> opcao_repetir;
            if (opcao_repetir == "n") {
                cout << "O programa vai terminar...\n";
                return 0;
            }
            else if (opcao_repetir == "s") {
                break;
            }
            else {
                cout << "Opção inválida! Introduza apenas (S)im ou (N)ão.\n";
            }
        }
    }
}


/*
else if (opcao == "T" || opcao == "t" || opcao == "F" || opcao == "f") {
    cout << "O programa vai terminar...\n";
    break;
}
*/



