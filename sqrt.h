template <bool B, class T, class F>
struct Conditional {
    static const unsigned long value = T::value;
};

template <class T, class F>
struct Conditional<false, T, F> {
    static const unsigned long value = F::value;
};

template <const unsigned long N, const unsigned long Left, const unsigned long Right>
struct BinarySearch {
    static const unsigned long value =
        Conditional<((Left + Right) / 2) * ((Left + Right) / 2) < N,
                    BinarySearch<N, (Left + Right) / 2 + 1, Right>,
                    BinarySearch<N, Left, (Left + Right) / 2> >::value;
};

template <const unsigned long N, const unsigned long Mid>
struct BinarySearch<N, Mid, Mid> {
    static const unsigned long value = Mid;
};

template <const unsigned long N>
struct Sqrt {
    static const int value = BinarySearch<N, 0, N>::value;
};
