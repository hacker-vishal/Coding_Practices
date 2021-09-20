/*

Problem-
Given an integer N, take N no. of inputs and store it in vector.
Sort the vector and print the numbers in sorted order.

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
    
    int N;
    cin >> N;
    vector<int> v;
    
    while(N)
    {
        int n;
        cin >> n;
        v.push_back(n);
        N--;
    }
     
    sort(v.begin(), v.end());
    
    vector<int>::iterator it;
    
    for(it=v.begin(); it<v.end(); it++)
        cout << *it << " ";
    
    return 0;
}

