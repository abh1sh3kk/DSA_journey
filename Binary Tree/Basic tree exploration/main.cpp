#include <iostream>
using namespace std;


typedef struct Node
{
	int data;
	Node *left;
	Node *right;
}Node;


Node *createNode(int given_data);
Node *insert(Node *root, int given_data);
void printInOrder(Node *root);


int main()
{
	Node* root = NULL;

	root = insert(root, 10);
	root = insert(root, 45);
	root = insert(root, 34);
	root = insert(root, 12);
	root = insert(root, 56);
	root = insert(root, 27);
	root = insert(root, 10);

	printInOrder(root);
	
	return 0;
}
void printInOrder(Node *root)
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}
Node* insert(Node* root, int given_data)
{
	if (root == NULL)
	{
		// Node *new_node = createNode(given_data);
		// root = new_node;
		// return root;

		return createNode(given_data);
	}
	else if (given_data <= root->data)
	{
		root->left = insert(root->left, given_data);
	}
	else
	{
		root->right = insert(root->right, given_data);
	}
	return root;
}
Node *createNode(int given_data)
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}