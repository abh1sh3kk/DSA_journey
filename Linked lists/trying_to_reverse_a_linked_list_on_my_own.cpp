#include <iostream>
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
	bool isEmpty();
	Node* createNode(int);
};
Node* Node::createNode(int given_data)
{
	Node *new_node = new Node;
	new_node->data = given_data;
	new_node->next = NULL;
	return new_node;
}
bool Node::isEmpty()
{
	return head == NULL ? 1 : 0;
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
		std::cout<< "There is no node. " << std::endl;
		return;
	}
	for (Node *traveller = head; traveller != tail; traveller = traveller->next)
	{
		if ( traveller->next->data == given_data)
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
	for(Node *traveller = head; traveller != NULL; traveller = traveller->next)
	{
		std::cout << traveller->data << std::endl;
		// std::cout<< traveller << "|| " << traveller->data << "| " << traveller->next << " ||" << std::endl;
	}
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

	return 0;
}