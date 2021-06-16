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
	void reverse_list();
};
void Node::reverse_list()
{
	if (!isEmpty())
	{
		Node *pre_node, *curr_node, *next_node;

		pre_node = NULL;
		curr_node = head;
		next_node = head->next;

		while (curr_node != NULL)
		{
			//current node pointing to previous node
			curr_node->next = pre_node;

			//updating pre_node, curr_node and next_node values
			pre_node = curr_node;
			curr_node = next_node;
			if (next_node != NULL)
				next_node = next_node->next;
		}
		//updating head at the end
		head = pre_node;
	}
	else
	{
		std::cout << "There is nothing to reverse ... " << std::endl;
		return;
	}
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
	for (Node *traveller = head; traveller != NULL; traveller = traveller->next)
	{
		// std::cout<< traveller << "|| " << traveller->data << "| " << traveller->next << " ||" << std::endl;
		std::cout << traveller->data << " "; 
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
	std::cout << std::endl << std::endl;
	std::cout << "Before reversing... " <<std::endl;
	n1.display();
	n1.reverse_list();
	std::cout << std::endl << std::endl;
	std::cout << "After reversing... " << endl <<endl;
	n1.display();
	return 0;
}