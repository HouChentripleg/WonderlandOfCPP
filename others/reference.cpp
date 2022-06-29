#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int* p = &a;
    int& r = a;
    cout << "a = " << a << ", "<< "p = " << p << ", "<< "*p = " << *p << ", "<< "r = " << r << endl;

    int b = 5;
    r = b;
    cout << "a = " << a << ", "<< "p = " << p << ", "<< "*p = " << *p << ", "<< "r = " << r << endl;
}