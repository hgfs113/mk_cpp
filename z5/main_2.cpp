#include <type_traits>
#include <typeinfo>


template <typename...>
struct are_same;

template <typename T>
struct are_same<T> : std::true_type {};

template <typename T, typename U, typename... Ts>
struct are_same<T, U, Ts...> : std::bool_constant<std::is_same<T, U>::value && are_same<U, Ts...>::value> {};


template<typename... Ts>
constexpr bool are_same_v = are_same<Ts...>::value;


int main() {
    static_assert(are_same_v<int, int32_t, signed int>, "compile assert");  // ok
    // static_assert(are_same_v<int, double>, "compile assert");  // compile error
}
