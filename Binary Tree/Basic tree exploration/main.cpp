#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;

public:
	Node* head = NULL;
	Node* createNode(int given_data);
	Node* insertLeft(int given_data);
}
Node* Node::createNode(int given_data)
{
	Node* new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

int main()
{

}
