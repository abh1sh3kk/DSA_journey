#include <iostream>
class Node
{
	int data;
	Node *prev;
	Node *next;

public:
	Node *head = NULL;
	void push(int);
	// void append(int);
	// void insertAfter(int, int);
	// void delete (int);
	bool isEmpty();
	Node *createNode(int);
	void display();
};
bool Node::isEmpty() 
{
	return (head == NULL ? 1 : 0);
}
Node* Node::createNode(int given_data) 
{

	// Allocating the new node 
	Node *new_node = new Node;


	// Assigning the data, previous and next to the new node
	new_node->data = given_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}
void Node::push(int given_data)
{
	Node *new_node = createNode(given_data);
	if (isEmpty())
	{
		// joining head and the new node.. 
		head = new_node;
	}
	else{
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
}
void Node:: display()
{
	if (isEmpty())
	{
		std::cout << "The list is empty" << std::endl;
		exit(0);
	}
	Node *traveller = head;

	while (traveller != NULL)
	{
		std::cout << "||" << traveller->prev << "|" << traveller->data << "|" << traveller->next << "||" << std::endl;
		traveller = traveller->next; 
	}
}

int main()
{
	Node n1;

	n1.push(5);
	n1.push(6);
	n1.push(7);
	n1.push(8);
	n1.push(9);
	n1.push(10);

	n1.display();


	return 0;
}