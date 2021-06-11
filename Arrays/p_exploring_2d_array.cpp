/*Write a program that prints 3x2 matrices and print the result in matrix form using pointer */ 
#include <iostream>
using namespace std;
int main()
{
    int row = 3, column = 3;


    int arr1[row][column] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // cout << "Enter the elements of 1st matrix: " << endl;
    // for (int i=0; i<row; i++)
    // {
    //     for(int j=0; j<column; j++)
    //     {
    //         cout << "Row " << i+1 << " Column " << j+1 << " : ";
    //         cin >> arr1[i][j];
    //     }
    // }
    cout << "Enter the value: ";
    cin >> *(*(arr1+1)+1); 
     cout << "*(*(arr1+1)+1)= " << *(*(arr1+1)+1) << endl;
     cout << "*(*(arr1+2)+2)= " << *(*(arr1+2)+2) << endl;

    return 0;
}