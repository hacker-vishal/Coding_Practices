/*
Given a string, print letters at even places as a first string and 
letters at odd places as second string with space separation between 
both the string

T = no. of test cases
s = input string
n = length of the string
f = first part
l = last part

sample input-
2 => T
Hacker => string
Rank => string

sample output-
Hce akr
Rn ak
*/

//solution-

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++)
    {
        string s;
        string f = "";
        string l = "";
        int n;
        
        cin >> s;
        n = s.length();
        
        for(int j=0; j<n; j++)
        {
            if(j%2==0)
            {
                f = f + s[j];
            }
            else
            {
                l = l + s[j];
            }
        }
        
        cout << f << " " << l << endl;
    }
    
    return 0;
}
