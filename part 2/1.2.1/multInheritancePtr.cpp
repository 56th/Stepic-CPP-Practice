#include <iostream>

struct Base {
	virtual void foo() const = 0;
	virtual ~Base() {}
}; 

struct D1 : Base {
	void foo() const final { std::cout << "D1::" << __func__ << '\n'; }
};

struct D2 : Base {
	void foo() const final { std::cout << "D2::" << __func__ << '\n'; }
}; 

struct D3 : D1, D2 {};

// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
Base const * D1BaseToD2Base(Base const * base) {
	// (1):
    auto d1 = static_cast<D1 const *>(base);
	auto d3 = static_cast<D3 const *>(d1);
	D2 const * d2 = d3;
	return d2;
	// or (2):
	// return dynamic_cast<D2 const *>(base);
}

int main() {
	D3 d3;
	D1 const * d1 = &d3;
	Base const * d1_base = d1;
	d1_base->foo();
	auto d2_base = D1BaseToD2Base(d1_base);
	d2_base->foo();
	return 0;
}

/*
	lesson link:
	https://stepik.org/lesson/53365/step/5?course=%D0%9F%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BD%D0%B0-%D1%8F%D0%B7%D1%8B%D0%BA%D0%B5-C%2B%2B-(%D0%BF%D1%80%D0%BE%D0%B4%D0%BE%D0%BB%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5)&unit=31457
*/