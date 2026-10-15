#include <iostream>

using namespace std;

long long powm (long long base, long long exp, long long mod) {
    // 일단 입력값 검사해야해
    if (mod <= 0 || exp < 0)
        return -1;
    // base 압축을 해보자
    base %= mod;
    // **mod가 1인 경우 대비하려고
    long long result = 1 % mod;
    
    while (exp > 0) {
        if (exp%2 == 1) 
            result = result*base % mod;

        base = base*base % mod;
        // exp는 지금 정수형이라 나머지는 버려짐
        exp /= 2;
    }

    return result;
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