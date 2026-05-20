// 1. Definir array de C com os valores de 10 a 15

// 2. Escrever código para somar os valores do array anterior

// 3. Definir vector (com std::vector) com valores pares de 0 a 20

// 4. Definir outro vector que é uma cópia deste vector

// 5. Definir vector (com std::vector) com os seguintes nomes: ALBERTO, 
//    ARMANDO, ARNALDO, AUGUSTO.

// 6. Escrever código para indicar a posição do ARNALDO neste vector.

// 7. Contar o número de ocorrências de ARNALDO

// 8. Escrever código para indicar se o ARNALDO está presente no vector (usar FOR-each)

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
    cout << "// 1. Definir array de C com os valores de 10 a 15\n";
    const int SIZE = 6;
    int valores1[] = {10, 11, 12, 13, 14, 15};
    cout << "valores1:\n";
    print_array(valores1, SIZE);

    int valores2[SIZE];
    valores2[0] = 10;
    valores2[1] = 11;
    valores2[2] = 12;
    valores2[3] = 13;
    valores2[4] = 14;
    valores2[5] = 15;
    cout << "valores2:\n";
    print_array(valores2, SIZE);

    int valores3[SIZE];
    for (int i = 0; i < SIZE; i += 1) {
        valores3[i] = 10 + i;
    }
    cout << "valores3:\n";
    print_array(valores3, SIZE);

    cout << "// 2. Escrever código para somar os valores do array anterior\n";
    auto soma = 0;
    for (int i = 0; i < SIZE; i += 1) {
        soma += valores1[i];
    }
    cout << "Soma => " << soma << endl;


    cout << "// 3. Definir vector (com std::vector) com valores pares de 0 a 20\n";
    vector<int> pares;
    for (int n = 0; n <= 20; n += 2) {
        pares.emplace_back(n);
    }
    print_vector(pares);

    cout << "// 4. Definir outro vector que é uma cópia deste vector\n";
    vector<int> pares2(pares);
    print_vector(pares2);

    cout << R"(
//5. Definir vector (com std::vector) com os seguintes nomes: ALBERTO, 
// ARMANDO, ARNALDO, AUGUSTO.
)" << endl;

    vector<string> nomes{
        "ALBERTO"s,
        "ARMANDO"s,
        "ARNALDO"s,
        "AUGUSTO"s,
        "ARNALDO"s,
    };

    cout << "// 6. Escrever código para indicar a posição do ARNALDO neste vector.\n";
    cout << "// 6a\n";

    bool encontrado = false;
    int i = 0;
    for (; i < nomes.size(); i += 1) {
        if (nomes[i] == "ARNALDO"s) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << "Encontrado na posição " << i << endl;
    }
    else {
        cout << "Não encontrado" << endl;
    }

    cout << "// 6b\n";

    i = 0;
    for (; i < nomes.size(); i += 1) {
        if (nomes[i] == "ARNALDO"s) {
            break;
        }
    }

    if (i < nomes.size()) {
        cout << "Encontrado na posição " << i << endl;
    }
    else {
        cout << "Não encontrado" << endl;
    }

    cout << "// 6c\n";
    auto pos = find(nomes.begin(), nomes.end(), "ARNALDO"s);

    if (pos != nomes.end()) {
        auto i = pos - nomes.begin();
        cout << "Encontrado na posição " << i << endl;
    }
    else {
        cout << "Não encontrado" << endl;
    }

    cout << "// 7. Contar o número de ocorrências de ARNALDO\n";
    cout << "// 7a\n";
    auto conta_nome = 0;
    for (int i = 0; i < nomes.size(); i += 1) {
        if (nomes[i] == "ARNALDO"s) {
            conta_nome += 1;
        }
    }

    cout << "Encontrado " << conta_nome << " vez(es).\n";

    cout << "// 7b\n";
    conta_nome = count(nomes.begin(), nomes.end(), "ARNALDO"s);
    cout << "Encontrado " << conta_nome << " vez(es).\n";

    // 8. Escrever código para indicar se o ARNALDO está presente no vector (usar FOR-each)

}