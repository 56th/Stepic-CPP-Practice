#include <type_traits>
#include <utility>

template<class T>
void do_math() noexcept(
    std::is_nothrow_copy_constructible<T>() &&
    std::is_nothrow_copy_assignable<T>() &&
    noexcept(std::declval<T>() + std::declval<T>()) 
) {
    // ...
}