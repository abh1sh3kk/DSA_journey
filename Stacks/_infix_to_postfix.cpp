#include <iostream>
#include<conio.h>
#include <string>
#define n 30
using namespace std;
class Stack
{
    public:
    int top;
    char arr1[n];  
    Stack()
    {
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

    //creating two stacks
    Stack opstack;
    Stack popstack;

    //iterating through each character and performing actions accordingly
    for (int i=0; i<infix.length(); i++) {

        // checking for A-Z or a-z (operand) and pushing it to popstack
        if ((int(infix[i])>64 && int(infix[i])<91) || (int(infix[i])>96 && int(infix[i])<123)) 
            popstack.push(infix[i]);   

        // checking for operators (anything except ')' ) and pushing it to opstack
        else if (infix[i] != ')')
            opstack.push(infix[i]);

        // if infix[i] == ')' 
        else {
            popstack.push(opstack.top_value());  
            opstack.pop();
            opstack.pop();
        }
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "The postfix of " << infix << " is ";
    popstack.show();
    cout << endl;
    cout << endl;
    cout << endl;
    getch();
    return 0;
} 