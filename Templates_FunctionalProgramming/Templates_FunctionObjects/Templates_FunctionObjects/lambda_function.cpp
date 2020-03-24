#include <iostream>
using namespace std;
// new line added on 17th March 
// lambda function, anonymous function objects....

//  [](){}      ;  [capture list] (parameters) -> {body of the function}

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback op)
{
	for (int i = 0; i < size; ++i)
		op(arr[i]);
}

int main()
{
	//[]() {
	//	cout << "hello lambda"<< endl;
	//}();       // using function call operator, we invoke the lambda function. 
	// generic or polymorphic lambdas , which has been introduce at the advent of C++14.
	int buffer[]{ 2,4,6,8,7 };
	
	int sum{}; // sum =0  ; uniform initialization
	auto s = [&buffer, &sum]() {
		for(int i=0; i < 5; ++i)
			sum += buffer[i];
	};

	s();
	cout << "Sum =  "  << sum << endl;
	ForEach(buffer, [](auto x) {
		cout << x << " ";
	});

	cout << endl;
	system("pause");
	return 0;
}

void lambda_ex1()
{
	auto sum = [](int x, int y) -> int {  // if the parameters are of same type as its return type, then its optional to specify the return type for the lambda function using the arrow operator..
		return x + y;
	};
	int y = 10;  // ignore this line
	int res = sum(4, 5);
	cout << "res = " << res << endl;
}

void lambda_ex2()
{
	auto sum = [](auto x, auto y) {  // if the parameters are of same type as its return type, then its optional to specify the return type for the lambda function using the arrow operator..
		return x + y;
	};
	auto res = sum('a', 'b');
	cout << "res = " << res << endl;
}

void lambda_ex3()
{
	int buffer[]{ 2,4,6,8,7 };
	cout << "Initially elements in the buffer : " << endl;
	ForEach(buffer, [](auto x) {
		cout << x << " ";
	});
	cout << endl;
	int fixed_no = 4;
	ForEach(buffer, [fixed_no](auto &x)mutable {
		x += fixed_no;
		++fixed_no;
	});
}