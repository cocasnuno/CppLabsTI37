/** 
 * vector / array     => Ambos são sequências mutáveis de objectos do mesmo do tipo 
 *                       de dados. Ou seja, são sequências homogéneas.
 *                       Além disto, todos os elementos são guardados 
 *                       contigua e continuamente em memória.
 *
 * vector (C++)       => Sequência mutável, homogénea e EXTENSÍVEL de objectos.
 *                       Necessitamos do módulo "vector":
 * 
 *                          #include <vector>
 *
 *                       Em Java, o tipo de dados equivalente é "ArrayList".
 *
 * array (C)          => Sequência mutável, homogénea e NÃO-EXTENSÍVEL de objectos.
 *                       Também se utiliza o termo "Vector simples não-extensível"
 *                       para um array.
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
 *
 */

#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

template<typename T>
void print_vector(const vector<T>& elems) {
    for (int i = 0; i < elems.size(); i += 1) {
        cout << elems[i] << endl;
    }
}

void print_array(const int array[], const int SIZE) {
    for (int i = 0; i < SIZE; i += 1) {
        cout << array[i] << endl;
    }
}

int main() {
    // VECTOR (C++)
    // Vector extensível
    //
    // #include <vector>
    //
    // std::vector<TIPO_DADOS> VAR{OBJ1, OBJ2, ....};
    // std::vector<TIPO_DADOS> VAR = {OBJ1, OBJ2, ....};
    // std::vector<TIPO_DADOS> VAR(N);          // cria vector com N elementos do 
    //                                          //  tipo TIPO_DADOS
    // std::vector<TIPO_DADOS> VAR(N, M);       // cria vector com N elementos do 
    //                                          //  tipo TIPO_DADOS inicializados a M

    vector<int> idadesA{20, 18, 38, 41, 21, 46};
    cout << "VECTOR idadesA" << endl;
    cout << "1o elemento      : " << idadesA[0] << endl;
    cout << "1o elemento      : " << idadesA.front() << endl;
    cout << "Ultimo elemento  : " << idadesA[idadesA.size() - 1] << endl;
    cout << "Ultimo elemento  : " << idadesA.back() << endl;
    print_vector(idadesA);

    cout << "--------\n";
    cout << "VECTOR idadesB" << endl;
    vector<int> idadesB(idadesA.size());

    for (int i = 0; i < idadesB.size(); i += 1) {
        idadesB[i] = idadesA[i];
    }
    print_vector(idadesB);

    cout << "--------\n";
    cout << "VECTOR idadesC" << endl;
    vector<int> idadesC;

    for (int i = 0; i < idadesA.size(); i += 1) {
        idadesC.emplace_back(idadesA[i]);
        // idadesC.push_back(idadesA[i]);
    }
    print_vector(idadesC);

    cout << "--------\n";
    cout << "VECTOR idadesD" << endl;
    vector<int> idadesD(idadesA);
    print_vector(idadesD);

    // Remover elementos vector
    cout << "---------\n";
    cout << "Antes de remover:" << endl;
    print_vector(idadesA);
    idadesA.erase(idadesA.begin() + 2);
    cout << "Depois de remover (posição 2):" << endl;
    print_vector(idadesA);

    // Remover 3 elementos a partir da posição 1:
    //     idadesA.erase(idadesA.begin() + 1, idadesA.begin() + 1 + 3);
    //     idadesA.erase(idadesA.begin() + 1, idadesA.begin() + 4);
    //
    // Remover X elementos a partir da posição P:
    //     idadesA.erase(idadesA.begin() + P, idadesA.begin() + P + X);

    // Relembrando:
    //      vector<int> idadesA{20, 18, 41, 21, 46};
    idadesA.erase(idadesA.begin() + 1, idadesA.begin() + 4); 
    cout << "Depois de remover 3 elementos a partir da posição 1:" << endl;
    print_vector(idadesA);

    cout << "---------\n";
    cout << "Antes do emplace_back/push_back:" << endl;
    print_vector(idadesA);
    idadesA.emplace_back(40);         // idadesA.push_back(40);
    idadesA.emplace_back(84);         // idadesA.push_back(84);
    cout << "Depois do emplace_back/push_back:" << endl;
    print_vector(idadesA);

    cout << "Tamanho do vector (antes pop_back)  : " << idadesA.size() << endl;
    idadesA.pop_back();
    cout << "Tamanho do vector (depois pop_back) : " << idadesA.size() << endl;
    idadesA.clear();
    cout << "Tamanho do vector (depois clear)    : " << idadesA.size() << endl;

    cout << "---------\n";
    cout << "VECTOR de NOMES" << endl;
    vector<string> nomes{
        "ALBERTO",
        "ARMANDO",
        "AUGUSTO",
        "ARNALDO",
        "ANTÓNIO",
        "ARNALDO",
        "AVELINO",
    };
    cout << "Antes de remover ARNALDO" << endl;
    print_vector(nomes);
    cout << endl;

    auto pos_a_remover = remove(nomes.begin(), nomes.end(), "ARNALDO");
    nomes.erase(pos_a_remover, nomes.end());

    // nomes.erase(remove(nomes.begin(), nomes.end(), "ARNALDO"), nomes.end());

    cout << "Depois de remover ARNALDO" << endl;
    print_vector(nomes);

    //
    // ARRAYs (C)
    // Vectores simples não-extensíveis.
    // 
    // TIPO_DADOS VAR[] = {OBJ1, OBJ2, ...};
    // TIPO_DADOS VAR[SIZE];
    //
    // ARRAY_OU_VECTOR[POS] => elemento na posição POS, em que POS é um valor
    //                         entre 0 e SIZE - 1 (SIZE é o número de elementos
    //                         no ARRAY_OU_VECTOR)

    // const int SIZE = 8;
    // int idadesA[] = {20, 18, 37, 41, 21, 46, 44, 29};
    // cout << "ARRAY idadesA" << endl;
    // cout << "1o elemento     : " << idadesA[0] << endl;
    // cout << "Último elemento : " << idadesA[SIZE-1] << endl;

    // cout << "Mostra todos:" << endl;
    // print_array(idadesA, SIZE);

    // cout << "\nCopiar idadesA para idadesB" << endl;
    // int idadesB[SIZE];

    /*
    idadesB[0] = idadesA[0];
    idadesB[1] = idadesA[1];
    idadesB[2] = idadesA[2];
    etc.
    */

    // for (int i = 0; i < SIZE; i += 1) {
    //     idadesB[i] = idadesA[i];
    // }
    // print_array(idadesB, SIZE);
}