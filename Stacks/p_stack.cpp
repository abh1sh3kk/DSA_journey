#include <iostream>
#define n 5
using namespace std;
class Stack{
    public:
        int arr1[n];
        int top = -1;
        void push(int);
        void pop();
        void show();
};
void Stack::push(int a) {
        if (top == n-1){
            cout << "Stack is full!!" << endl;
            return;
        }
        top++;
        arr1[top] = a;
}
void Stack:: show() {
        cout << "The value of top is " << top << endl;
        for (int i = 0; i<=top; i++) {
            cout << arr1[i] << endl;
        }
    }
void Stack::pop(){
        if (top == -1){
            cout << "The stack is empty!!!" << endl;
            return;
        }
        top--;
    }
int main()
{
    Stack s1;
    s1.pop();
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.push(5);
    s1.show();

    return 0;
}