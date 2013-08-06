#include <iostream>

struct A {
	void fun() {
		std::cout << "funA\n";
	}

	virtual void virtfun() {
		std::cout << "virtfunA\n";
	}
};
struct B : public A {
	void fun() {
		std::cout << "funB\n";
	}
	virtual void virtfun() {
		std::cout << "virtfunB\n";
	}
};

int main() {
	A a;
	B b;

	// statische Aufrufe
	a.fun();     // funA
	a.virtfun(); // virtfunA

	b.fun();     // funB
	b.virtfun(); // virtfunB
	b.A::fun();  // funA

	A& ap = b;
	ap.fun();    // funA
	// dynamischer Aufruf
	ap.virtfun();// virtfunB
}

