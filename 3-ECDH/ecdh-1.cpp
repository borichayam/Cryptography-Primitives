#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct EC {
    int a;
    int b;
    int p;
};

int mod_inv(int x, int mod) {
    int r;

    if (x==0) 
        return 0; //infinity
    else if (mod <= 0)
        return -1; // error
    else {
        while (x < 0) {
            x += mod;
        }

        for (r=0; r<mod; r++) {
            if ((r*x)%mod == 1)
                return r;
        }

        return -1;
    }
    
    '''x = (x % mod + mod) % mod;

    for (int i=1; i<mod; i++) {
        if ((x*i) % mod == 1)
            return i;
    }

    return -1;'''
};
