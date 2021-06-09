#include <iostream>
class Node
{
private:
    int data;
    Node *next;

public:
    Node *head = NULL;
    Node *start = NULL;
    void insertAfter(int, int);
    Node *createNode(int);
    void append(int);
    void push(int);
    void display();
    void pop(int);
    bool isEmpty();
};
Node *Node::createNode(int given_data)
{
    Node *new_node = new Node;
    new_node->data = given_data;
    new_node->next = NULL;
    return new_node;
}
void Node::append(int given_data)
{
    if (head == NULL)
    {
        head = createNode(given_data);
        start = head;
    }
    else
    {
        Node *new_node = createNode(given_data);
        head->next = new_node;
        head = head->next;
    }
}
void Node::push(int given_data)
{
    if (head == NULL)
    {
        head = createNode(given_data);
        start = head;
    }
    else
    {
        Node *new_node = createNode(given_data);
        new_node->next = start;
        start = new_node;
    }
}
void Node::insertAfter(int index_data, int to_insert)
{
    for (Node *traveller = start; 1; traveller = traveller->next)
    {
        if (traveller->data == index_data)
        {
            Node *new_node = createNode(to_insert);
            new_node->next = traveller->next;
            traveller->next = new_node;
            return;
        }
    }
}
void Node::display()
{
    for (Node *traveller = start; traveller != NULL; traveller = traveller->next)
        std::cout << traveller << "\t||" << traveller->data << " |" << traveller->next << " ||" << std::endl;
}
bool Node::isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}
void Node::pop(int given_data)
{
    if (isEmpty())
    {
        std::cout << "The linked list is empty!!! " << std::endl;
        return;
    }
    else
    {
        Node *traveller = start;
        while (traveller->next->data != given_data)
        {
            if (traveller->next == NULL)
                return;
            traveller = traveller->next;
        }
        traveller->next = traveller->next->next;
        std::cout << given_data << " was deleted successfully." << std::endl;
    }
}
int main()
{
    Node n1;
    n1.append(69);
    n1.append(68);
    n1.append(66);
    n1.insertAfter(66, 65);
    n1.display();
    n1.pop(66);
    n1.display();
    return 0;
}