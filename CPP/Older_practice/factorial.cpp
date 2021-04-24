#include<iostream>
using namespace std;


int main()
{
	int l, o, n, x, f = 1, s = 0;
	cout << "Enter the last no.:";
	cin >> l;
	for (int j = 1; j < l; j++)
	{
		n = j;
		o = n;

		while (n != 0)
		{
			int r = n % 10;
			n = n / 10;
			for (int i = 1; i < r; i++)
			{
				f = f * (i + 1);
			}
			s = s + f;
			f = 1;
		}
		if (o == s)
		{
			cout << "No. is identical to it's factorial\n";
			cout << "No. is;" << o << "\n";
			s = 0;
		}
		else
			s = 0;
    }
return 0;
}