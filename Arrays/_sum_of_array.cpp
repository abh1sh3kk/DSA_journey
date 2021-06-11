/* Program to read n numbers in array and display their sum and average */
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int num;
    int arr[100];
    int count = 0;
    int sum = 0;

    cout << "How many numbers? ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter element no. " << i + 1 << ": ";
        cin >> arr[i];
        sum = sum + arr[i];
        count++;
    }

    cout << "The sum is " << sum << endl;
    cout << "And the average is " << sum / count << endl;
    getch();
    return 0;
}