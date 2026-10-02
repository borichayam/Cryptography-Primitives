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
    x = (x % mod + mod) % mod;

    for (int i=1; i<mod; i++) {
        if ((x*i) % mod == 1)
            return i;
    }

    return -1;
};

void EC_double(EC E, Point *R, Point P) {
    int numerator = 3 * P.x * P.x + E.a;
    int denominator = 2 * P.y;

    numerator = (numerator % E.p + E.p) % E.p;
    denominator = (denominator % E.p + E.p) % E.p;

    int inv = mod_inv(denominator, E.p);

    if (inv == -1) {
        R->x = -1;
        R->y = -1;
        return;
    }

    int lambda = (numerator * inv) % E.p;

    int x3 = lambda * lambda - 2 * P.x;
    x3 = (x3 % E.p + E.p) % E.p;

    int y3 = lambda * (P.x - x3) - P.y;
    y3 = (y3 % E.p + E.p) % E.p;

    R->x = x3;
    R->y = y3;
};

void EC_add(EC E, Point *R, Point P, Point Q) {
    if (P.x == Q.x && P.y == Q.y) {
        EC_double(E, R, P);
        return;
    }

    int numerator = Q.y - P.y;
    int denominator = Q.x - P.x;

    numerator = (numerator % E.p + E.p) % E.p;
    denominator = (denominator % E.p + E.p) % E.p;

    int inv = mod_inv(denominator, E.p);

    if (inv == -1) {
        R->x = -1;
        R->y = -1;
        return;
    }

    int lambda = (numerator * inv) % E.p;

    int x3 = lambda * lambda - P.x - Q.x;
    x3 = (x3 % E.p + E.p) % E.p;

    int y3 = lambda * (P.x - x3) - P.y;
    y3 = (y3 % E.p + E.p) % E.p;

    R->x = x3;
    R->y = y3;
}


int main()
{
    EC E = {2, 3, 5};

    Point A = {1, 4};
    Point B = {3, 1};
    Point R;

    cout << "A = (" << A.x << "," << A.y << ")" << endl;
    cout << "B = (" << B.x << "," << B.y << ")" << endl;

    EC_add(E, &R, A, B);
    cout << "A + B = (" << R.x << "," << R.y << ")" << endl;

    EC_double(E, &R, A);
    cout << "2A = (" << R.x << "," << R.y << ")" << endl;

    return 0;
}