#include<iostream>
#include<string>
using namespace std;



namespace nm1
{ 
struct Student
{
	int id;
	string name;
	Student* next;
};


Student* stud;
Student* head;
Student* temp;
Student* ptr;
Student* extra;


class LinkedList
{
	Student* head;
	Student* tail;
	Student* CreateNode(int id, string name)
	{
		Student* temp = new Student();
		temp->id = id;
		temp->name = name;
		temp->next = NULL;
		return temp;
	}
public:
	LinkedList() :head(NULL), tail(NULL)
	{
	}
	void Append(int id, string name)
	{
		Student* stud = CreateNode(id, name);
		if (head == NULL)
		{
			head = stud;
		}
		else
		{
			tail->next = stud;
		}
		tail = stud;
	}
	void Prepend(int id, string name)
	{
		if (head == NULL)
		{
			Append(id, name);
		}
		else
		{
			Student* stud = CreateNode(id, name);
			stud->next = head;
			head = stud;
		}

	}
	void DeleteFirst()
	{
		Student* stud;
		Student* temp;
		if (head == NULL)
		{
			printf("\nList is Empty:\n");
			return;
		}
		else
		{
			temp = head;
			head = head->next;

			delete temp;
		}
	}
	void DeleteLast()
	{
		
		if (head == NULL)
		{
			printf("\nList is Empty:");
			exit(0);
		}
		else if (head->next == NULL)
		{
			ptr = head;
			head = NULL;
			delete ptr;
			
		}
		else
		{
			ptr = head;
			while (ptr->next != NULL)
			{
				temp = ptr;
				ptr = ptr->next;
			}
			temp->next = NULL;
			
			delete ptr;
		}
	}
	void DeleteByPosition(int pos)
	{
		int i;
		
		if (head == NULL)
		{
			cout<<"\nThe List is Empty:\n";
			exit(0);
		}
		else
		{
			
			if (pos == 0)
			{
				ptr = head;
				head = head->next;
				
				delete ptr;
			}
			else
			{
				ptr = head;
				for (i = 1; i < pos; i++)
				{
					temp = ptr;
					ptr = ptr->next;
					if (ptr == NULL)
					{
						cout<<"\nPosition not Found:\n";
						return;
					}
				}
				temp->next = ptr->next;
				delete ptr;
				
			}
		}
	}
	void DeleteByValue(int id)
	{
		int i;

		if (head == NULL)
		{
			cout << "\nThe List is Empty:\n";
			exit(0);
		}
		else
		{

			ptr = head;

			while (ptr->id != id)
			{
				temp = ptr;
				ptr = ptr->next;
				extra = ptr->next;
			}

			temp->next = extra;
			delete ptr;

		}

	}
	void InsertByPosition(int pos, int id, string name)
	{


		int i;

		if (head == NULL)
		{
			cout << "\nThe List is Empty:\n";
			exit(0);
		}
		else
		{

			if (pos == 0)
			{
				/*ptr = head;
				head = head->next;*/
				Append(id, name);
				
			}
			else
			{
				Student* stud = CreateNode(id, name);
				ptr = head;
				for (i = 1; i <= pos-1; i++)
				{
					temp = ptr;
					ptr = ptr->next;
					if (ptr == NULL)
					{
						cout << "\nPosition not Found:\n";
						return;
					}
				}
				temp->next = stud;
				stud->next = ptr;

			}
		}

	}
	void InsertAfter(int criteriaId, int id, string name)
	{

		int i;

		if (head == NULL)
		{
			cout << "\nThe List is Empty:\n";
			exit(0);
		}
		else
		{

			if (criteriaId == 0)
			{
				
				Append(id, name);

			}
			else
			{
				Student* stud = CreateNode(id, name);

				

				ptr = head;

				while (ptr->id != criteriaId)
				{
					temp = ptr;
					ptr = ptr->next;
					extra = ptr->next;
				}
				
				ptr->next = stud;
				stud->next = extra;
				
				

			}
		}
		
	}
	void InsertBefore(int criteriaId, int id, string name)
	{

		int i;

		if (head == NULL)
		{
			cout << "\nThe List is Empty:\n";
			exit(0);
		}
		else
		{

			if (criteriaId == 0)
			{

				Append(id, name);

			}
			else
			{
				Student* stud = CreateNode(id, name);

				ptr = head;

				while (ptr->id != criteriaId)
				{
					temp = ptr;
					ptr = ptr->next;
				}
				temp->next = stud;
				stud->next = ptr;




			}
		}

	}
	
