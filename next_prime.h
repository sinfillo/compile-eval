#pragma once

constexpr bool CheckPrime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

constexpr int next_prime(int x) {
    while (!CheckPrime(x)) {
        ++x;
    }
    return x;
}
