#include <iostream>
using namespace std;

class P {
public:
    P(int a, int b) {
        cout << "P(int a, int b)" << endl;
    }
    P(initializer_list<int>) {
        cout << "P(initializer_list<int>)" << endl;
    }
    explicit P(int a, int b, int c) {
        cout << "P(int a, int b, int c)" << endl;
    }
};

void fp(const P&) {
    cout << "function" << endl;
};

int main() {
    P p1(2, 5);
    P p2{2, 5};
    P p3{2, 5, 9};
    P p4 = {2, 5, 9};

    fp({7, 2});
    fp({7, 2, 9});

    return 0;
}