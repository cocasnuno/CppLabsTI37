#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // 1) Indique duas formas de construir/declarar/definir uma string?
    string str1 = "ABC";
    string str2("ABC");
    string str3 = "ABC"s;

    // 2) Indique como definir uma string com dez símbolos '#'
    auto str4 = string(10, '#');
    cout << "str4 => " << str4 << endl;

    string xpto = "ABC XYZ DEF";
    cout << "___ XPTO => \"" << xpto << "\" ____" << endl;

    // 3.1) Obter o primeiro caractere
    cout << "3.1) " << xpto[0] << endl;
    cout << "3.1) " << xpto.at(0) << endl;

    // 3.2) Obter o último caractere
    cout << "3.2) " << xpto[xpto.length() - 1] << endl;
    cout << "3.2) " << xpto.back() << endl;

    // 3.3) Obter o penúltimo caractere
    cout << "3.3) " << xpto[xpto.length() - 2] << endl;

    // 3.4) Obter a posição do espaço 
    cout << "3.1) " << "Posição do espaço => " << xpto.find(' ') << endl;
        // NOTA: se o caractere não for encontrado então o método 
        // string::find devolve string::npos

    // 3.5) Obter a substring à direita do espaço
    auto pos_espaco = xpto.find(' ');
    if (pos_espaco != string::npos) {
        cout << "3.5) " << xpto.substr(pos_espaco + 1) << endl;
    }

    // 3.6) Obter uma substring com os caracteres compreendidos entre
    //     as posições 2 e 5 (inclusive).

    cout << "3.6) " << xpto.substr(2, 4) << endl;

    // 3.7) Obter a posição do segundo 'A'

    cout << "3.7) " << xpto.find('A', xpto.find('A') + 1) << endl;

    // 3.8) Confirmar que a substring "AXY" não existe na string XPTO
    if (xpto.find("AXY") == string::npos) {
        cout << "3.8) Não existe" << endl;
    }
    else {
        cout << "3.8) Afinal existe" << endl;
    }

    cout << "3.8) Existe? " << (xpto.find("AXY") != string::npos) << endl;

    // 3.9) Apagar a segunda ocorrência de "ABC"
    xpto = "ABC XYZ DEF ABC 123";
    auto pos_abc = xpto.find("ABC", xpto.find("ABC") + 1);
    cout << "3.9) " << xpto.erase(pos_abc, 3) << endl;

    // 3.10) Substituir a substring "DEF" por "XYZ"
    auto pos_def = xpto.find("DEF");
    cout << "3.10) " << xpto.replace(pos_def, 3, "XYZ") << endl;
}
