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

// Non type template arguments must be a constant value.... so thats why we can use it as the size of the 
//array
// Do we need to add size in the template part so as to use it inside SumofArray()?

template<typename T, int size>
T SumofArray(T (&arr)[size])
{
	T sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];
	return sum;
	//cout << typeid(x).name() << endl;
}


void StringManipulations()
{
	const int MAX_N = 100;
	char G[MAX_N][MAX_N + 1];  // G[0]-> template  , G[1]-> object, G[2]....so on
	// char *G[MAX_N];

	//for (int i = 0; i < 5; ++i)
	//	scanf("%s", G[i]);
	//// print the string of which we taken the input
	//for (int i = 0; i < 5; ++i)
	//	printf("%s\n", G[i]);

	//char s[] = "Argy"; //  
	//s[3] = 'x';
	//cout << s << endl;

	//char *s = "himanshu";   // const char * s = "himanshu"; it means where s is pointing to cannot be changed , 
	//                        // but s(pointer) itself can be changed.
	//*(s + 1) = 'B';
	//char s2[] = "lionel";
	//s = s2;                      mystrcpy(), mystrcat(), mystrlen(), mystrcmp()
//	cout << s << endl;
}


//int main()
//{
//	int arr[]{ 1,4, 7, 9, 2, 3 };
//	// reference to an array  ...
//	int res = SumofArray(arr);
//	cout << res << endl;
//	int(&refArray)[6] = arr;
//	refArray[0] = 9;
//	cout << SumofArray(arr) << endl;
//	Print<5>();
//	int x = 7;
//	Print<sizeof(x)>();
//	//int res = SumofArray<6>(arr); ??? What did we intend to show here? how do we finally avoid specifying the size of the array(in our example 6)?
//	
//	cout << "example2" << endl;
//	//example2();
//
//	system("pause");
//	return 0;
//
//}


//int main()
//{
//	int arr[]{ 1,4, 7, 9, 2, 3 };
//	StringManipulations();
//	// auto x = begin(arr);   
//	// reference to an array  ...
//	//int res = SumofArray(arr);
//	//int(&ref)[6] = arr;
//	//ref[0] = 9;
//	//Print<5>();  // to invoke it we are passing the non-type parameter within the template argument list.
//	//int x = 7;
//	//Print<sizeof(x)>();
//	//int res = SumofArray<6>(arr);
//	
//	system("pause");
//	return 0;
//}


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
}

void example2()
{

	const char* b{ "Barcelona" };
	const char* a{ "Arsenal" };

	const char * maximumString = max<const char*>(a, b);

	cout << *maximumString << endl; //This prints A only. Is this happening because the char pointer points to the first char of the string "Arsenal"?
	cout << maximumString << endl;

}