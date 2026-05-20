/**
 * TPC: Acrescentar a ConversortTemperaturas1.cpp a conversão de Celsius 
 * para Kelvin (CK) e de Fahrenheit para Kelvin (FK)
 */

 #include <iostream>
 #include <string>
 #include <cstdlib>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using temperature = boost::multiprecision::cpp_dec_float_50;

/*
 * Declarações de funções
 */

bool confirma(string pergunta);
char para_maiuscula(char ch);
string para_maiuscula(string ch);
char para_minuscula(char ch);
string para_minuscula(string ch);
void clear_screen();

/*
 * Definicões
 */

int main() {
    // auto ZERO_CELSIUS_IN_KELVIN = temperature("273.15");
    temperature ZERO_CELSIUS_IN_KELVIN("273.15");

    cout.precision(2);
    cout.setf(ios_base::fixed);

    while (true) {
        // 1. Exibir opções do menu
        clear_screen();
        cout << "Escolha a conversão:\n";
        cout << "    C. Converter de Celsius para Fahrenheit\n";
        cout << "    F. Converter de Fahrenheit para Celsius\n";
        cout << "    KC. Converter de Kelvin para Celsius\n";
        cout << "    KF. Converter de Kelvin para Fahrenheit\n";
        cout << "    CK. Converter de Celsius para Kelvin\n";
        cout << "    FK. Converter de Fahrenheit para Kelvin\n";

        // 2. Ler opção introduzida pelo utilizador
        cout << "Opcao> ";
        string opcao;
        cin >> opcao;
        opcao = para_maiuscula(opcao);

        cout << endl;

        // 3. (Analisar e) Executar a opção introduzida
        if (opcao == "C") {
            cout << "Temperatura em Celsius: ";
            temperature celsius;
            cin >> celsius;
            temperature fahr = celsius * 9/5 + 32;
            cout << "Temperatura em Fahrenheit: " << fahr << '\n';
        }
        else if (opcao == "F") {
            cout << "Temperatura em Fahrenheit: ";
            temperature fahr;
            cin >> fahr;
            temperature celsius = (fahr - 32) * 5/9;
            cout << "Temperatura em Celsius: " << celsius << '\n';
        }
        else if (opcao == "KC") {
            cout << "Temperatura em Kelvin: ";
            temperature kelvin;
            cin >> kelvin;
            temperature celsius = kelvin - ZERO_CELSIUS_IN_KELVIN;
            cout << "Temperatura em Celsius: " << celsius << '\n';
            
        }
        else if (opcao == "KF") {
            cout << "Temperatura em Kelvin: ";
            temperature kelvin;
            cin >> kelvin;
            temperature celsius = kelvin - ZERO_CELSIUS_IN_KELVIN;
            temperature fahr = celsius * 9/5 + 32;
            cout << "Temperatura em Fahrenheit: " << fahr << '\n';
            
        }
        else {
            cout << "Opção <" << opcao << "> inválida!\n";
        }

        cout << endl;

        // 4. Deseja continuar ou não?
        if ( confirma("Deseja terminar o programa? ")) {
            cout << "O programa vai terminar...\n";
            break;
        }
    }
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

/*
int x = 10;
int y = x + 1;
int z = 2 * y;

auto x = 10.0;     // Java:   var x = 10.0;
auto y = x + 1;
auto z = 2 * y;
 */