#include <iostream>
#include <map>
#include <typeindex>
#include <functional>

using Args2 = std::pair<std::type_index, std::type_index>;

namespace std {
    template<>
    struct hash<Args2> { // for compatibility w/ unordered_map (no need for the tree-based map) 
        size_t operator()(Args2 const & args) const {
            auto h = hash<type_index>();
            auto h1 = h(args.first);
            auto h2 = h(args.second);
            return h1 == h2 ? h1 : h1 ^ h2;
        }
    };
}

template<typename Base, typename Result, bool Commutative>
struct Multimethod2 {
	using Function = std::function<Result(Base *, Base *)>;
    void addImpl(std::type_info const & t1, std::type_info const & t2, Function const & f) {
        auto key = make_key(t1, t2);
        _impls[key] = f;
	}
	bool hasImpl(Base * a, Base * b) const {
        if (_impls.find(make_key(typeid(*a), typeid(*b))) == _impls.end())
            return Commutative ? _impls.find(make_key(typeid(*b), typeid(*a))) != _impls.end() : false;
        return true;
	}
	Result call(Base * a, Base * b) const {
        auto f = _impls.find(make_key(typeid(*a), typeid(*b)));
        return f != _impls.end() ? f->second(a, b) : call(b, a);
    }
private:
    std::map<Args2, Function> _impls; // or unordered_map, see above
    Args2 make_key(std::type_info const & t1, std::type_info const & t2) const {
        return {std::type_index(t1), std::type_index(t2)};
    }
};

// for dummy testing

struct Shape {
	virtual ~Shape() = default; // for RTTI
};

struct Rectangle : Shape {
};

struct Triangle : Shape {
};

int main() {
    Multimethod2<Shape, bool, true> is_intersect;
    is_intersect.addImpl(typeid(Rectangle), typeid(Rectangle), [](Shape * r1, Shape * r2) { 
        std::cout << "intersect_r_r: " << typeid(*r1).name() << ' ' << typeid(*r2).name() << "\n\n";
        return true; // dummy
    });
    is_intersect.addImpl(typeid(Triangle), typeid(Rectangle), [](Shape * t, Shape * r) { 
        std::cout << "intersect_t_r: " << typeid(*t).name() << ' ' << typeid(*r).name() << "\n\n";
        return true; // dummy
    });
    Triangle t;
    Rectangle r;
    std::vector<Shape*> shapes = { &t, &r };
    for (auto* s1 : shapes)
        for (auto* s2 : shapes) {
            std::cout << "arg types: " << typeid(*s1).name() << ' ' << typeid(*s2).name() << '\n';
            if (is_intersect.hasImpl(s1, s2))
                is_intersect.call(s1, s2);
            else
                std::cout << "no implementation" << "\n\n";
        }
    return 0;
}