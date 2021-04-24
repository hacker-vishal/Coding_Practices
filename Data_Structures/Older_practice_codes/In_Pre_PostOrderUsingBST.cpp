#include<iostream>
#include<string>
using namespace std;

/*
inputs   : 7,4,10,8,12,2,5

postorder :  2,5,4,8,12,10,7
pre-order  : 7,4,2,5,10,8,12
in-order   : 2,4,5,7,8,10,12
*/
namespace nm54
{

	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node(int data) :data(data), left(NULL), right(NULL)
		{
		}
	};

	class BST
	{
		Node* root;
		void PostOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				PostOrderTrav(node->left);
				PostOrderTrav(node->right);
				cout << node->data << ' ';
			}
		}
		void PreOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				cout << node->data << ' ';
				PreOrderTrav(node->left);
				PreOrderTrav(node->right);
			}
		}
		void InOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				InOrderTrav(node->left);
				cout << node->data << ' ';
				InOrderTrav(node->right);
			}
		}
	public:
		BST() :root(NULL)
		{
		}
		void Add(int data)
		{
			Node* node = new Node(data);
			if (root == NULL)
			{
				root = node;
			}
			else
			{
				Node* trav1, * trav2;
				trav1 = trav2 = root;
				while (trav1 != NULL)
				{
					trav2 = trav1;
					trav1 = (data < trav1->data) ? trav1->left : trav1->right;
				}
				if (data < trav2->data)
				{
					trav2->left = node;
				}
				else
				{
					trav2->right = node;
				}
			}
		}

		void DeleteLeast()
		{
			if (root == NULL)
			{
				cout << "Tree is Empty \n";
			}
			else if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				cout << "Releasing " << temp->data << endl;
				delete temp;
			}
			else
			{
				Node* trav1, * trav2;
				trav1 = trav2 = root;
				while (trav1->left != NULL)
				{
					trav2 = trav1;
					trav1 = trav1->left;
				}
				trav2->left = trav1->right;

				cout << "Releasing " << trav1->data << endl;
				delete trav1;
			}
		}

		void PostOrder()
		{
			cout << "\n_____________________Post Order  : ";
			PostOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
		void PreOrder()
		{
			cout << "\n_____________________Pre  Order  : ";
			PreOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
		void InOrder()
		{
			cout << "\n_____________________In    Order : ";
			InOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
	};
	int main()
	{
		int arr[7] = { 7,4,10,8,12,2,5 };
		cout << "inputs   : 7,4,10,8,12,2,5\npostorder :  2, 5, 4, 8, 12, 10, 7\npre - order : 7, 4, 2, 5, 10, 8, 12\nin - order : 2, 4, 5, 7, 8, 10, 12" << endl;
		BST bst;
		for (size_t i = 0; i < 7; i++)
		{
			bst.Add(arr[i]);
		}
		bst.PostOrder();
		bst.PreOrder();
		bst.InOrder();
		return 0;
	}
}#include<iostream>
#include<string>
using namespace std;

/*
inputs   : 7,4,10,8,12,2,5

postorder :  2,5,4,8,12,10,7
pre-order  : 7,4,2,5,10,8,12
in-order   : 2,4,5,7,8,10,12
*/
namespace nm54
{

	struct Node
	{
		int data;
		Node* left;
		Node* right;
		Node(int data) :data(data), left(NULL), right(NULL)
		{
		}
	};

	class BST
	{
		Node* root;
		void PostOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				PostOrderTrav(node->left);
				PostOrderTrav(node->right);
				cout << node->data << ' ';
			}
		}
		void PreOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				cout << node->data << ' ';
				PreOrderTrav(node->left);
				PreOrderTrav(node->right);
			}
		}
		void InOrderTrav(Node* node)
		{
			if (node != NULL)
			{
				InOrderTrav(node->left);
				cout << node->data << ' ';
				InOrderTrav(node->right);
			}
		}
	public:
		BST() :root(NULL)
		{
		}
		void Add(int data)
		{
			Node* node = new Node(data);
			if (root == NULL)
			{
				root = node;
			}
			else
			{
				Node* trav1, * trav2;
				trav1 = trav2 = root;
				while (trav1 != NULL)
				{
					trav2 = trav1;
					trav1 = (data < trav1->data) ? trav1->left : trav1->right;
				}
				if (data < trav2->data)
				{
					trav2->left = node;
				}
				else
				{
					trav2->right = node;
				}
			}
		}

		void DeleteLeast()
		{
			if (root == NULL)
			{
				cout << "Tree is Empty \n";
			}
			else if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				cout << "Releasing " << temp->data << endl;
				delete temp;
			}
			else
			{
				Node* trav1, * trav2;
				trav1 = trav2 = root;
				while (trav1->left != NULL)
				{
					trav2 = trav1;
					trav1 = trav1->left;
				}
				trav2->left = trav1->right;

				cout << "Releasing " << trav1->data << endl;
				delete trav1;
			}
		}

		void PostOrder()
		{
			cout << "\n_____________________Post Order  : ";
			PostOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
		void PreOrder()
		{
			cout << "\n_____________________Pre  Order  : ";
			PreOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
		void InOrder()
		{
			cout << "\n_____________________In    Order : ";
			InOrderTrav(root);
			cout << "\n______________________________________________________\n";
		}
	};
	int main()
	{
		int arr[7] = { 7,4,10,8,12,2,5 };
		cout << "inputs   : 7,4,10,8,12,2,5\npostorder :  2, 5, 4, 8, 12, 10, 7\npre - order : 7, 4, 2, 5, 10, 8, 12\nin - order : 2, 4, 5, 7, 8, 10, 12" << endl;
		BST bst;
		for (size_t i = 0; i < 7; i++)
		{
			bst.Add(arr[i]);
		}
		bst.PostOrder();
		bst.PreOrder();
		bst.InOrder();
		return 0;
	}
}