# compile-eval
Вычисления во время компиляции в разных стандартах:

## C++03

В этой секции используется старый стандарт языка C++03. Для организации вычислений использовался только механизм инстанцирования шаблонов.

В файле `pow.h` реализован шаблон  `Pow<int, int>`. В `Pow<a, b>::value` лежит результат выражения $`a^b`$. Считаем, что $`a > 0, b \ge 0`$. 

В файле `sqrt.h` реализован шаблон `Sqrt<n>`. В `Sqrt<n>::value` лежит такое наименьшее x, что $`x * x \ge n`$.

## C++11

В этой секции используется стандарт C++11. Теперь доступны `constexpr` выражения. Однако в этой версии стандарта на constexpr-функции наложены довольно строгие ограничения
(например, функция может представлять собой только выражение вида return ...).

В файле `another_pow.h` реализована функция `pow(int, int)` (теперь вместо шаблонов использованы возможности constexpr).

В файле `hash.h` реализована функция `hash(const char *s, int p, int m)`, которая считает следующий полиномиальный хеш строки s на этапе компиляции:
```math
h = \sum\limits_{i = 0}^{|s| - 1} s_i * p^{i} (mod \; m)
```

## C++14

В этой секции используется стандарт C++14, который существенно ослабил ограничения, налагаемые на constexpr функции, а также ввел широкую поддержку constexpr стандартной библиотекой. Это
позволило реализовывать намного более сложные алгоритмы на этапе компиляции.

В файле `next_prime.h` реализована функция `next_prime(int)`, которая по заданному `x` находит такое наименьшее $`y \ge x`$, что y --- простое.

В файле `determinant.h` реализована функция `determinant` . Данная функция вычисляет определитель заданной квадратной матрицы. 