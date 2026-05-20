#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total = 0;
    vector<int> digitos(10,0);
    char ch;
    while (cin.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            total += 1;
            digitos[ch - '0'] += 1;
        }
    }
    cout << "Total de digitos: " << total << "\n";
    for (int i = 0; i < digitos.size(); i += 1) {
        cout << i << " -> " << digitos[i] << endl;
    }
    return 0;
}
