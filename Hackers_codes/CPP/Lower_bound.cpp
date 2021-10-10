/*
Given a sorted vector of size n and queries q. For each query find the index of element in vector.

Sample Input

 8			-> size of vector n	
 1 1 2 2 6 9 9 15	-> elements of vector
 4			-> no of queries q
 1			-> find index of given elements.. if found, print "Yes <index>", if not there, print "No <index of element just greater than given element>"
 4
 9
 15

Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8

*/

//Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n=0;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        int temp=0;
        cin >> temp;
        v[i]=temp;
    }
    
    int q=0;
    cin >> q;
    
    while(q>0)
    {
        int num=0;
        cin >> num;
        
        vector<int>::iterator it;
        
        it= lower_bound(v.begin(), v.end(), num);
        
        if(*it == num)
            cout << "Yes " << it-v.begin()+1 << endl;
        else 
            cout << "No " << it-v.begin()+1 << endl;
        
        q--;
    }
    
    return 0;

