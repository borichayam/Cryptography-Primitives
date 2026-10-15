#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class powm(mpz_class base, mpz_class exp, mpz_class mod) {
    mpz_class r;
    mpz_powm(r.get_mpz_t(), base.get_mpz_t(), exp.get_mpz_t(), mod.get_mpz_t());
    return r;
}

mpz_class urandomm(gmp_randstate_t state, mpz_class n) {
    mpz_class r;
    mpz_urandomm(r.get_mpz_t(), state, n.get_mpz_t());
    return r;
}

int cmp(mpz_class a, mpz_class b) {
    int r;
    r = mpz_cmp(a.get_mpz_t(), b.get_mpz_t()); //ㅋㅋㅋ r에 결과값을 안 넣었었다...
    return r;
}

int main() {
    gmp_randstate_t state;
    gmp_randinit_mt(state);
    mpz_class a, b;
    mpz_class A, B;
    mpz_class Ka, Kb;

    /* DH parameters for TLS (2,048‐bit group) ‐‐RFC7919 */
    ////////////////////////////////////////////////////////
    mpz_class p{
        "0xFFFFFFFFFFFFFFFFADF85458A2BB4A9A"
        "AFDC5620273D3CF1D8B9C583CE2D3695"
        "A9E13641146433FBCC939DCE249B3EF9"
        "7D2FE363630C75D8F681B202AEC4617A"
        "D3DF1ED5D5FD65612433F51F5F066ED0"
        "856365553DED1AF3B557135E7F57C935"
        "984F0C70E0E68B77E2A689DAF3EFE872"
        "1DF158A136ADE73530ACCA4F483A797A"
        "BC0AB182B324FB61D108A94BB2C8E3FB"
        "B96ADAB760D7F4681D4F42A3DE394DF4"
        "AE56EDE76372BB190B07A7C8EE0A6D70"
        "9E02FCE1CDF7E2ECC03404CD28342F61"
        "9172FE9CE98583FF8E4F1232EEF28183"
        "C3FE3B1B4C6FAD733BB5FCBC2EC22005"
        "C58EF1837D1683B2C6F34A26C1B2EFFA"
        "886B423861285C97FFFFFFFFFFFFFFFF"
    };
    mpz_class g = 2;
    ////////////////////////////////////////////////////////

    
    a = urandomm(state, p);
    b = urandomm(state, p);

    cout << "비밀키a :" << a << endl;
    cout << "비밀키b :" << b << endl;
    cout << "--공개키 계산 중--\n" << endl;

    A = powm(g, a, p);
    B = powm(g, b, p);

    cout << "공개키a :" << A << endl;
    cout << "공개키b :" << B << endl;
    cout << "--공유하는 비밀키 계산 중--\n" << endl;

    Ka = powm(B, a, p);
    Kb = powm(A, b, p);

    cout << "비밀키Ka :" << Ka << endl;
    cout << "비밀키Kb :" << Kb << endl;
    cout << "--비교 연산 중--\n" << endl;

    if(cmp(Ka, Kb) == 0)
        cout << "Success!\n" << endl;
    else
        cout << "fail...\n" << endl;


    // gpt니가 하면 좋대
    gmp_randclear(state);
}