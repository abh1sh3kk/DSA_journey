#include <iostream>
using namespace std;
#define N 20
class Stack
{
private:
    char arr[N];
    int top = -1;

public:
    void push(char given_char);
    void pop();
    void display();
    bool isEmpty();
    bool isFull();
};
bool Stack::isFull()
{
    return top == N - 1 ? 1 : 0;
}
bool Stack::isEmpty()
{
    return top == -1 ? 1 : 0;
}
void Stack::push(char given_char)
{
    if (isFull())
    {
        cout << "The stack is full." << endl;
        return;
    }
    arr[++top] = given_char;
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "The stack is empty." << endl;
        return;
    }
    top--;
}
void Stack::display()
{
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
        return;
    }
    for (int i = top; i <= 0; i--)
    {
        cout << "| " << arr[i] << " |" << endl;
    }
}
int main()
{
    Stack s1;

    s1.display();
    return 0;
}