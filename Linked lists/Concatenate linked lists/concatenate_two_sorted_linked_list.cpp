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
	Node *get_head();
	Node concatenate(Node, Node);
};
Node *Node::get_head()
{
	return head;
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
// int concatenate(Node n1)
// {
// 	n1.display();
// 	return 0;
// }
Node Node::concatenate(Node n1, Node n2)
{
	Node n3;
	if (!(n1.isEmpty()) && !(n2.isEmpty()))
	{
		Node *traveller1 = n1.get_head();
		Node *traveller2 = n2.get_head();

		//travelling through each node and pushing data into another node
		while (traveller1->next != NULL)
		{
			n3.push(traveller1->data);
			traveller1 = traveller1->next;
		}
		n3.push(traveller1->data);

		//travelling through each node and pushing data into another node
		while (traveller2->next != NULL)
		{
			n3.push(traveller2->data);
			traveller2 = traveller2->next;
		}
		n3.push(traveller2->data);
		return n3;
	}
	cout << "Sorry, NULL list cannot be concatenated.";
	return n3;
}
int main()
{
	Node n1, n2;
	Node n3;

	for (int i = 1; i <= 5; i++)
		n1.push(i);
	for (int i = 1; i <= 5; i++)
		n2.push(i * 2);

	n1.display();
	n2.display();

	n3 = n3.concatenate(n1, n2);
	n3.display();

	return 0;
}