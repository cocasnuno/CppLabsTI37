#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include <boost/lambda/lambda.hpp>
#include <boost/range/irange.hpp>
#include <boost/filesystem.hpp>

using namespace std;

using namespace boost::lambda;
using namespace boost::filesystem;
using namespace boost;

int sum_a_to_b(int a, int b) {
    auto r = irange(a, b + 1);
    return accumulate(r.begin(), r.end(), 0);
}

int main(int argc, char** argv) {
    // std::system("chcp 65001>nul");
    int i = 0;
    vector<int> vals{10, 20, 30};
    cout << "Teste: Programação em C/C++. Alguns caracteres: á, è, ô, €." << endl;
    for (auto v : vals) {
        cout << i << " - " << v << endl;
        i += 1;
    }

    // typedef std::istream_iterator<int> in;
    // for_each(in(std::cin), in(), std::cout << (_1 * 3) << " " );

    cout << "Sum of 20 to 25 is " << sum_a_to_b(20, 25) << endl;

    for(auto& p : recursive_directory_iterator(".")) {
        cout << p.path() << '\n';
    }
    cout << "Fim" << endl;
}