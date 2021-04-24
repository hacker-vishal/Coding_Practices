#include<iostream>
using namespace std;

class CA
{
	static CA* head;
	CA()
	{
		cout<<"CA Ctor\n";
	}
	~CA()
	{
		cout<<"CA D-tor\n";
	}
	static CA* CreateCA()
	{
		if(head==NULL)
			head=new CA();
		return head;
	}
	static void ReleaseCA()
	{
		delete head;
		head=NULL;
	}
public:
	void fun()
	{
		cout<<"CA::Fun\n";
	}
	friend class SmartCA;
};
CA* CA::head=NULL;


class SmartCA
{
	static void* operator new(size_t size);
	static void* operator new[](size_t size);
	static void operator delete(void*);
	static void operator delete[](void*);
	SmartCA& operator=(SmartCA par);
	CA* ptr;
	static int count;
public:
	SmartCA():ptr(CA::CreateCA())
	{
		count++;
	}
	SmartCA(const SmartCA& par):ptr(par.ptr)
	{
		count++;
	}
	CA* operator->()
	{
		return ptr;
	}
	
	
	~SmartCA()
	{
		--count;
		if(count==0)
		{
			CA::ReleaseCA();
		}
	}
};
int SmartCA::count=0;


void DoJob()
{
	SmartCA obj1;
	SmartCA obj2;
	obj1->fun();

}


int main1()
{
	DoJob();
	cout<<"________________________\n";
	SmartCA s1;
	
	SmartCA s2;
	SmartCA s3(s2);

	s1->fun();
	return 0;
}

int main()
{
	
	cout<<"________________________\n";
	SmartCA s1;
	DoJob();
	SmartCA s2;
	SmartCA s3(s2);

	s1->fun();
	return 0;
}