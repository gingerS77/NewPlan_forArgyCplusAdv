#include <iostream>
using namespace std;

template<typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	int a = 5, b = 7;
	sum<int>(a, 7.8f); // overriding the compiler instatiation process... function name <>
	/*float f1 = 5.8, f2 = 7.7;
	sum(f1, f2);*/
	system("pause");
	return 0;
}