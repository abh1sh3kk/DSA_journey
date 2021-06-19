#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *prev;
	Node *next;
}Node;

void append(int given_data);
void display();
Node* createNode(int given_data);

Node *head = NULL;

int main()
{
	Node n1;

	append(5);
	append(6);
	append(7);
	append(8);
	
	display();

	return 0;
}
Node* createNode(int given_data)
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}
void display()
{
	Node *traveller = head;

	while (traveller != NULL)
	{
		cout << traveller << "||" << traveller->prev << "|" << traveller->data << "|" << traveller->next << "||" << endl;
		traveller = traveller->next;
	}
}
void append(int given_data)
{

	Node *new_node = createNode(given_data);

	if (head == NULL)
	{
		head = new_node;
		return;
	}

	Node *traveller = head;
	while (traveller->next != NULL)
	{
		traveller = traveller->next;
	}
	traveller->next = new_node;
	new_node->prev = traveller;
}