#include<iostream>
using namespace std;

class CSine
{
	double angle;
	double sinvalue;
	int limit;
public:
	CSine(double anglepar = 0.0, int limit = 100) :angle(anglepar*3.14159 / 180.0), sinvalue(angle), limit(limit)
	{

	}

	void Reset(double anglepar = 0.0, int limit = 100)
	{
		this->angle = anglepar * 3.14159 / 180;
		this->limit = limit;
		this->sinvalue = angle;
	}

	void Process()
	{
		double term = angle;
		double sum = angle;
		for (int i = 1; i <= limit; i++)
		{
			term = -(term * angle*angle)/((2 * i)*((2 * 1) + 1));
			sum += term;
		}
		this->sinvalue = sum;
	}

	friend ostream &operator<<(ostream &os, const CSine &par)
	{
		os << par.sinvalue << "\n";
		return os;
	}
	

};

int main()
{
	CSine cs(90.000000, 100);
	cs.Process();
	cout<<cs;

	return 0;
}