/*
Find max values of x and y such x<=y and x+2y=n 

200	-> n

66 67	-> x and y

*/

//Solution
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n\n";
    cin>>n;
    int x,y;
    bool got_ans=false;
    
    for(int i=n/2; i>0; --i)
    {
        for(int j=n/2; j>=i; --j)
        {
            if((i+(2*j))==n)
            {
                x=i;
                y=j;
                got_ans=true;
                // cout<<"got "<<x<<" "<<y<<endl;
            }
            
            if(got_ans)
                break;
        }
    }
    
    cout<<x<<" "<<y;
}
