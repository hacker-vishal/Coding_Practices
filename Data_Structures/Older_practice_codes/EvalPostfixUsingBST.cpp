#include<iostream>
#include<string>
using namespace std;


namespace nm52
{
	template<typename T, int size>
	class Stack
	{

		T arr[size];
		int top;
	public:
		Stack() :top(-1)
		{
		}
		bool IsEmpty()
		{
			return top == -1;
		}
		bool IsFull()
		{
			return top == size;
		}
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}
	};

	struct Node
	{
		char data;
		Node* left;
		Node* right;
		Node(char data) :data(data), left(NULL), right(NULL)
		{
		}
	};

	class BST
	{
		Node* root;
		
		void Add(char data)
		{
			Node* node = new Node(data);
			if (!isalpha(data))
			{
				node->right = stk.Pop();
				node->left = stk.Pop();
			}
			stk.Push(node);
		}

		int Evaluate(Node* node)
		{
			switch (node->data)
			{
			case'+':
				return Evaluate(node->left) + Evaluate(node->right);
			case'-':
				return Evaluate(node->left) - Evaluate(node->right);
			case'*':
				return Evaluate(node->left) * Evaluate(node->right);
			case'/':
				return Evaluate(node->left) / Evaluate(node->right);
			case '^':
				return pow(Evaluate(node->left), Evaluate(node->right));
			default:
				cout << "Please enter the value for " << node->data << " : ";
				int val;
				cin >> val;

				return val;
			}
			return 0;

		}

		void Release(Node* node)
		{
			if (node != NULL)
			{
				Release(node->left);
				Release(node->right);
				cout << "Releasing = " << node->data << endl;
				delete node;
			}
		}
		Stack<Node*, 50> stk;
	public:
		BST() :root(NULL)
		{
		}
		void GetPostFixed(string postfixed)
		{
			int length = postfixed.size();
			for (size_t i = 0; i < length; i++)
			{
				this->Add(postfixed[i]);
			}
			root = stk.Pop();
		}
		void GetPrefix(string prefixed)
		{
			//Do it 
		}

		int Eval()
		{

			return Evaluate(root);

		}
		~BST()
		{
			Release(root);
		}
	};

	int main()
	{
		string postfixed = "abc*+d+";
		BST bst;
		bst.GetPostFixed(postfixed);

		cout << "postfix Expression = " << postfixed << endl;

		cout << "Evaluation of Postfix using BST = " << bst.Eval() << endl;
		cout << "______________________\n";
		return 0;
	}
}
