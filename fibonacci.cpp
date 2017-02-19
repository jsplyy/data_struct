// 0 n=0
// f(n)= 1 n=1
// f(n-1)+f(n-2) n=2

/*
关于fibonacci数列的思考：
递归实现 O(2^n)
非递归实现 O(n)
O(logN)
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

long long fibonacciLoop(int n);
string fibonacciLoopSequence(int n);
string toString(long long i);
long long fibonacciRecursion(int n);
long long fibonacciTailRecursion(int n, long long acce1, long long acce2);

int main()
{
	cout << fibonacciLoopSequence(10);
	cout<<toString(100)<<endl;
	cout << fibonacciRecursion(10)<<endl;
	cout << fibonacciTailRecursion(3,0,1);
	return 0;
}

long long fibonacciLoop(int n)
{
	long long result[2]={0,1}, current = 0;

	if(n<2)
	{
		return result[n];
	}

	for (int i = 2; i <= n; i++)
	{
		current = result[1] + result[0];
		result[0] = result[1];
		result[1] = current;
	}

	return current;

}

long long fibonacciRecursion(int n)
{
	int result[2] = {0,1};
	if (n<2)
	{
		return result[n];
	}

	return fibonacciRecursion(n-1) + fibonacciRecursion(n-2);
}

long long fibonacciTailRecursion(int n, long long acce1, long long acce2)
{
	if (n == 0)
	{
		return acce1;
	}

	return fibonacciTailRecursion(n-1, acce2, acce1 + acce2);
}

string toString(long long i)
{
	stringstream ss;
	string temp = "";
	ss << i;
	temp = ss.str();
	return temp;
}

string fibonacciLoopSequence(int n)
{
	long long result[2]={0,1}, current = 0;
	string fibonacciSequence = "";

	if(n<2)
	{
		fibonacciSequence=fibonacciSequence + toString(result[n]);
	}

	fibonacciSequence = toString(result[0]) + ' ' + toString(result[1]);
	for (int i = 2; i <= n; i++)
	{
		current = result[1] + result[0];
		result[0] = result[1];
		result[1] = current;
		fibonacciSequence =  fibonacciSequence + ' ' + toString(current);
	}

	return fibonacciSequence + '\n';
}