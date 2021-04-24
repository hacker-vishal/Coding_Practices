#include<iostream>
#include<string>
using namespace std;

class JD
{
	int mm;
	int dd;
	int julian = 0;
	int julval = 0;

public:

	void getdata()
	{
		cout << "enter the day \n";
		cin >> dd;
		cout << "enter the month \n";
		cin >> mm;
	}
	int process()
	{
		mm = mm - 1;

		switch (mm)
		{
		case 12:
			julian += 31;
		case 11:
			julian = 30;
		case 10:
			julian + 31;
		case 9:
			julian + 30;
		case 8:
			julian += 31;
		case 07:
			julian += 31;
		case 06:
			julian += 30;
		case 05:
			julian += 31;
		case 04:
			julian += 30;
		case 03:
			julian += 31;
		case 02:
			julian += 28;
		case 01:
			julian += 31;
			break;
		}

		julval = dd + julian;
		return julval;
	}
};
	
	int main()
	{
		JD obj1;
		obj1.getdata();
			int val = obj1.process();
		cout << " julian value = " << val;
		return 0;
	}