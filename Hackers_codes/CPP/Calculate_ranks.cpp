/*
Given marks of n students. Highest marks will get 1st rank. If marks are similar then they'll secure same rank.

Sample input and output
enter no. of students n
10
enter space separated marks for students
4 6 7 8 9 9 9 10 10 15
Output-
10 9 8 7 4 4 4 2 2 1 

*/

//Solution
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout<<"enter no. of students n\n";
    cin>>n;
    
    int marks [n];
    cout<<"enter space separated marks for students\n";
    for(int i=0; i<n; ++i)
        cin>>marks[i];
    
    int ranks [n];
    
    //sort the marks array
    sort(marks, marks+n);
    
    //reverse the marks array
    reverse(marks, marks+n);
    
    // for(int i: marks)
    //     cout<<i<<" ";
    
    ranks[0]=1;
    
    for(int i=1; i<n; i++)
    {
        if(marks[i]==marks[i-1])
            ranks[i]=ranks[i-1];
        else
            ranks[i]=i+1;
    }
    
    reverse(ranks, ranks+n);
    
    cout<<"Output-\n";
    for(int i: ranks)
        cout<<i<<" ";

    return 0;
}
