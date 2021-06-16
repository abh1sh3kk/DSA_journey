#include <iostream>
using namespace std;
int fibo(int n);
int main()
{
	int n = 5;
	for (int i = 0; i <= n; i++)
	{
		cout << fibo(i) << endl;
	}
	return 0;
}
int fibo(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return (fibo(n - 1) + fibo(n - 2));
}
