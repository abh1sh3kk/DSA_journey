#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *prev;
	Node *next;
} Node;

void append(Node **head, int given_data);
void display(Node **head);
Node *createNode(int given_data);
void pop(Node **head, int given_data);

int main()
{
	Node *head = NULL;

	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	append(&head, 8);
	pop(&head, 8);
	display(&head);

	return 0;
}
void pop(Node **head, int given_data)
{

	// checking whether the list is empty or not..
	if (*head == NULL)
	{
		cout << "The list is empty.. " << endl;
		return;
	}

	// so the list is not empty.. now we start transversing the list
	Node *traveller = *head;

	// navigating the element to be popped
	while (traveller->data != given_data)
	{

		// if traveller is in last node and data is not still found.. invalid message is shown
		if (traveller->next == NULL)
		{
			cout << "Sorry the data is invlid!!!" << endl;
			return;
		}

		// since traveller is not in last node.. we push traveller forward
		traveller = traveller->next;

	}

	// if the elements to be popped is in 1st position
	if(traveller->prev == NULL)
	{
		traveller->next->prev = *head;
		*head = traveller->next;
		free(traveller);
		return;	
	}


	// if the element to be popped is in last position
	if(traveller->next == NULL)
	{
		traveller->prev->next = NULL;
		free(traveller);
		return;
	}
	traveller->prev->next = traveller->next;
	traveller->next->prev = traveller->prev;
	free(traveller);
}

Node *createNode(int given_data)
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}
void display(Node **head)
{
	Node *traveller = *head;

	while (traveller != NULL)
	{
		cout << traveller << "||" << traveller->prev << "|--> " << traveller->data << " <--|" << traveller->next << "||" << endl;
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