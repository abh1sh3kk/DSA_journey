/* program to print numbers from n to 1 using recursion */
#include<iostream>
using namespace std;
void print_num(int a);
int main()
{
print_num(20);
  return 0;
}
void print_num(int a)
{
	if (a == 0)
		return;
	else{
		cout << a << " ";
		print_num(a-1);
	}
}