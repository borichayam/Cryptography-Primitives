#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class nextprime(mpz_class n) {
    mpz_class r;
    mpz_nextprime(r.get_mpz_t(), n.get_mpz_t());
    return r;
}

mpz_class powm(mpz_class b, mpz_class g, mpz_class p) {
    mpz_class r;
    mpz_powm(r.get_mpz_t(), b.get_mpz_t(), g.get_mpz_t(), p.get_mpz_t());
    return r;
}

mpz_class urandomm(gmp_randstate_t state, mpz_class n) {
    mpz_class r;
    mpz_urandomm(r.get_mpz_t(), state, n.get_mpz_t());
    return r;
}

int cpm(mpz_class a, mpz_class b) {
    int r;
    r = mpz_cmp(a.get_mpz_t(), b.get_mpz_t());
    return r;
}

int main() {
    cout << "13 > " << nextprime(13) << endl;
}