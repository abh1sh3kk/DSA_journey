#include <iostream>
#include <string>
using namespace std;
#define N 25
bool isOperand(char ch);
bool isOperator(char ch);
int precedence(char a);
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
    char topppp();
};
bool Stack::isFull()
{
    return (top == N - 1) ? 1 : 0;
}
bool Stack::isEmpty()
{
    return (top == -1) ? 1 : 0;
}
void Stack::push(char given_char)
{
    if (isFull())
    {
        std::cout << "The Stack is full." << std::endl;
        exit(1);
    }
    arr[++top] = given_char;
}
char Stack::topppp()
{
    return arr[top];
}
void Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "The Stack is empty." << std::endl;
        exit(1);
    }
    top--;
}
void Stack::display()
{
    if (isEmpty())
    {
        std::cout << "The Stack is empty" << std::endl;
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        std::cout << "| " << arr[i] << " |" << std::endl;
    }
}
bool isOperand(char ch)
{
    // if ((int(ch) == (0 - 9) || int(ch) == (A-Z) || int(ch) == (a - z) ||
    if ((ch > 47 && ch < 58) || (ch > 64 && ch < 91) || (ch > 96 && ch < 123))
        return 1;
    return 0;
}
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(')
        return 1;
    return 0;
}
int precedence(char a)
{
    if (a == '(')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else if (a == ')')
        return 0;
    else
    {
        return 5;
    }
}
int main()
{
    Stack opstack, alpha;
    char given_data[] = "(A+B/C-E)^F";
    for (int i = 0; i <= 10; i++)
    {
        cout << "0th index " << given_data[i] << endl;
        if (isOperator(given_data[i]))
        {
            while (precedence(given_data[i] <= precedence(opstack.topppp())))
            {
                alpha.push(opstack.topppp());
                opstack.pop();
            }
            opstack.push(given_data[i]);
        }
        else if (isOperand(given_data[i]))
        {
            alpha.push(given_data[i]);
        }
        else 
        {
            cout << "Invalid Character!!" << endl;
            exit(1);
        }
    }
    return 0;
}