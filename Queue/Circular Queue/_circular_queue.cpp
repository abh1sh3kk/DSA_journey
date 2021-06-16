#include <iostream>
using namespace std;
#define n 5
class Queue
{
private:
    int rear = -1;
    int front = -1;
    int arr[n];

public:
    int rear_next(){return (rear + 1) % n;}
    int front_next() {return (front + 1) % n;}
    void enqueue(int a);
    void dequeue();
    void display();
    bool isEmpty();
};
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "The queue is empty" << endl;
        return;
    }
    else if (front == rear)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        arr[front] = 0;
        front = front_next();
    }
}
void Queue::enqueue(int a)
{
    if (isEmpty())
    {
        arr[rear_next()] = a;
        front = front_next();
        rear = rear_next();
    }
    else if (rear_next() == front)
        cout << "!!! The queue is full !!!" << endl;
    else
    {
        arr[rear_next()] = a;
        rear = rear_next();
    }
}
bool Queue::isEmpty()
{
    if (rear == -1 && front == -1)
        return 1;
    return 0;
}
void Queue::display()
{
    cout << "Front = " << front << " Rear = " << rear << endl;
    cout << "_______________" << endl;
    for (int i = front; i != rear; i=(i+1)%n)
        cout << arr[i] << " ";
    cout << arr[rear];
    cout << endl
         << "---------------" << endl;
}
int main()
{
    Queue q1;
    q1.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(8);
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(5);
    q1.enqueue(0);
    q1.enqueue(7);
    q1.enqueue(3);
    q1.display();
    return 0;
}