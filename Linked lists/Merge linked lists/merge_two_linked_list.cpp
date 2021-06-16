#include <iostream>
using namespace std;
class Node
{
private:
	int data;
	Node *next;

public:
	Node *head = NULL;
	Node *tail = NULL;
	Node *createNode(int given_data);
	void push(int given_data);
	void pop(int given_data);
	void display();
	bool isEmpty();
	// void merge(Node, Node);
	void merge(Node n1, Node n2);
	void set_head(Node *head);
};
void Node::merge(Node n1, Node n2)
{
	if (n1.isEmpty() || n2.isEmpty())
	{
		cout << "Can't deal with empty list" << endl;
		exit(0);
	}

	// traveller is a temporary variable who traverse the list.. 
	Node *traveller = n1.head;
	
	while(traveller->next != NULL)
	{
		traveller = traveller->next;  // if the nodes aren't empty...
	}

	//head of n2 is joined with tail of n1
	traveller->next = n2.head;
}
void Node::pop(int given_data)
{

	Node *to_deallocate;
	Node *traveller = head;

	if (isEmpty())
	{
		cout << "There is nothing to pop.." << endl;
	}
	else if (head->data == given_data)
	{
		to_deallocate = head;
		head = head->next;
		free(to_deallocate);
	}
	else
	{
		while (traveller->next->data != given_data)
		{
			if (traveller == NULL)
			{
				cout << "Element not found" << endl;
				return;
			}
			traveller = traveller->next;
		}

		to_deallocate = traveller->next;
		traveller->next = traveller->next->next;

		free(to_deallocate);
	}
}
bool Node::isEmpty()
{
	return (head == NULL ? 1 : 0);
}
Node *Node::createNode(int given_data)
{
	Node *new_node = new Node;
	new_node->data = given_data;
	new_node->next = NULL;
	return new_node;
}
void Node::push(int given_data)
{
	Node *new_node = createNode(given_data);
	if (isEmpty())
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		Node *traveller = head;
		while (traveller->next != NULL)
		{
			traveller = traveller->next;
		}
		traveller->next = new_node;
		tail = tail->next;
	}
}
void Node::display()
{
	Node *traveller = head;

	while (traveller != NULL)
	{
		cout << traveller << " || " << traveller->data << "|" << traveller->next << "||" << endl;
		traveller = traveller->next;
	}
	cout << endl;
}
int main()
{
	Node n1, n2;

	for (int i = 1; i <= 5; i++)
		n1.push(i);
	for (int i = 1; i <= 5; i++)
		n2.push(i * 2);

	n1.display();
	n2.display();

	n1.merge(n1, n2);
	n1.display();


	return 0;
}