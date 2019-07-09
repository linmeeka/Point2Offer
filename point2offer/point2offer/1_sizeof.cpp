#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class A {

};

class B {
public:
	B() {};
	~B() {};
	void fun() {};
	int fun1() { return 1; };
};

class C {
public:
	C() {};
	~C() {};
	void fun() {};
	int fun1() { return 1; };
	virtual int fun2() { return 2; };
};

int main()
{
	A a;
	B b;
	C c;
	cout << "sizeof A: " << sizeof(a) << endl;
	cout << "sizeof B: " << sizeof(b) << endl;
	cout << "sizeof C: " << sizeof(c) << endl;
	return 0;
}