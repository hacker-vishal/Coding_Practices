/*
Given a 3*3 matrix, find max no that can be formed from horizontal and vertical combination
of matrix elements.

Enter space separated elements of matrix
1 2 3 4 5 6 7 8 9 			 -> matrix elements

789					 -> answer

*/

//Solution
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[3][3];
    string str="";
    int numarr[6];
    int pos=0;
    
    cout<<"Enter space separated elements of matrix\n";
    
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            cin>>arr[i][j];
            str+=to_string(arr[i][j]);
        }
        numarr[pos]=stoi(str);
        ++pos;
        str="";
    }
    
    //for getting column-wise numbers
    for(int i=0; i<3; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            str+=to_string(arr[j][i]);
        }
        numarr[pos]=stoi(str);
        ++pos;
        str="";
    }
    
    cout<<*max_element(numarr, numarr+6);
}
