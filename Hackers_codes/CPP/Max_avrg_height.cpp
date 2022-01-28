/*
Given heights of n students. Find max avrg of 3 consecutive students.

Enter no of students				
6						-> no of students
Enter space separated heights of students
1 2 3 4 5 6					-> heights of students

5						-> max avrg height for 3 consecutive students

*/

//Solution
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter no of students\n";
    cin>>n;
    
    int arr[n];
    cout<<"Enter space separated heights of students\n";
    for(int i=0; i<n; ++i)
        cin>>arr[i];
        
    int avrg=0; 
    int max_avrg=0;
        
    for(int i=0; i<n-2; ++i)
    {
        int sum=0;
        for(int j=i; j<i+3; ++j)
        {
            sum+=arr[j];
        }
        avrg=sum/3;
            
        if(avrg>max_avrg)
            max_avrg=avrg;
    }
    
    cout<<max_avrg;
}
