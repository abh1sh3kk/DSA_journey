#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node *head = NULL;
    Node *start = NULL;
    void insert(int a);
    void pop();
    void display();
    void set_data(int);
    int get_data();

};
void Node::pop()
{
    cout << "Head->data : " << head->data << endl;
}
void Node::set_data(int given_data)
{
    data = given_data;
}
int Node::get_data()
{
    return data;
}
void Node::display()
{
    for (Node *traveller = start; traveller != NULL; traveller = traveller->next)
    {
        cout << traveller << " ||" << traveller->data << " |" << traveller->next << " ||" << endl;
    }
}
void Node::insert(int given_data)
{
    Node *node = new Node;
    node->data = given_data;
    node->next = NULL;
    // cout << "Head: " << head << endl;
    if (head == NULL)
    {
        // cout << "I am inside if.. " << endl;
        head = node;
        start = node;
    }
    else
    {
        // cout << "I am inside else.. " << endl;
        // cout << "Everything seems fine.. let's check." << endl;
        // cout << "head->next : " << head->next << " &node = " << node << endl;
        head->next = node;
        head = node;
        // cout << "After head->next = &node and head = &node; we have: " << endl;
        // cout << "head->next = " << head->next << " &node = " << node << endl;
    }
}
int main()
{
    Node l1;
    l1.insert(4);
    l1.insert(69);
    l1.insert(99);
    l1.insert(36);
    l1.display();
    l1.pop();

    return 0;
}