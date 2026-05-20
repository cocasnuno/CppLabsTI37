/**
 * STRING é uma sequência de CHARs
 * 
 * ESTRUTURA DE DADOS  =>   Representação física de um tipo de dados, ou,
 *                          é a implementação de um tipo de dados.
 *                          Esta implementação abrange dois "aspectos":
 *                          1) estrutura em mémória   2) operações disponíveis
 *                                                       para manipular objectos
 *                                                       do tipo de dados.
 *
 *                          Porém, é mais comum utilizar o termo "estrutura de 
 *                          dados" como sinónimo de "colecção de elementos".
 *
 * COLECÇÃO DE ELEMENTOS    =>  "Conjunto" ou "grupo" de objectos que podem 
 * (COLLECTION ou CONTAINER)    ser ou não  do mesmo tipo de dados 
 *                              (tipicamente, são)
 *
 * COLECÇÕES TÍPICAS NA MAIORIA DAS LINGUAGENS:
 *
 *      1. SEQUÊNCIAS:  associação de posições a objectos; elementos estão por
 *                      por ordem (ou seja, sabemos qual é o 1o, qual é o 2o, etc.)
 *                      Tipicamente, temos operações para aceder aos elementos 
 *                      por posição, para obter o comprimento da sequência, 
 *                      para iterar a sequência por uma determinada ordem e pela
 *                      ordem inversa, etc.
 *
 *          1.1 STRINGS: Uma sequência de caracteres. Em C++, uma string é uma 
 *                       sequência de "objectos" do tipo CHAR (ou similar).
 *                       Temos dois tipos de string em C++:
 *                          1) strings herdadas da linguagem C
 *                          2) std::string
 *                          
 *          1.2 ARRAYS:
 *          1.3 VECTORES/LISTAS:
 *    
 *      2. MAPAS:   associação de qualquer coisa a qualquer coisa. Por exemplo,
 *                  podemos querer associar nomes a datas de nascimento.
 *
 *      3. CONJUNTOS "MATEMÁTICOS"/SETs: são conjuntos de elementos sem 
 *                  repetição, ou seja, não aceitam duplicados
 *
 *
 *  DOIS TIPOS DE FUNÇÃO EM C++ NO QUE TOCA À INVOCAÇÃO:
 *
 *  1. FUNCAO(ARG1, ARG2, ..., ARG_N)
 *     Exemplos:
 *          pow(2, 3)                 // devolve 2^3 == 8
 *          getline(cin, str);        // lê uma linha de texto para variável str
 *          system("cls");            // invocar um subprocesso/programa
 *
 * 2. ARG1.FUNCAO(ARG2, ..., ARG_N)     => estas funções designam-se também por
 *    Exemplos:                           "método" ou (em C++) "função membro";
 *          cin.get(ch);                   estas funções são executadas num 
 *          str.length();                   determinado contexto dado pelo ARG1
 * 
 *          char ch;
 *          cin.get(ch);              // lê caractere a partir do cin
 *          string xpto;
 *          getline(cin, xpto);
 *          cout << xpto.length()     // string.length() dá a dimensão da string
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;
// using namespace std::literals;

int main() {
    cout << "---------------------------------" << endl;
    cout << "CONSTRUÇÃO" << endl;
    cout << "---------------------------------" << endl;

    string nome = "Alberto";
    string nome2("Alberto");
    auto nome3 = "Alberto"s;        // var nome3 = "Alberto";
    // "ALBERTO"  ==> string de C
    // "ALBERTO"s ==> string de C++

    cout << nome << endl;
    cout << nome2 << endl;
    cout << nome3 << endl;

    string varios_tracos(40, '-');

    cout << varios_tracos << endl;
    cout << varios_tracos.length() << endl;

    string nome5 = "Armando";
    string nome6(nome5, 1, 3);
    cout << nome6 << endl;

    cout << "---------------------------------" << endl;
    cout << "DIMENSÃO E ACESSO" << endl;
    cout << "---------------------------------" << endl;

    cout << "Dimensão da string: " << nome.length() << endl;
    cout << "Dimensão da string: " << nome.size() << endl;
    cout << "Dimensão da string: " << "Hermenegilda"s.size() << endl;

    cout << "Primeiro caractere da string          : " << nome[0] << endl;
    cout << "Primeiro caractere da string (com at) : " << nome.at(0) << endl;
    cout << "Segundo caractere da string           : " << nome[1] << endl;
    cout << "Segundo caractere da string (com at)  : " << nome.at(1) << endl;

    // cout << "Caractere inexistente (70) da string          : " << nome[70] << endl;
    // cout << "Caractere inexistente (70) da string (com at) : " << nome.at(70) << endl;

    cout << "Último caractere da string            : " << nome[nome.length() - 1] << endl;
    auto pos_ultimo = nome.length() - 1;
    cout << "Último caractere da string (c/var)    : " << nome[pos_ultimo] << endl;
    cout << "Último caractere da string (c/back)   : " << nome.back() << endl;

    cout << "---------------------------------" << endl;
    cout << "OPERADORES (==, >, >=, etc.)" << endl;
    cout << "---------------------------------" << endl;

    string nome4 = "Armando";
    cout << "Os nomes são iguais? ";

    if (nome == nome4) {                // Java: if (nome.equals(nome4)) {...
        cout << " iguais" << endl;
    }
    else {
        cout << " diferentes" << endl;
    }

    cout << "O maior nome é: ";
    if (nome >= nome4) {         // "Alberto" >= "Albertina" ? true
        cout << nome;
    }
    else {
        cout << nome4;
    }
    cout << endl;

    cout << "---------------------------------" << endl;
    cout << "OPERADORES (+, +=)" << endl;
    cout << "---------------------------------" << endl;

    // nome => "ALBERTO"    nome2 => "ARMANDO"
    nome = "ALBERTO"s; nome2 = "ARMANDO"s;
    string apelido = "ANTUNES";
    string nome_completo = nome + " " + nome2 + " " + apelido;
    cout << "Nome completo: " << nome_completo << endl;

    string apelido2 = "ALMEIDA";
    nome_completo += " ";
    nome_completo += apelido2;
    cout << "Nome mesmo completo: " << nome_completo << endl;

    cout << "---------------------------------" << endl;
    cout << "CONVERTER int,double,etc p/ std::string e vice-versa" << endl;
    cout << "---------------------------------" << endl;

    /*
      // Java
      int quantidade = 30;
      ...
      String mensagem = "Quantidade livros: " + quantidade; 

      // C++

      cout << "Quantidade livros: " << quantidade;
      string mensagem = "Quantidade livros: " + quantidade;   ERRADO!!!
    */

    stringstream mensagem;
    int quantidade = 30;
    mensagem << "Quantidade de livros: " << quantidade;
    cout << mensagem.str() << endl;

    stringstream produtos("Leite 20");
    string nome_produto;
    produtos >> nome_produto >> quantidade;

    cout << "Nome do produto       : " << nome_produto << endl;
    cout << "Quantidade do produto : " << quantidade << endl;

    cout << "---------------------------------" << endl;
    cout << "PESQUISAS E SUBSTRINGS" << endl;
    cout << "---------------------------------" << endl;
    string str5 = "ARMANDO";

    cout << "STR5 ==> " << str5 << endl;

    cout << "str5.find('A') => " << str5.find('A') << endl;
    cout << "str5.find('N') => " << str5.find('N') << endl;
    cout << "str5.find('Z') => " << str5.find('Z') << endl;

    char letra = 'W';
    if (str5.find(letra) != string::npos ) {
        cout << "Caractere '" << letra << "' encontrado\n";
    }
    else {
        cout << "Caractere '" << letra << "' NÃO encontrado\n";
    }

    letra = 'M';
    auto pos = str5.find(letra);
    if (pos != string::npos) {
        cout << "Caractere '" << letra << "' encontrado na posição " << pos << "\n";
    }
    else {
        cout << "Caractere '" << letra << "' NÃO encontrado\n";
    }

    pos = str5.find("MA");
    if (pos != string::npos) {
        cout << "Encontrada 'MA' na posição " << pos << endl;
    }
    else {
        cout << "Não encontrada" << endl;
    }

    str5 = "ARMANDA"s;
    // localiza o 2o 'A'
    pos = str5.find('A', str5.find('A') + 1);  // pos = str5.find('A', 0 + 1)
    if (pos != string::npos) {
        cout << "Segundo 'A' encontrado na posição " << pos << endl;
    }
    else {
        cout << "Não encontrado" << endl;
    }

    // localiza o 3o 'A'
    pos = str5.find('A', pos + 1);

    string str7 = "BOA TARDE";
    string str8 = str7.substr(4, 5);    // extrai 5 caracteres a partir da posição 4
    cout << "Original  : " << str7 << endl;
    cout << "Substring : " << str8 << endl;

    string str9 = str7.substr(4, str7.size());  // extrai 8 caracteres (dimensão de BOA TARDE) 
    cout << "Original  : " << str7 << endl;     // a partir da posição 4
    cout << "Substring : " << str9 << endl;

    cout << "---------------------------------" << endl;
    cout << "MODIFICAÇÃO" << endl;
    cout << "---------------------------------" << endl;

    str7.erase(4);
    cout << "Original  : " << str7 << endl;

    string str10 = "ABCDEFGHI";
    cout << "Antes     : " << str10 << endl;
    str10.erase(3, 3);
    cout << "Depois    : " << str10 << endl;

    // Também poderíamos fazer
    str10 = "ABCDEFGHI";
    cout << "Antes     : " << str10 << endl;    
    cout << "Depois    : " << str10.erase(3, 3) << endl;

    // str10 => "ABCGHI"
    cout << "Vamos inserir \"DEF\" novamente" << endl;
    cout << R"(Vamos inserir "DEF" novamente)" << endl;
    str10.insert(3, "DEF");
    cout << "Agora     : " << str10 << endl;

    /*
    auto reg_exp1 = R"(\s\d.*\S)"
    */

    cout << R"(Vamos substituir "DEF" por "-456-")" << endl;
    str10.replace(3, "DEF"s.length(), "-456-");  // mesmo que str10.replace(3, 3, "-456-");
    cout << "Agora     : " << str10 << endl;

    str10.clear();    // ou str10.erase(0);
}


/*
    pos = -1;
    while (pos != string::pos) {
        pos = str5.find('A', pos + 1);
        cout << "Encontrado na posição " << pos << endl;
    }
*/