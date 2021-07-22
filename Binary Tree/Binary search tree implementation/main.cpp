#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<stdlib.h>
#include <vector>

using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
} Node;

Node *root = NULL;

void insert(Node **root, int given_data);
Node *createNode(int given_data);
void printPostOrder(Node *root);
bool searchData(Node *root, int given_data);
void pop(Node **root, int given_data);
int find_max(Node *root);
int menu(void);

int main()
{
	while (true)
	{
		int choice = menu();
		int data;

		switch(choice){
			case 1:
			cout << "Enter the data to insert: ";
			cin >> data;
			insert(&root, data);
			cout << "Insertion successful" << endl;
			break;

			case 2:
			cout << "Enter the number to search: ";
			cin >> data;
			if (searchData(root, data))
				cout << "Congratulations, " << data << " was found." << endl;
			else
				cout << "Sorry!! " << data << " was not found." << endl;
			break;

			case 3:
			cout << "Enter the data to remove: ";
			cin >> data;
			pop(&root, data);
			cout << data << " was successfully removed. " << endl;
			break;

			case 4:
			printPostOrder(root);
			break;

			case 5:
			exit(0);

			default:
			cout << "Invalid character" << endl;
			break;
		}
	}

	return 0;
}
int menu(void)
{
	int n;

	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "1. Insert data." << endl;
	cout << "2. Search for a data." << endl;
	cout << "3. Remove a data." << endl;
	cout << "4. Display the data(Post-order)." << endl;
	cout << "5. Exit" << endl;


	cout << "\nEnter your choice: ";
	cin >> n;

	return n;
}
void pop(Node **root, int given_data)
{
	if (given_data < (*root)->data)
		pop(&((*root)->left), given_data);

	else if (given_data > (*root)->data)
		pop(&((*root)->right), given_data);

	else if (given_data == (*root)->data)
	{
		// leaf node
		if ((*root)->left == NULL && (*root)->right == NULL)
		{
			delete (*root);
			*root = NULL;
			return;
		}

		// if left side is null and right side has a subtree
		else if ((*root)->left == NULL)
		{
			auto temp = *root;
			*root = (*root)->right;
			free(temp);
		}

		// if right side is null and left side has a subtree
		else if ((*root)->right == NULL)
		{
			auto temp = *root;
			*root = (*root)->left;
			free(temp);
		}

		// if the node has subtree on both left and right children
		else
		{
			int max = find_max((*root)->left);
			(*root)->data = max;
			pop(&((*root)->left), max);
		}
	}
}
int find_max(Node *root)
{
	if (root->right == NULL)
		return (root->data);
	return (find_max(root->right));
}
bool searchData(Node *root, int given_data)
{
	if (given_data == root->data)
		return true;

	if (root == NULL)
		return false;

	if (given_data <= root->data)
		return (searchData(root->left, given_data));

	else
		return (searchData(root->right, given_data));
}

void printPostOrder(Node *root)
{
	if (root == NULL)
		return;

	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}
Node *createNode(int given_data)
{
	auto new_node = new Node;

	new_node->data = given_data;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void insert(Node **root, int given_data)
{

	// if we reach at the end
	if (*root == NULL)
	{
		auto new_node = createNode(given_data);
		*root = new_node;
	}

	// go left
	else if (given_data <= (*root)->data)
		insert(&((*root)->left), given_data);

	// go right
	else
		insert(&((*root)->right), given_data);

}
