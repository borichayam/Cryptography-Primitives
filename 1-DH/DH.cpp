#include <gmpxx.h>

mpz_class powm(mpz_class m, mpz_class e, mpz_class K) {
    mpz_class r;
    // m=base, e=exp, K=mod
    mpz_powm(r.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), K.get_mpz_t());
    return r;
}

mpz_class urandomm(gmp_randstate_t state, const mpz_class n) {
    
}

int cmp(mpz_class A, mpz_class B) {

}