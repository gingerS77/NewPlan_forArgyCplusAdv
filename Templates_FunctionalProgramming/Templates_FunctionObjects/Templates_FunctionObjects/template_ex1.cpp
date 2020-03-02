#include <iostream>
#include <cstring>   // string.h       <string>
using namespace std;

template<typename T>
T sum(T a, T b)
{
	return a + b;
}

template<typename T>
T max(T a, T b)                     //  char*  
{
	return a > b ? a : b;
}

// Explicit instantiation
template char sum(char, char);

 //Explicit specialization for char* (raw strings means C style strings...)
 //string s = "Argy Pappas";  // c++ ,  #include <string> 
 //Regular template function definition should be defined before defining this template specialization function
template<> const char* max<const char*>(const char* a, const char* b)                     //  char*  
{
	return strcmp(a, b)<0 ? a : b;
}

template<int x>
void Print()
{
	cout << typeid(x).name() << endl;
}

template<typename T, int size>
T SumofArray(T (&arr)[size])
{
	T sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	return sum;
	//cout << typeid(x).name() << endl;
}


int main()
{
	int arr[]{ 1,4, 7, 9, 2, 3 };
	// reference to an array  ...
	int res = SumofArray(arr);
	//int(&ref)[6] = arr;
	//ref[0] = 9;
	Print<5>();
	int x = 7;
	Print<sizeof(x)>();
	//int res = SumofArray<6>(arr);
	
	system("pause");
	return 0;
}


void oldfun()
{
	int a = 5, b = 7;
	sum<int>(a, 7.8f); // overriding the compiler instatiation process... function name <>
	double resD = sum(4.7, 7.9);   // by default decimal numbers are treated as double
								   /*float f1 = 5.8, f2 = 7.7;
								   sum(f1, f2);*/
	float(*pfn)(float, float) = sum;  // by having an address of a template function, the compiler basically 
									  // instantiates the template function for that particlar type
									  // in this case it will instantiate the sum() for float type

	// ----------------------------------------------------------

	const char* b1{ "Barcelona" };
	const char* a1{ "Arsenal" };

	//const char * maximumString = max<const char*>(a, b);

	//cout << maximumString << endl;

}