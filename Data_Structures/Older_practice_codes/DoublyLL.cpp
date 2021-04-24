#include<iostream>
#include<string>
using namespace std;


namespace nm5
{

struct Student
{
	int id;
	string name;
	Student* next;
	Student* prev;

};

Student* temp;
Student* ptr;
Student* extra;


class DoublyLinkedList
{
	Student* head;
	Student* tail;
	Student* CreateNode(int id, string name)
	{
		Student* temp = new Student();
		temp->id = id;
		temp->name = name;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}
public:
	DoublyLinkedList() :head(NULL), tail(NULL)
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
			stud->prev = tail;
		}
		tail = stud;
	}
	void Prepend(int id, string name)
	{
		Student* stud = CreateNode(id, name);
		if (head == NULL)
		{
			Append(id,name);
		}
		else 
		{
			
			stud->next = head;
			head->prev = stud;
			head = stud;
			
		}
		
	}
	void DeleteFirst()
	{
		if (head == NULL)
		{
			cout << "List Is Empty\n";
		}
		else
		{
			temp = head;
			head = temp->next;
			head->prev = NULL;
			 
			delete temp;

		}
	}
	void DeleteLast()
	{
		if (head == NULL)
		{
			cout << "List Is Empty\n";
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
			tail = temp;
			delete ptr;
		}
	}
	void DeleteByPosition(int pos)
	{
		int i;

		if (head == NULL)
		{
			cout << "\nThe List is Empty:\n";
			exit(0);
		}
		else
		{

			if (pos == 1)
			{
				ptr = head;
				head = head->next;
				head->prev = NULL;

				delete ptr;
			}
			else
			{
				ptr = head;
				for (i = 1; i < pos; i++)
				{
					temp = ptr;
					ptr = ptr->next;
					extra = ptr->next;
					
				}
				temp->next = extra;
				extra->prev = temp;
				delete ptr;

			}
		}
	}
	
	void InsertByPosition(int pos, int id, string name)
	{
		int i;

		if (head == NULL)
		{
			Append(id, name);
		}
		else
		{
			Student* stud = CreateNode(id, name);
				ptr = head;
				for (i = 1; i < pos; i++)
				{
					temp = ptr;
					ptr = ptr->next;

				}
				temp->next = stud;
				stud->prev = temp;
				stud->next = ptr;
				ptr->prev = stud;

				

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
			extra->prev = temp;
			delete ptr;

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

			if (criteriaId ==	1)
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
				stud->prev = ptr;
				stud->next = extra;
				extra->prev = stud;


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
				stud->prev = temp;
				stud->next = ptr;
				ptr->prev = stud;




			}
		}

	}
	

	void List()
	{
		cout << "\n\n============List Of Students============\n\n";
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
		cout << "\n\n========================================\n\n";
	}
	~DoublyLinkedList()
	{
	}
};


int main()
{
	DoublyLinkedList dlkd;


	int choice, id;
	int pos, criteriaId;
	string name;
	while (1) {
		cout << "\n#######SINGLE LINKED LIST OPERATIONS:#######\n";
		cout << "\n********************MENU********************\n";
		cout << "----------------------------------------------\n";
		cout << "\n 1.Append Node    \n";
		cout << "\n 2.Prepend Node    \n";
		cout << "\n 3.Delete First Node    \n";
		cout << "\n 4.Delete Last Node  \n";
		cout << "\n 5.Delete By Position       \n";
		cout << "\n 6.Insert By Position        \n";
		cout << "\n 7.Delete By Value        \n";
		cout << "\n 8.Insert By After        \n";
		cout << "\n 9.Insert By Before        \n";
		cout << "\n 10.Show List       \n";
		cout << "\n 11.Exit       \n";
		cout << "----------------------------------------------\n";
		cout << "Enter your choice:\t";
		
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\n Enter Id   \n";
			cin >> id;
			cout << "\n Enter Name   \n";
			cin >> name;
			dlkd.Append(id, name);
			break;


		case 2:
			cout << "\n Enter Id   \n";
			cin >> id;
			cout << "\n Enter Name   \n";
			cin >> name;
			dlkd.Prepend(id, name);
			break;

		case 3:
			cout << "\n\n===============================\n\n";
			cout << "........1st Node Deleted...........\n";
			cout << "\n\n===============================\n\n";
			dlkd.DeleteFirst();
			break;

		case 4:
			cout << "\n\n===============================\n\n";
			cout << "........Last Node Deleted...........\n";
			cout << "\n\n===============================\n\n";
			dlkd.DeleteLast();
			break;

		case 5:
			cout << "\n Enter Position   \n";
			cin >> pos;

			cout << "\n\n===============================\n\n";
			cout << "......Deleted Node by Position.........\n";
			cout << "\n\n===============================\n\n";
			
			dlkd.DeleteByPosition(pos);
			
			break;

		case 6:
			cout << "\nEnter the position for the new node to be inserted:\t\n";
			cin >> pos;
			cout << "\nEnter Id:\t\n";
			cin >> id;
			cout << "\nEnter Name:\t\n";
			cin >> name;
			dlkd.InsertByPosition(pos, id, name);
			break;


		case 7:
			cout << "\n Enter Node Id which You want to Delete   \n";
			cin >> id;
			cout << "Deleted By Node Id\n";
			dlkd.DeleteByValue(id);
			break;

		case 8:
			cout << "\nEnter the Node ID after which you want to insert node:\t\n";
			cin >> criteriaId;
			cout << "\nEnter new node Id:\t\n";
			cin >> id;
			cout << "\nEnter new node Name:\t\n";
			cin >> name;


			dlkd.InsertAfter(criteriaId, id, name);

			break;

		case 9:
			cout << "\nEnter the Node ID Before which you want to insert node:\t\n";
			cin >> criteriaId;
			cout << "\nEnter new node Id:\t\n";
			cin >> id;
			cout << "\nEnter new node Name:\t\n";
			cin >> name;


			dlkd.InsertBefore(criteriaId, id, name);

			break;

		case 10:
			dlkd.List();
			break;
		
		case 11:
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
