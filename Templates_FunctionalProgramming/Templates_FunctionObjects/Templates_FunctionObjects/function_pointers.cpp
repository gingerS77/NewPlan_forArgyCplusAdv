#include <iostream>
using namespace std;

//int sum(int a, int b) {
//	return a + b;
//}
//
//
//
////typedef int(*fn)(int, int);    // using    typedef struct name Name;
//// C++  , using  .........
////using fn = int(*)(int, int);  //  C++ 20 
//
//using cmp = bool(*)(int, int);  // this is the beauty of using keyword in C++
//// typedef bool(*cmp)(int,int);
//
//// Bubble sort....
////void bubblesort(int *arr, int size, cmp compare )
////{
////	for (int i = 0; i < size - 1; ++i)
////	{
////		for (int j = 0; j < size - i - 1; ++j)
////		{
////			if (compare(arr[j] , arr[j + 1]))
////			{
////				swap(arr[j], arr[j + 1]);
////			}
////		}
////	}
////}
//
////template
//void bubblesort(int *arr, int size, cmp compare )
//{
//	for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = 0; j < size - i - 1; ++j)
//		{
//			if (compare(arr[j] , arr[j + 1]))
//			{
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//
//bool ascending(int a, int b) {
//	return a > b ? true : false;
//}
//
//bool descending(int a, int b) {
//	return a < b ? true : false;
//}
//
//using fn = bool (*)(int, int);
//
//bool max(int a, int b)
//{
//	return (a > b) ? true : false;
//}
//
//struct Comparator {
//	bool operator()(int x, int y) {
//		return x > y;
//	}
//};
// to invoke a function object(functors), we need to first creaete the object , then using the object we can invoke it
// objectname()
//int main()
//{
//	Comparator cmp;
//	cout << boolalpha << cmp(4, 3) << endl << endl;  // cmp.operator()(4,3);
//
//
//	fn myfun_ptr = max;  // assigning the address of a function to a function pointer
//	cout << boolalpha << myfun_ptr(4, 9) << endl;
//	int A[] = { 3,2,1,5,6,4,12,44,67,21,13,31,55 };
//	int size = sizeof(A) / sizeof(int);
//	std::cout << "\nPrinting before sorting:\n ";
//	for (int i = 0; i < size; ++i)
//		std::cout << A[i] << "  ";
//	cout << endl;
//	//bubblesort(A, size, &ascending);
//
//	//std::cout << "Printing after sorting: ";
//	//for (int i = 0; i < size; ++i)
//	//	std::cout << A[i] << "  ";
//
//	cout << endl;
//	system("pause");
//	return 0;
//}


//void old_code()
//{
//	fn fn1 = sum;  // fn1 is function pointer....
//				   //int sum = (*fn)(3, 4);
//	int result = fn1(3, 4);
//	cout << "Sum = " << result << endl;
//	
//}