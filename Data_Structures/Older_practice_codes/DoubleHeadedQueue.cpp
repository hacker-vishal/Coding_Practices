#include<iostream>
#include<string>
using namespace std;

namespace as03
{

	struct EmpDetail
	{
		string name;
		int salary;
		EmpDetail* next;
		EmpDetail(string name, int salary) :name(name), salary(salary), next(NULL)
		{
		}
		void Display()
		{
			if (next != NULL)
			{
				next->Display();
			}
			cout << "\t" << name << "\t" << salary << '\n';
		}
		~EmpDetail()
		{
			if (next != NULL)
			{
				delete next;
			}
			cout << "Releasing " << name << '\n';
		}
	};


	class Queue
	{
		EmpDetail* head;
		EmpDetail* tail;

		void Release()
		{
			delete head;
			head = tail = NULL;
		}
		void Add(EmpDetail* temp)
		{
			if (head == NULL)
			{
				head = temp;
			}
			else
			{
				tail->next = temp;
			}
			tail = temp;
		}

	public:
		Queue() :head(head), tail(tail)
		{
		}
		bool IsEmpty()
		{
			return head == NULL;
		}
		void Enqueue(string name, int salary)
		{
			EmpDetail* node = new EmpDetail{ name,salary };
			Add(node);
		}
		void Enqueue(EmpDetail* node)
		{
			if (node != NULL)
			{
				Add(node);
			}
		}
		EmpDetail* Dequeue()
		{
			if (!IsEmpty())
			{
				EmpDetail* temp = head;
				head = head->next;
				if (head == NULL)
				{
					tail = NULL;
				}
				temp->next = NULL;
				return temp;
			}
			cout << "Queue is Empty\n";
			return NULL;
		}
		void List()
		{

			if (head != NULL)
			{
				head->Display();
			}
			else
			{
				cout << "Queue is Empty\n";
			}
			cout << "=================================\n";
		}
		~Queue()
		{

			delete head;
		}
	};

	int main()
	{
		Queue q;
		q.Enqueue(new EmpDetail("XYZ", 100));
		q.Enqueue("Saurav", 5000);
		EmpDetail* temp = new EmpDetail("PQR", 6000);
		q.Enqueue(temp);
		q.Enqueue("RST", 2000);
		q.Enqueue("LMN", 4000);
		q.List();
		cout << "+++++++++++++++++++++++++++++++++++++++\n";
		EmpDetail* t = q.Dequeue();
		delete t;
		cout << "++++++++++++++++++++++++++++++++++++++++++\n";
		q.List();
		return 0;
	}
}