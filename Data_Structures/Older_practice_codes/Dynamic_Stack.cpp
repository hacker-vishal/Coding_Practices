#include<iostream>
using namespace std;

namespace nm59
{


	template<typename T, int size>
	struct Node
	{
		int arr[size];
		int top;
		Node() :top(-1), next(NULL)
		{
			cout << "\nNew Node Constructed \n";
		}
		~Node()
		{
			cout << "Releasing the  node\n";
		}
		Node* next;
	};

	template<typename T, int size>
	class StackPacket
	{
		Node<T, size>* head;
	public:
		StackPacket() :head(NULL)
		{
		}
		int Pop()
		{
			if (IsEmpty())
			{
				cout << "Stack is Empty\n";
				return -1;
			}
			int val = head->arr[head->top--];
			if (head->top == -1)
			{
				Node<T, size>* temp = head;
				head = head->next;
				delete temp;
			}
			return val;
		}
		void Push(int data)
		{
			if (head == NULL)
			{
				head = new Node<T, size>();
			}
			else if (head->top == size - 1)
			{
				Node<T, size>* temp = new Node<T, size>();
				temp->next = head;
				head = temp;
			}
			head->arr[++head->top] = data;
		}
		void Display()
		{
			Node<T, size>* trav = head;
			while (trav != NULL)
			{
				int length = trav->top;
				for (int i = length; i >= 0; i--)
				{
					cout << trav->arr[i] << endl;
				}
				trav = trav->next;
			}
		}

		bool IsEmpty()
		{
			return head == NULL;
		}
		~StackPacket()
		{
			Node<T, size>* trav = head;
			while (head != NULL)
			{
				trav = head;
				head = head->next;
				delete trav;
			}

		}
	};

	int main()
	{
		StackPacket<int, 5> pckt;
		pckt.Push(100);
		pckt.Push(200);
		pckt.Push(300);
		pckt.Push(400);
		pckt.Push(500);
		pckt.Push(600);
		pckt.Push(700);
		pckt.Push(800);
		pckt.Push(500);
		pckt.Push(600);
		pckt.Push(700);
		pckt.Push(800);
		cout << "_____________________________\n";
		pckt.Display();
		cout << "_____________________________\n";
		cout << pckt.Pop() << endl;
		cout << pckt.Pop() << endl;
		cout << pckt.Pop() << endl;
		cout << "_____________________________\n";
		return 0;
	}
}