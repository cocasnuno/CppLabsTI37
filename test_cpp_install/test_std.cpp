#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum_a_to_b(int a, int b) {
    int sum = 0;
    for (int x = a; x <= b; x += 1) {
        sum += x;
    }
    return sum;
}

int main() {
    vector<string> msg{"Hello", "C++", "World", "from the", "Test Project!"};

    for (const string& word : msg) {
        cout << word << " ";
    }
    cout << endl;

    cout << "Sum of 20 to 25 is " << sum_a_to_b(20, 25) << endl;
}

