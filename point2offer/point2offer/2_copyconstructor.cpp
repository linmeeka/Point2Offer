#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class A {
private:
	int value;
	A(int n) { value = n; };
	A(const A& a) { value = a.value; };
};