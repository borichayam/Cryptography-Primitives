//  nextprime 함수: mpz_nextprime(𝑟𝑟,𝑧𝑧) 이용  𝑛𝑛보다 큰 최초의 소수를 return
#include <gmpxx.h>

mpz_class nextprime(mpz_class n) {
	mpz_class r;
	mpz_nextprime(r.get_mpz_t(), n.get_mpz_t());
	return r;
}

mpz_class powm(mpz_class m, mpz_class e, mpz_class K) {
    mpz_class r;
    // m=base, e=exp, K=mod
    mpz_powm(r.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), K.get_mpz_t());
    return r;
}