#include <iostream>
using namespace std;
int sum(int a);
int main()
{
	cout << "Sum upto 5 is " << sum(100) << endl;
	return 0;
}
int sum(int a)
{
	if (a == 1)
		return 1;
	else
	{
		return sum(a-1) + a;
	}
}