	void ReverseLL()
	{
		Student* current = head;
		Student* prev = NULL, * next = NULL;

		while (current != NULL) {
			// Store next
			next = current->next;

			// Reverse current node's pointer
			current->next = prev;

			// Move pointers one position ahead.
			prev = current;
			current = next;
		}
		head = prev;
	}



	void List()
	{
		cout << "\n\n--------------------List Of Students--------------------\n\n";
		Student* trav = head;
		if (head == NULL)
		{
			cout << "*****************List Is Empty****************\n\n\n";
		}
		else
		{
		while (trav != NULL)
		{
			cout << trav->id << '\t' << trav->name << '\n';
			trav = trav->next;
		}
	}
		cout << "------------------------------------------------------------\n\n";
	}
	~LinkedList()
	{
	}
};


int main()
{
	LinkedList lkd;


	int choice, id;
	int pos, criteriaId;
	string name;
	while (1) {
		cout << "\n***SINGLE LINKED LIST OPERATIONS:****\n";
		cout << "\n********************MENU********************\n";
		cout << "---------------------------------------\n";
		cout << "\n 1.Append Node    \n";
		cout << "\n 2.Prepend Node    \n";
		cout << "\n 3.Delete First Node    \n";
		cout << "\n 4.Delete Last Node  \n";
		cout << "\n 5.Delete By Position       \n";
		cout << "\n 6.Delete By Value     \n";
		cout << "\n 7.Insert By Position        \n";
		cout << "\n 8.Insert After        \n";
		cout << "\n 9.Insert Before        \n";
		cout << "\n 10.Reverse The Linked List     \n";
		cout << "\n 11.Show List       \n";
		cout << "\n 12.Exit       \n";
		cout << "\n--------------------------------------\n";
		cout << "Enter your choice:\t";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n Enter Id   \n";
			cin >> id;
			cout << "\n Enter Name   \n";
			cin >> name;
			lkd.Append(id, name);
			break;
		case 2:
			cout << "\n Enter Id   \n";
			cin >> id;
			cout << "\n Enter Name   \n";
			cin >> name;
			lkd.Prepend(id, name);
			break;
		case 3:
			cout << "First Node Deleted\n";
			lkd.DeleteFirst();
			break;
		case 4:
			cout << "Last Node Deleted\n";
			lkd.DeleteLast();
			break;
			
		case 5:
			
			
			cout << "\n Enter Position   \n";
			cin >> pos;
			cout << "Deleted By Position\n";
			lkd.DeleteByPosition(pos);
		
			break;
		case 6:
			cout << "\n Enter Node Id which You want to Delete   \n";
			cin >> id;
			cout << "Deleted By Node Id\n";
			lkd.DeleteByValue(id);
			break;
		case 7:
			
			
			cout<<"\nEnter the position for the new node to be inserted:\t\n";
			cin >> pos;
			cout<<"\nEnter Id:\t\n";
			cin >> id;
			cout << "\nEnter Name:\t\n";
			cin >> name;
			lkd.InsertByPosition(pos, id, name);

			break;
		case 8:
			cout << "\nEnter the Node ID after which you want to insert node:\t\n";
			cin >> criteriaId;
			cout << "\nEnter new node Id:\t\n";
			cin >> id;
			cout << "\nEnter new node Name:\t\n";
			cin >> name;

			
			lkd.InsertAfter(criteriaId,id,name);

			break;
		case 9:
			cout << "\nEnter the Node ID Before which you want to insert node:\t\n";
			cin >> criteriaId;
			cout << "\nEnter new node Id:\t\n";
			cin >> id;
			cout << "\nEnter new node Name:\t\n";
			cin >> name;


			lkd.InsertBefore(criteriaId, id, name);

			break;
		case 10:
			lkd.ReverseLL();

			break;
		case 11:
			lkd.List();
			break;
		case 12:
			exit(0);
			break;
		default:
			printf("\n Wrong Choice:\n");
			break;
		}//end of switch()
	}

	return 0;
}
}