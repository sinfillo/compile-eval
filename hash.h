#pragma once

constexpr long hash(const char *s, int p, int mod) {
    return (*s == '\0') ? (0)
                        : ((*s % mod + ((p % mod) * (hash(s + 1, p, mod) % mod)) % mod) % mod);
}
