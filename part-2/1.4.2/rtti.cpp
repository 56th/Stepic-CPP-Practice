#include <iostream>

struct Unit {
	double a;
	virtual ~Unit() = default;
};

struct Elf : virtual Unit {
	double b;
	double c;
	int d;
};

struct Archer : virtual Unit {
	char e;
};

struct ElfArcher: Elf, Archer {
	int f, g;
	float h;
};

int main() {
	ElfArcher ea;
	Elf* e = &ea;
	Archer* a = &ea;
	Unit* u = &ea;	
	std::cout 
		<< "ea: " << &ea << '\n'
		<< "e:  " << e << '\n'
		<< "a:  " << a << '\n'
		<< "u:  " << u << '\n';
	std::cout
		<< "dynamic_cast<void*>:\n"
		<< "ea: " << dynamic_cast<void*>(&ea) << '\n'
		<< "e:  " << dynamic_cast<void*>(e  ) << '\n'
		<< "a:  " << dynamic_cast<void*>(a  ) << '\n'
		<< "u:  " << dynamic_cast<void*>(u  ) << '\n';
	return 0;
}