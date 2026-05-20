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
 * V2:
 *  a) Ciclo WHILE(TRUE) c/ BREAK
 *  b) Conversões implementadas
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

    while (true) {      // OU  for(;;) {
        // 1. Exibir opções do menu
        cout << "Escolha o sentido da conversão\n";
        cout << "1. Euros -> Dólares\n";
        cout << "2. Dólares -> Euros\n";
        cout << "T. Terminar\n";

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
        else if (opcao == "T" || opcao == "t" || opcao == "F" || opcao == "f") {
            cout << "O programa vai terminar...\n";
            break;
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