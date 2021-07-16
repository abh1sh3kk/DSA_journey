#include <iostream>
using namespace std;


typedef struct Node
{
	int data;
	Node *left;
	Node *right;
}Node;

Node *createNode(int given_data);
void insert(Node **root, int given_data);
void printInOrder(Node *root);


int main()
{
	Node* root = NULL;

	insert(&root, 10);
	insert(&root, 45);
	insert(&root, 34);
	insert(&root, 6);
	insert(&root, 8);
	insert(&root, 2);

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
void insert(Node** root, int given_data)
{
	if (*root == NULL)
	{
		Node *new_node = createNode(given_data);
		*root = new_node;
	}
	else if (given_data <= (*root)->data)
	{
		insert(&((*root)->left), given_data);
	}
	else
	{
		insert(&((*root)->right), given_data);
	}
}
Node *createNode(int given_data)
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}
