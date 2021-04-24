#include<iostream>
#include<string>
using namespace std;


class SG
{
	int head;
	int legs;
	int ducks;
	int goats;
public:
	SG(int head,int legs):head(head),legs(legs),ducks(0),goats(0)
	{
	}
	void GetData(int head,int legs)
	{
		this->head=head;
		this->legs=legs;
	}
	void Process()
	{
		int i=1;
		for(;i<head && (4*(head-i)+i*2)!=legs ;i++);
		goats=head-i;
		ducks=i;
	}
	void Display() const
	{
		cout<<"Goats="<<goats<<" and ducks="<<ducks<<'\n';
	}
};


int main()
{
	SG sg(90,190);
	
	sg.Process();
	sg.Display();
	sg.GetData(4,12);
	
	return 0;
}