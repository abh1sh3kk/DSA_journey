#include <iostream>
#include <conio.h>
using namespace std;
#define n 5
#define high 2
#define low 0
class Stack
{
private:
    int arr1[n];
    int top = -1;

public:
    void push(int a)
    {
        if (top == n - 1)
        {
            cout << "Stack is full!!!" << endl;
            return;
        }
        else if(top == -1 || arr1[top] > a) 
            arr1[++top] = a;
        else
            cout << "The value can't be pushed" << endl;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!!" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        return arr1[top];
    }
    void display()
    {
        for (int i = top; i >= low; i--)
        {
            cout << "| " << arr1[i] << " |" << endl;
        }
    }
    void transfer(Stack a)
    {
        a.push(arr1[top]);
    }
};
int main()
{
    Stack s1, s2, s3;

    for (int i = high; i >= low; i--)
        s1.push(i + 1);

    

    // cout << "s1" << endl;
    // s1.display();
    return 0;
}