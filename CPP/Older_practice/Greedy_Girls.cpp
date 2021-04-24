#include<iostream>
using namespace std;

int main()
{  
   int x,y,z,i;
   for (i = 1; i <= 500; i++)
   {
	   if (i % 3 == 1)
	   {
		   x = i / 3 * 2;
		   if (x % 3 == 1)
		   {
			   y = x / 3 * 2;
			   if (y % 3 == 1)
			   {
				   z = y / 3 * 2;
				   if (z % 3 == 0)
				   {
					   cout << "no.of mangoes" << i << '\n';
				   }
			   }
		   }
	   }
   }

}

  
