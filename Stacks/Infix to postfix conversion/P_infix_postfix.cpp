#include <iostream>
#include <string>
#define n 20
using namespace std;
class Stack
{
    public:
    int top;
    char arr1[n];  
    Stack()
    {
        //to see whether stack is created or not
        cout << "Stack has been created." << endl;

        top = -1;
    }
        void push(char);
        void pop();
        void show();
        char top_value();
};
char Stack::top_value()
{   
    return arr1[top];
}
void Stack::push(char a) {
        if (top == n-1){
            cout << "Stack is full!!" << endl;
            return;
        }
        top++;
        arr1[top] = a;
        // cout << a << " was pushed successfully in " << top << endl;
}
void Stack:: show() {
        for (int i = 0; i<=top; i++) {
            cout << arr1[i];
        }
    }
void Stack::pop(){
        if (top == -1){
            cout << "The stack is empty!!!" << endl;
            return;
        }
        top--;
    }
int main() {
    string infix = "(((A-(B+C))*D)$(E+F))";

    //checking infix
    cout << "infix = " << infix << endl;

    Stack opstack;
    Stack popstack;

    for (int i=0; i<infix.length(); i++) {
        if ((int(infix[i])>64 && int(infix[i])<91) || (int(infix[i])>96 && int(infix[i])<123))
        {
            cout << "infix[i] = " << infix[i] << " and int(infix[i]) = " << int(infix[i]) << endl;
            popstack.push(infix[i]);
        }
        else if (int(infix[i]) != 41)
        {
            cout << "infix[i] = " << infix[i] << " and int(infix[i]) = " << int(infix[i]) << endl;
            opstack.push(infix[i]);
        }
        else{
            cout << "infix[i] = " << infix[i] << " and int(infix[i]) = " << int(infix[i]) << endl;
            popstack.push(opstack.top_value());
            opstack.pop();
            opstack.pop();
        }
    }
    popstack.show();
    return 0;
}