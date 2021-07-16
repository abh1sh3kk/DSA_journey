#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
} Node;

Node *createNode(int given_data);
void insert(Node **root, int given_data);
void printInOrder(Node *root);
bool containsData(Node *root, int given_data);

int main()
{
	Node *root = NULL;

	insert(&root, 10);
	insert(&root, 45);
	insert(&root, 34);
	insert(&root, 6);
	insert(&root, 8);
	insert(&root, 2);

	// printInOrder(root);
	cout << containsData(root, 99) << endl;

	return 0;
}
bool containsData(Node *root, int given_data)
{


	// if root reaches end or the tree is empty return false
	if (root == NULL)
		return false;


	// if the data is found return true
	if (given_data == root->data)
		return true;


	// self explanatory
	if (given_data < root->data)
		return (containsData(root->left, given_data));
		

	// if given data is more than root->data
	else
		return (containsData(root->right, given_data));

}
void printInOrder(Node *root)
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}
void insert(Node **root, int given_data)
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
