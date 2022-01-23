/*
An array of integers is GOOD if last bit of all numbers when represented in binary are same.

//Output Window
Enter size of array
5
Enter space separated n numbers
2 4 6 8 10
GOOD

*/

//Solution
#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    
    int arr[n]={};
    cout<<"Enter space separated n numbers\n";
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    // print elements of array arr    
    // for(int i=0; i<n; i++)
    //     cout<<arr[i]<<" ";
    
    //Number of bits for which we want to allocate storage
    const int bitnum=8;
    
    string strarr[n]={};
    for(int i=0; i<n; i++)
    {
        strarr[i]=bitset<bitnum>(arr[i]).to_string();
    }
    
    char lastbit=strarr[0][bitnum-1]; //cout<<lastbit;
    
    bool isgood=true;
    string ans="GOOD";
    
    for(int i=1; i<n; i++)
    {
        if(lastbit!=strarr[i][bitnum-1])
        {
            isgood=false;
            break;
        }
        else
            continue;
    }
    
    if(!isgood)
        ans="BAD";
        
    cout<<ans;
}
