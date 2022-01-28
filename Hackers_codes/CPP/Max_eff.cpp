/*

Given n no of elements. -ve meaning eff. decreased and +ve meaning eff. increased. While going thro'
array elements, find index at which we're getting maximum efficiency.

10						-> n
Enter space separated elements of array arr	
10 30 45 67 8  22 333 21 56 89			-> array elements
9						-> index of element with max efficiency

*/

//Solution
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n\n";
    cin>>n;
    
    int arr[n];
    cout<<"Enter space separated elements of array arr\n";
    for(int i=0; i<n; ++i)  
        cin>>arr[i];
    
    //Print elements of array
    // for(int i: arr)
    //     cout<<i<<" ";
    
    int eff=0;
    int helper=0;
    int max_pt=0;
    
    for(int i=0; i<n; ++i)
    {
        helper+=arr[i];
        if(helper>eff)
        {
            eff=helper;
            max_pt=i;
        }
    }
    
    if(eff<0)
        cout<<"-1";
    else
        cout<<max_pt;
    
    return 0;
}
