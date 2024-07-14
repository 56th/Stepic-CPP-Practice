#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include <type_traits>
#include "../5.3.7/IntList.hpp"

template<int m = 0, int kg = 0, int s = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
using Dimension = IntList<m, kg, s, A, K, mol, cd>;

template<typename T, typename = void>
struct IsDimension : std::false_type {};

template<int... Vals>
struct IsDimension<
    IntList<Vals...>, 
    typename std::enable_if<(Dimension<>::Length == sizeof...(Vals))>::type
> : std::true_type {};

template<typename Dim>
struct Quantity {
    static_assert(IsDimension<Dim>::value);
    explicit Quantity(double val) noexcept : val(val) {}
    double value() const noexcept {
        return val;
    }
    explicit operator double() const noexcept {
        return val;
    }
private:
    double val;
};   

using NumberQ = Quantity<Dimension<>>;           
using LengthQ = Quantity<Dimension<1>>;          
using MassQ = Quantity<Dimension<0, 1>>;       
using TimeQ = Quantity<Dimension<0, 0, 1>>;    
using VelocityQ = Quantity<Dimension<1, 0, -1>>;   
using AccelQ = Quantity<Dimension<1, 0, -2>>;
using ForceQ = Quantity<Dimension<1, 1, -2>>;

template<typename T>
struct GetDimension {
    using type = Dimension<>;
};

template<typename T>
struct GetDimension<Quantity<T>> {
    using type = T;
};

template<typename Dim>
Quantity<Dim> operator+(Quantity<Dim> const & a, Quantity<Dim> const & b) {
    return Quantity<Dim>(a.value() + b.value());
}

template<typename Dim>
Quantity<Dim> operator-(Quantity<Dim> const & a, Quantity<Dim> const & b) {
    return Quantity<Dim>(a.value() - b.value());
}

template<int A, int B>
struct Plus {
    static int const value = A + B;    
};

template<int A, int B>
struct Minus {
    static int const value = A - B;    
};

template<typename A, typename B, typename Dim = typename Zip<typename GetDimension<A>::type, typename GetDimension<B>::type, Plus>::type>
Quantity<Dim> operator*(A const & a, B const & b) {
    return Quantity<Dim>(static_cast<double>(a) * static_cast<double>(b));
}

template<typename A, typename B, typename Dim = typename Zip<typename GetDimension<A>::type, typename GetDimension<B>::type, Minus>::type>
Quantity<Dim> operator/(A const & a, B const & b) {
    return Quantity<Dim>(static_cast<double>(a) / static_cast<double>(b));
}

#endif