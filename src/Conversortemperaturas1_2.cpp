#include <iostream>
#include <string>
#include <cstdlib>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using temperature = boost::multiprecision::cpp_dec_float_50;

char para_maiuscula(char ch) {
    if (ch >= 'a' && ch <= 'z') ch -= 32;
    return ch;
}

string para_maiuscula(string str) {
    for (size_t i = 0; i < str.length(); i += 1) {
        str[i] = para_maiuscula(str[i]);
    }
    return str;
}

bool confirma(string pergunta) {
    while (true) {
        cout << pergunta;
        string opcao_repetir;
        cin >> opcao_repetir;
        opcao_repetir = para_maiuscula(opcao_repetir);

        if (opcao_repetir == "N" || opcao_repetir == "NAO") return false;
        if (opcao_repetir == "S" || opcao_repetir == "SIM") return true;
        
        cout << "Opção inválida! Introduza apenas (S)im ou (N)ão.\n";
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
    // Definição de constantes com alta precisão
    const temperature ZERO_CELSIUS_IN_KELVIN("273.15");
    const temperature NOVE("9");
    const temperature CINCO("5");
    const temperature TRINTA_E_DOIS("32");

    cout.precision(2); // Altere aqui se quiser exibir mais casas decimais no ecrã
    cout.setf(ios_base::fixed);

    while (true) {
        clear_screen();
        cout << "Escolha a conversão:\n";
        cout << "    C. Converter de Celsius para Fahrenheit\n";
        cout << "    F. Converter de Fahrenheit para Celsius\n";
        cout << "    KC. Converter de Kelvin para Celsius\n";
        cout << "    KF. Converter de Kelvin para Fahrenheit\n";

        cout << "Opcao> ";
        string opcao;
        cin >> opcao;
        opcao = para_maiuscula(opcao);
        cout << endl;

        if (opcao == "C") {
            cout << "Temperatura em Celsius: ";
            temperature celsius;
            cin >> celsius;
            // Correção da fórmula usando os tipos precisos
            temperature fahr = (celsius * NOVE / CINCO) + TRINTA_E_DOIS;
            cout << "Temperatura em Fahrenheit: " << fahr << '\n';
        }
        else if (opcao == "F") {
            cout << "Temperatura em Fahrenheit: ";
            temperature fahr;
            cin >> fahr;
            // Correção da fórmula
            temperature celsius = (fahr - TRINTA_E_DOIS) * CINCO / NOVE;
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
            // Correção da fórmula
            temperature fahr = (celsius * NOVE / CINCO) + TRINTA_E_DOIS;
            cout << "Temperatura em Fahrenheit: " << fahr << '\n';
        }
        else {
            cout << "Opção <" << opcao << "> inválida!\n";
        }

        cout << endl;

        if (confirma("Deseja terminar o programa? ")) {
            cout << "O programa vai terminar...\n";
            break;
        }
    }
    return 0;
}