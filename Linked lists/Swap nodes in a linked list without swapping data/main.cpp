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
	void append(int given_data);
	void remove(int given_data);
	void display();
	Node *createNode(int);
	bool isEmpty();
	void reverse_node(int a, int b);
};
void Node::reverse_node(int a, int b)
{
	// making a temporary helper node 
	Node* node_zero = createNode(5);
	node_zero->next = head;

	// pointers that point the nodes to be swapped
	Node* traveller1 = node_zero;
	Node* traveller2 = node_zero;

	// Finding the nodes that points the nodes to be swapped
	while(traveller1->next->data != a)
	{
		if (traveller1->next->next == NULL)
		{
			cout << a << " was not found." << endl;
			exit(0);
		}
		traveller1 = traveller1->next;
	}
	while(traveller2->next->data != b)
	{
		if(traveller2->next->next == NULL)
		{
			cout << b << " was not found." << endl;
			exit(0);
		}
		traveller2 = traveller2->next;
	}

	// Swapping the data first
	int temp_for_data_swap;
	temp_for_data_swap = traveller1->next->data;
	traveller1->next->data = traveller2->next->data;
	traveller2->next->data = temp_for_data_swap;

	// temporary variables for preserving the addresses
	Node* temp1 = traveller1->next;			// keeping the 1st node safe
	Node* temp2 = traveller2->next->next;		// keeping the next node of 2nd node safe

	// the main process
	traveller1->next = traveller2->next;		// bringing the 2nd node in place of 1st
	traveller2->next->next = temp1->next;		// finishing that process
	traveller2->next = temp1;			// bringing the 1st node in place of 2nd
	temp1->next = temp2;				// finishing up that process

	head = node_zero->next;
	free(node_zero);
}
Node *Node::createNode(int given_data)
{
	
	Node *new_node = new Node;
	new_node->data = given_data;
	new_node->next = NULL;
	return new_node;
}
bool Node::isEmpty()
{
	if (head == NULL)
		return 1;
	return 0;
}
void Node::append(int given_data)
{
	Node *new_node = createNode(given_data);
	if (isEmpty())
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = tail->next;
	}
}
void Node::remove(int given_data)
{
	if (isEmpty())
	{
		std::cout << "There is no node. " << std::endl;
		return;
	}
	for (Node *traveller = head; traveller != tail; traveller = traveller->next)
	{
		if (traveller->next->data == given_data)
		{
			Node *node_to_free = traveller->next;
			traveller->next = traveller->next->next;
			free(node_to_free);
			return;
		}
	}
}
void Node::display()
{
	if(isEmpty())
	{
		cout << "The list is empty.. " << endl;
		exit(0);
	}
	for (Node *traveller = head; traveller != NULL; traveller = traveller->next)
	{
		std::cout<< traveller << "|| " << traveller->data << "| " << traveller->next << " ||" << std::endl;
		// std::cout << traveller->data << " ";
	}
	std::cout << std::endl;
}

int main()
{
	Node n1;

	n1.append(69);
	n1.append(68);
	n1.append(67);
	n1.append(66);
	n1.append(65);

	n1.display();

	n1.reverse_node(65, 69);

	n1.display();

	return 0;
}