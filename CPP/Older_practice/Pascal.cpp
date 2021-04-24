#include<iostream>
using namespace std;

class pascal
{ 
 public:
   int factorial(int n)
 {
    if(n == 1 || n == 0)
     {
      return 1;
     }
    return n * factorial(n-1);
 }

  int nCr(int n, int r)
  {
     return factorial(n)/((factorial(r)*factorial(n-r)));
  }
};

int main()
{  
   pascal pa;
   int n,i,j,k;
   cout<<"Enter the no of rows";
   cin>>n;
   pa.factorial(n);
   for(i=0;i<n;i++)
    {
     for(j=n-1;j>0;j--)
     {
      cout<<"\n";
     }
     for(k=0; k<=i;k++)
     {
      cout<<pa.nCr(i,k)<<"\t";
     }
    cout<<" "<<endl;
   }
return 0;
}
