#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *prev;
	Node *next;
}Node;

void append(Node **head, int given_data);
void display(Node *head);
Node* createNode(int given_data);

int main()
{
	Node *head = NULL;

	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	append(&head, 8);
	
	display(head);

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
void display(Node* head)
{
	Node *traveller = head;

	while (traveller != NULL)
	{
		cout << traveller << "||" << traveller->prev << "|" << traveller->data << "|" << traveller->next << "||" << endl;
		traveller = traveller->next;
	}
}
void append(Node **head, int given_data)
{

	Node *new_node = createNode(given_data);

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	Node *traveller = *head;
	while (traveller->next != NULL)
	{
		traveller = traveller->next;
	}
	traveller->next = new_node;
	new_node->prev = traveller;
}