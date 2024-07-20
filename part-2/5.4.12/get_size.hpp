#ifndef GET_SIZE_HPP
#define GET_SIZE_HPP

template<typename T, size_t (T::*)() const = &T::size>
size_t get_size(T const & container) {
    return container.size();
}

template<typename T, size_t T::* = &T::size>
size_t get_size(T const & container) {
    return container.size;
}

#endif