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
 * V5:
 *  a) Outras funções: clear_screen, pause, para_maiuscula, etc.
 *  b) Saída melhorada
 */

#include <iostream>
#include <string>
#include <cstdlib>    // como incluir "stdlib.h" em prog. de C++

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using money = boost::multiprecision::cpp_dec_float_50;

char para_maiuscula(char ch) {      // ch => character
    if (ch >= 'a' && ch <= 'z') {
        ch -= 32;
    }
    return ch;
}

string para_maiuscula(string str) {
    for (int i = 0; i < str.length(); i += 1) {
        str[i] = para_maiuscula(str[i]);
    }
    return str;
}

char para_minuscula(char ch) {      // ch => character
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;
    }
    return ch;
}

string para_minuscula(string str) {
    for (int i = 0; i < str.length(); i += 1) {
        str[i] = para_minuscula(str[i]);
    }
    return str;
}

bool confirma(string pergunta) {
    while (true) {
        cout << pergunta;
        string opcao_repetir;
        cin >> opcao_repetir;

        opcao_repetir = para_maiuscula(opcao_repetir);

        if (
            opcao_repetir == "N"   ||
            opcao_repetir == "NAO"
        ) {
            return false;
        }
        else if (
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

void clear_screen() {
#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
    system("clear");
#elif defined(_WIN32) 
    system("cls");
#endif
}

int main() {
    money cambio("1.1459");    // em 30/03/2026

    cout.precision(2);
    cout.setf(ios_base::fixed);

    while (true) {
        // 1. Exibir opções do menu
        clear_screen();
        cout << "Escolha o sentido da conversão\n";
        cout << "1. Euros -> Dólares\n";
        cout << "2. Dólares -> Euros\n";

        // 2. Ler opção introduzida pelo utilizador
        cout << "> ";
        string opcao;
        cin >> opcao;

        cout << endl;

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

        cout << endl;

        // 4. Deseja continuar ou não?
        if ( !confirma("Deseja efectuar mais conversões (S/N) ? ")) {
            cout << "O programa vai terminar...\n";
            break;
        }
    }
}


/*
  A -> 65        a -> 97
  B -> 66        b -> 98
  C -> 67        c -> 99
  ...
  Z -> 90        z -> 122

*/

/*
    char ch = 'a';
    cout << para_maiuscula(ch);     // A
    ch = 'p';

    char ch2 = para_maiuscula(ch);
    cout << ch2;                    // P

    cout << para_maiscula('f');     // F
    cout << para_maiscula('Y');     // Y
    cout << para_maiscula('7');     // 7
    cout << para_maiscula('$');     // $
    cout << para_maiscula('u');     // U
*/

/*
OVERLOADING DE FUNÇÕES => funções podem ter o mesmo nome desde
que tenham listas de parâmetros diferentes

    void fun(int x) {
        //...
    }

    void fun(double x) {
        //...
    }

    void fun(int x, string xpto) {
        //...
    }
*/

/*
    cout << str[   str.length() - 1  ];
    cout << str[   str.size() - 1  ];

    for (INICIALIZAÇÃO; CONDIÇÃO; ACTUALIZAÇÃO) {
        BLOCO_DE_INSTRUÇÕES
    }
*/
