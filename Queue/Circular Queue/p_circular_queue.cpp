#include <iostream>
using namespace std;
#define n 5
class Queue
{
private:
    int rear = -1;
    int front = -1;
    int arr[n] = {0, 0, 0, 0, 0};

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
        cout << "isEmpty(): rear_next()= " << rear_next()<< endl;
        arr[rear_next()] = a;
        cout << "arr[rear_next()] = a: \t arr[rear_next()] = " << arr[rear_next()] << endl;
        front = front_next();
        rear = rear_next();
        cout << "After incrementing: " << front << " and " << rear << endl;
    }
    else if (arr[rear_next()] == 0)
    {
        cout << "else if: \tarr[rear_next()] = " << arr[rear_next()] << endl;
        cout << "rear_next()= " << rear_next()<< endl;
        arr[rear_next()] = a;
        cout << "a = " << a << " arr[rear_next()] = " << arr[rear_next()] << endl;
        rear = rear_next();
        cout << "rear is updated to " << rear << " and arr[1] = " << arr[1] << endl;
    }
    else
        cout << "!!! The queue is full !!!" << endl;
}
bool Queue::isEmpty()
{
    if (rear == -1 && front == -1)
        return 1;
    return 0;
}
void Queue::display()
{
    cout << "_______________" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl
         << "---------------" << endl;
}
int main()
{
    Queue q1;
    q1.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(8);
    q1.enqueue(5);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(9);
    q1.display();
    return 0;
}