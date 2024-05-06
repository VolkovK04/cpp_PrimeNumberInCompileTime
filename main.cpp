#include <iostream>
#include <type_traits>

template<int n, int i = 2>
struct IsPrime : std::integral_constant<bool, (i * i >= n) ? true : (n % i != 0) && IsPrime<n, i + 1>::value> {};

template<int n>
struct IsPrime<n, n> : std::integral_constant<bool, true> {};

template<int N, int i = 2, int count = 0>
struct NthPrimeNumber : std::conditional_t<IsPrime<i>::value, 
                                           std::conditional_t<(count + 1 == N), 
                                                              std::integral_constant<int, i>, 
                                                              NthPrimeNumber<N, i + 1, count + 1>>, 
                                           NthPrimeNumber<N, i + 1, count>> {};

int main() {
    constexpr int N = 10;
    constexpr int result = NthPrimeNumber<N>::value;
    std::cout << "Nth prime number: " << result << std::endl;
    return 0;
}
