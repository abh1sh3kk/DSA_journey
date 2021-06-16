#include <iostream>
#define n 10
using namespace std;
class Queue
{
private:
    int arr[n];
    int rear = -1;
    int front = -1;

public:
    void enqueue(int);
    void dequeue();
    bool isEmpty();
    void display();
};
void Queue::enqueue(int a)
{
    if (isEmpty())
    {
        arr[++rear] = a;
        ++front;
        return;
    }
    else if (rear == n - 1)
    {
        cout << "The Queue is full." << endl;
        return;
    }
    arr[++rear] = a;
};
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "The Queue is empty." << endl;
        return;
    }
    else if (rear == front)
    {
        cout << "Now the queue became empty." << endl;
        rear = front = -1;
    }
    else
    {
        front++;
    }
};
void Queue::display()
{
    cout << "-----------" << endl;
    for (int i = front; i <= rear ; i++)
        cout << "  " << arr[i];
    cout << endl;
    cout << "----------";
};
bool Queue::isEmpty()
{
    if (rear == -1 && front == -1)
        return 1;
    return 0;
};
