/**
 * Conversor cambial EUR<->USD. 
 * Exibe um menu com as opções em baixo indicadas.
 *
 *    $ prog.exe
 *
 *    Escolha o sentido da conversão
 *    1. Euros -> Dólares
 *    2. Dólares -> Euros
 *    T. Terminar
 *    > 2
 *
 *    Montante em dólares: 2000
 *    Euros -> 1851.85
 *
 *    Escolha o sentido da conversao
 *    1. Euros -> Dolares
 *    2. Dólares -> Euros
 *    T. Terminar
 *    > T
 *
 *    $
 * -------------------------
 * V1:
 *  a) Primeira versão
 *  b) Ciclo WHILE com condição explícita para continuar
 */

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using money = boost::multiprecision::cpp_dec_float_50;

int main() {
    money cambio("1.1459");    // em 30/03/2026

    cout.precision(20);
    cout.setf(ios_base::fixed);

    string opcao;
    while (opcao != "T" && opcao != "t") {
        // 1. Exibir opções do menu
        cout << "Escolha o sentido da conversão\n";
        cout << "1. Euros -> Dolares\n";
        cout << "2. Dólares -> Euros\n";
        cout << "T. Terminar\n";

        // 2. Ler opção introduzida pelo utilizador
        cout << "> ";
        cin >> opcao;

        // 3. (Analisar e) Executar a opção introduzida
        if (opcao == "1") {
            cout << "EUROS -> DÓLARES\n";
        }
        else if (opcao == "2") {
            cout << "DÓLARES -> EUROS\n";
        }
        else if (opcao == "T" || opcao == "t") {
            cout << "O programa vai terminar...\n";
        }
        else {
            cout << "Opção <" << opcao << "> inválida!\n";
        }
    }
}

// GRAVAR!!!!!!

/*

while (OPCAO != TERMINAR PROGRAMA) {
    1. Exibir opções do menu
    2. Ler opção introduzida pelo utilizador
    3. (Analisar e) Executar a opção introduzida
}

while (true) {
    1. Exibir opções do menu
    2. Ler opção introduzida pelo utilizador
    3. (Analisar e) Executar a opção introduzida
        => Terminar programa se opção introduzida for para terminar
           (break)
}

 */