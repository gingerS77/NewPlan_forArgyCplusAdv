#include <iostream>
using namespace std;
// new line added on 17th March 
// lambda function, anonymous function objects....

//  [](){}      ;  [capture list] (parameters) -> {body of the function}

int main()
{
	//[]() {
	//	cout << "hello lambda"<< endl;
	//}();       // using function call operator, we invoke the lambda function. 

	auto sum = [](int x, int y) -> int {  // if the parameters are of same type as its return type, then its optional to specify the return type for the lambda function using the arrow operator..
		return x + y;
	};

	int res = sum(4,5);
	cout << "res = " << res << endl;

	system("pause");
	return 0;
}