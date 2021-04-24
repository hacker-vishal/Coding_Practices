#include <iostream>
#include <string>
using namespace std;

namespace as10
{

	struct Node
	{
		Node* prev;
		int data;
		Node* next;
	};


	class DoublyLinkedList
	{
	private:
		Node* createNode(int data)
		{
			Node* node = new Node();
			node->prev = NULL;
			node->data = data;
			node->next = NULL;

			return node;
		}
	public:
		Node* head;
		Node* tail;

		DoublyLinkedList() : head(NULL), tail(NULL)
		{
		}

		/* Append or Insert at the end */
		void Append(int data)
		{
			Node* node = createNode(data);

			if (head == NULL)
			{
				head = node;
				tail = node;
			}
			else
			{
				Node* trav = head;
				while (trav->next != NULL)
				{
					trav = trav->next;
				}
				trav->next = node;
				node->prev = trav;
				// node->next = NULL;  		// already NULL

				tail = node;
			}
		}


		void splitAppend(string numStr)
		{
			for (char& c : numStr)
			{
				Append(c - '0');
			}

		}


		/* Insert at Head */
		void InsertAtHead(int data)
		{
			if (head == NULL)
			{
				Append(data);
			}
			else
			{
				Node* node = createNode(data);

				// node->prev = NULL;  		// already NULL
				node->next = head;
				head->prev = node;

				head = node;
			}
		}


		void Add(DoublyLinkedList& num)
		{
			DoublyLinkedList dll;
			Node* trav0 = this->tail;
			Node* trav1 = num.tail;
			int sum = 0;
			int rem = 0;
			int carry = 0;

			while ((trav0 != NULL) || (trav1 != NULL))
			{
				if (trav0 == NULL)
				{
					sum = trav1->data + carry;
					trav1 = trav1->prev;
				}
				else if (trav1 == NULL)
				{
					sum = trav0->data + carry;
					trav0 = trav0->prev;
				}
				else
				{
					sum = trav0->data + trav1->data + carry;
					trav0 = trav0->prev;
					trav1 = trav1->prev;
				}

				rem = sum % 10;
				carry = sum / 10;

				dll.InsertAtHead(rem);
			}

			if (carry != 0)
			{
				dll.InsertAtHead(carry);
			}

			cout << "sum: ";
			dll.Print();
		}


		void Print()
		{
			Node* trav = head;

			while (trav != NULL)
			{
				cout << trav->data << "";
				trav = trav->next;
			}
			cout << "\n";
		}


		~DoublyLinkedList()
		{
		}
	};




	int main()
	{
		DoublyLinkedList num0;
		DoublyLinkedList num1;

		string numStr0;
		cout << "num0: ";
		cin >> numStr0;
		string numStr1;
		cout << "num1: ";
		cin >> numStr1;

		num0.splitAppend(numStr0);
		num1.splitAppend(numStr1);

		num0.Add(num1);

		return 0;
	}
}