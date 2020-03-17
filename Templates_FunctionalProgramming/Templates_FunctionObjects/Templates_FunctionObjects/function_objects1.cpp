#include <iostream>
using namespace std;

//template<typename T>
//using cmp = bool(*)(T, T);
//
////template<typename T, int size>  // for function pointers
////void bubblesort(T (&arr)[size], cmp<T> compare)  // <T> : template argument list
////{
////	for (int i = 0; i < size - 1; ++i)
////	{
////		for (int j = 0; j < size - i - 1; ++j)
////		{
////			if (compare(arr[j] , arr[j + 1]))
////			{
////				T temp = move(arr[j]);
////				arr[j] = move(arr[j + 1]);
////				arr[j + 1] = move(temp);
////			}
////		}
////	}
////}
//
//template<typename T, int size, typename callback>  // we can pass function pointer/ function ober or even a lambda function
//void bubblesort(T (&arr)[size], callback compare)  // <T> : template argument list
//{
//	for (int i = 0; i < size - 1; ++i)
//	{
//		for (int j = 0; j < size - i - 1; ++j)
//		{
//			if (compare(arr[j] , arr[j + 1]))
//			{
//				T temp = move(arr[j]);
//				arr[j] = move(arr[j + 1]);
//				arr[j + 1] = move(temp);
//			}
//		}
//	}
//}
//
////template<typename T>
////bool ascending(T x, T y)
////{
////	return x > y;
////}
//
//bool ascending(int x, int y)
//{
//	return x > y;
//}
//
//struct Asc {
//	bool operator()(int x, int y) {     // function call operator
//		return x > y;
//	}
//};
//
//int main()
//{
//	int A[] = { 3,2,1,5,6,4,12,44,67,21,13,31,55 };
//	int size = sizeof(A) / sizeof(int);
//	std::cout << "\nPrinting before sorting:\n ";
//	for (int i = 0; i < size; ++i)
//		std::cout << A[i] << "  ";
//	cout << endl;
//	//bubblesort(A, &ascending);
//	bubblesort(A, Asc());
//	std::cout << "Printing after sorting: ";
//	for (int i = 0; i < size; ++i)
//		std::cout << A[i] << "  ";
//	
//	cout << endl;
//	system("pause");
//	return 0;
//
//
//}