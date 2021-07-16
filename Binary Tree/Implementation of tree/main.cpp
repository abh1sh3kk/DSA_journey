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

<<<<<<< HEAD
public:
	Node *root = NULL;
	Node *createNode(int given_data);
	void insert(int given_data);
	void printInOrder(Node *root);
};
void Node::printInOrder(Node* root)
=======
	printInOrder(root);
	
	return 0;
}
void printInOrder(Node *root)
>>>>>>> herum_k_hunxa
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}
<<<<<<< HEAD
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
=======
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
>>>>>>> herum_k_hunxa
{
	Node *new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
<<<<<<< HEAD
}
int main()
{
	Node n1;

	n1.insert(10);
	n1.insert(45);
	n1.printInOrder(n1.root);
}
=======
}
>>>>>>> herum_k_hunxa
