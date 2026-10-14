#include <iostream>
#include <string>

using namespace std;

int powm(int base, int exp, int mod) {
    // int a = 1;

    // for (int i=0; i<exp; i++) {
    //     a = a*base;
    // }

    // return a%mod;
    // 이렇게 하면 정수 오버플로(Integer Overflow)가 됨!!

    int r = 1;

    for (int i=0; i<exp; i++) {
        r *= base;
        r %= mod;
    }

    return r;
}

int main() {
    int base = 3;
    int exp = 100;
    int mod = 23;

    cout << "base: " << base << endl;
    cout << "exp: " << exp << endl;
    cout << "mod: " << mod << endl;
    cout << "result: " << powm(base, exp, mod) << endl;
}