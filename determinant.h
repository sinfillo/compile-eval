#pragma once

#include <array>

template <int N>
constexpr int determinant(const std::array<std::array<int, N>, N>& a) {
    // разложение по 1 строке
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        std::array<std::array<int, N - 1>, N - 1> cur{};
        for (int j = 1; j < N; ++j) {
            int pt_in_new = 0;
            int pt = 0;
            while (pt < N) {
                if (pt != i) {
                    (&std::get<0>(((&std::get<0>(cur))[j - 1])))[pt_in_new++] = a[j][pt];
                }
                ++pt;
            }
        }
        if ((1 + i + 1) % 2 == 0) {
            ans += a[0][i] * determinant<N - 1>(cur);
        } else {
            ans -= a[0][i] * determinant<N - 1>(cur);
        }
    }

    return ans;
}

template <>
constexpr int determinant<2>(const std::array<std::array<int, 2>, 2>& a) {
    return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

template <>
constexpr int determinant<1>(const std::array<std::array<int, 1>, 1>& a) {
    return a[0][0];
}