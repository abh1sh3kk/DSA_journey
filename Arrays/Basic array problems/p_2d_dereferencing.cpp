/*Write a program that prints 3x2 matrices and print the result in matrix form using pointer */ 
#include <iostream>
using namespace std;
int main()
{
    int row = 3, column = 2;
    int arr1[row][column], arr2[row][column];
    int sum[row][column];

    cout << "Enter the elements of 1st matrix: " << endl;
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            cout << "Row " << i+1 << " Column " << j+1 << " : ";
            cin >> *(*(arr1+i)+j);
        }
    }

    cout << endl;

    cout << "Enter the elements of 2nd matrix: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            cout << "Row " << i+1 << " Column " << j+1 << " : ";
            cin >> *(*(arr2+i)+j);
        }
    }

    cout << "The sum of the arrays is: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            *(*(sum+i)+j) = *(*(arr1+i)+j) + *(*(arr2+i)+j);
            cout << *(*(sum+i)+j) << "   ";
        }
        cout << endl;
    }

    return 0;
}