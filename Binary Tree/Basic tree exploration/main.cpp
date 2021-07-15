#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;

public:
	Node *root = NULL;
	Node *createNode(int given_data);
	void insert(int given_data);
	void printInOrder(Node *root);
};
void Node::printInOrder(Node* root)
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}
void Node::insert(int given_data)
{
	//preserve the root
	Node *temp = root;

	// if root doesn't exist, create one
	if (root == NULL)
	{
		Node* new_node = createNode(given_data);
		root = new_node;
		return;
	}

	// if given data is less than root data, change the value of root to root->left
	if (given_data < root->data)
	{
		root = root->left;
	}

	// if given data is more than root data, change the value of root to root->right
	else
	{
		root = root->right;
	}
	insert(given_data);
	root = temp;
}
Node *Node::createNode(int given_data)
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}
int main()
{
	Node n1;

	n1.insert(10);
	n1.insert(45);
	n1.printInOrder(n1.root);
}
