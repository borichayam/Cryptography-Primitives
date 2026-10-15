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
    // int base = 3;
    // int exp = 100;
    // int mod = 23;

    // cout << "base: " << base << endl;
    // cout << "exp: " << exp << endl;
    // cout << "mod: " << mod << endl;
    // cout << "result: " << powm(base, exp, mod) << endl;
    int g = 19;
    int p = 29;
    int a = 11;
    int b = 23;
    int A, B;

    cout << "base: " << g << endl;
    cout << "mod: " << p << endl;
    cout << "exp1: " << a << endl;
    cout << "exp2: " << b << endl;

    A = powm(g, a, p);
    B = powm(g, b, p);
    int K1 = powm(A, b, p);
    int K2 = powm(B, a, p);

    cout << "A, B: " << A << ", " << B << endl;
    if (K1 == K2) {
        cout << "Key exchange successful!" << endl;
        cout << "Shared secret: " << K1 << endl;
    } else {
        cout << "Key exchange failed!" << endl;
    }
}