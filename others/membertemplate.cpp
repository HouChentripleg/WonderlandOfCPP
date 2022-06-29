#include <iostream>

template<class T1, class T2>
struct Pair {
    T1 first;
    T2 second;
    Pair() : first(T1()), second(T2()) {}
    Pair(const T1& a, const T2& b) : first(a), second(b) {}

    template<class U1, class U2>
    Pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
};
