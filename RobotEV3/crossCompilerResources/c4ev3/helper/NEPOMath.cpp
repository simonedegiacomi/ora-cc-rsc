#include "NEPOMath.h"


bool IsWhole(double d) {
    return d == floor(d);
}

bool IsPrime(double d) {
    if (!IsWhole(d)) {
        return false;
    }
    int n = d;
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3, s = (int) (sqrt(d) + 1); i <= s; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
