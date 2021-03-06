#include <iostream>
using namespace std;

namespace as08
{

	// A structure to represent a node.
	struct list
	{
		int data;
		list* next;
	};

	// Function implementing insertion sort.
	list* InsertinList(list* head, int n)
	{
		// Creating newnode and temp node.
		list* newnode = new list;
		list* temp = new list;

		// Using newnode as the node to be inserted in the list.
		newnode->data = n;
		newnode->next = NULL;

		// If head is null then assign new node to head.
		if (head == NULL)
		{
			head = newnode;
			return head;
		}
		else
		{
			temp = head;

			// If newnode->data is lesser than head->data, then insert newnode before head.
			if (newnode->data < head->data)
			{
				newnode->next = head;
				head = newnode;
				return head;
			}

			// Traverse the list till we get value more than newnode->data.
			while (temp->next != NULL)
			{
				if (newnode->data < (temp->next)->data)
					break;

				temp = temp->next;
			}

			// Insert newnode after temp.
			newnode->next = temp->next;
			temp->next = newnode;
			return head;
		}
	}

	int main()
	{
		int n, i, num;
		// Declaring head of the linked list.
		list* head = new list;
		head = NULL;

		cout << "\nEnter the number of data element to be sorted: ";
		cin >> n;

		for (i = 0; i < n; i++)
		{
			cout << "Enter element " << i + 1 << ": ";
			cin >> num;
			// Inserting num in the list.
			head = InsertinList(head, num);
		}

		// Display the sorted data.
		cout << "\nSorted Data ";
		while (head != NULL)
		{
			cout << "->" << head->data;
			head = head->next;
		}

		return 0;
	}
}