#include <iostream>
#include <stdlib.h>
using namespace std;

namespace as09
{

	struct Node
	{
		Node* prev;
		int data;
		Node* next;
	};


	class CircularDoublyLinkedList
	{
	private:
		Node* front;
		Node* rear;

		Node* createNode(int data)
		{
			Node* node = new Node();
			node->prev = NULL;
			node->data = data;
			node->next = NULL;

			return node;
		}
	public:

		CircularDoublyLinkedList() : front(NULL), rear(NULL)
		{
		}

		/* Append or Insert at the end */
		void Append(int data)
		{
			Node* node = createNode(data);

			if (front == NULL)
			{
				front = node;
				rear = node;
			}
			else
			{
				rear->next = node;
				node->prev = rear;

				rear = node;

				rear->next = front;
				front->prev = rear;
			}
		}


		/* Delete at beginning */
		void DeleteAtBeginning()
		{
			if (front == NULL)
			{
				cout << "Nothing to delete.\n";
				return;
			}
			else
			{
				rear->next = front->next;
				delete front;
				front = rear->next;
				front->prev = rear;
			}

		}


		/* Delete at end */
		void DeleteAtEnd()
		{
			if (front == NULL)
			{
				cout << "Nothing to delete.\n";
				return;
			}
			else
			{
				front->prev = rear->prev;
				delete rear;
				rear = front->prev;
				rear->next = front;
			}

		}


		/* Delete at nth Position */
		void DeleteAtNthPos(int pos)
		{
			if (front == NULL)
			{
				cout << "Nothing to delete.\n";
			}
			else
			{
				Node* trav = front;

				// To reach the nth node, (n - 1) traversals are required.
				for (int i = 0; i < (pos - 1); i++)
				{
					trav = trav->next;
				}

				if (trav->prev == rear)
				{
					DeleteAtBeginning();
					return;
				}
				else if (trav->next == front)
				{
					DeleteAtEnd();
					return;
				}

				Node* travPrev = trav->prev;
				Node* travNext = trav->next;

				travPrev->next = travNext;
				travNext->prev = travPrev;

				delete trav;
			}

		}


		void dropN(int num)
		{
			Node* jumper = front;

			while (front != rear)
			{
				for (int i = 0; i < (num - 1); i++)
				{
					jumper = jumper->next;
				}

				if (jumper->prev == rear)
				{
					DeleteAtBeginning();
					jumper = front;
					continue;
				}
				else if (jumper->next == front)
				{
					DeleteAtEnd();
					jumper = front;
					continue;
				}

				Node* jumperPrev = jumper->prev;
				Node* jumperNext = jumper->next;

				jumperPrev->next = jumperNext;
				jumperNext->prev = jumperPrev;

				delete jumper;
				jumper = jumperNext;
			}
		}


		void Print()
		{
			Node* trav = front;

			do
			{
				cout << trav->data << " ";
				trav = trav->next;
			} while (trav != front);

			cout << "\n";
		}


		~CircularDoublyLinkedList()
		{
		}
	};


	int main()
	{
		CircularDoublyLinkedList cdll;

		// list having initial values [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
		for (int i = 1; i < 11; i++)
		{
			cdll.Append(i);
		}

		int num = rand() % 10;

		cout << "Number picked up is " << num << "\n";
		cdll.Print();

		cdll.dropN(num);

		cout << "Node saved is: ";
		cdll.Print();

		return 0;
	}
}