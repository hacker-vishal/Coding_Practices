#include<iostream>
#include<string>
using namespace std;

namespace nm4
{
	struct Student
	{
		int id;
		Student* next;

	};

	int id, ch, survive, skip;
	Student* stud;
	Student* head;
	Student* temp;
	Student* ptr;
	Student* extra;


	class S_CircularLinkedList
	{
		Student* head;
		Student* tail;
		Student* CreateNode(int id)
		{
			Student* temp = new Student();
			temp->id = id;
			//temp->name = name;

			temp->next = NULL;
			return temp;
		}
	public:
		S_CircularLinkedList() :head(NULL), tail(NULL)
		{
		}



		void Append(int id)
		{


			Student* stud = CreateNode(id);
			if (head == NULL)
			{
				head = stud;

			}
			else
			{
				tail->next = stud;


			}
			tail = stud;
			tail->next = head;

		}


		int survivor(int k)
		{
			struct Student* p, * q;
			int i;

			q = p = head;
			while (p->next != p)
			{
				for (i = 0; i < k; i++)
				{
					q = p;
					p = p->next;

				}


				q->next = p->next;
				cout << p->id << "has been killed.\n";
				delete p;

				p = q->next;
			}
			/*head = p;*/


			return (p->id);
		}


		void List()
		{
			cout << "\n\n--------------------List Of Id's--------------------\n\n";

			Student* trav = head;
			if (head == NULL)
			{
				cout << "*****************List Is Empty****************\n\n\n";
			}
			else
			{
				do
				{
					cout << trav->id << '\t' << '\n';
					trav = trav->next;
				} while (trav != head);
			}

			cout << "------------------------------------------------------------\n\n";
		}

		~S_CircularLinkedList()
		{
		}
	};


	int main()
	{
		S_CircularLinkedList lkd;
		struct Student* head = NULL;

		do {
			cout << "Enter Id\n";
			cin >> id;
			lkd.Append(id);
			cout << "Do you want to add a number [1/0]?";
			cin >> ch;
		} while (ch != 0);


		lkd.List();

		cout << "Enter the number of persons to be skipped: ";
		cin >> skip;
		survive = lkd.survivor(skip);
		cout << "\n\n----------------The person to survive is-----------------\n\n" << survive << "\n\n---------------------------------------------------------------------\n\n";
		/*delete head;*/



		return 0;
	}
}



