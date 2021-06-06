/*

problem statement-

variable sized array will be created. No of queries will be given.

For the given queries, index of vector is given and index of element
in given vector is given, we've to find the element and print on 
separate lines.



Sample Input

2 2             2=no. of vectors in vector array, 2=no. of queries 
3 1 5 4         3=size of vector, 1,5,4=elements of vector
5 1 2 8 9 3     5=size of vector, 1,2,8,9,3=elements of vector
0 1             0=index of vector in vector array, 1=index of element to be found
1 3             1=index of vector in vector array, 3=index of element to be found

Sample Output

5
9

*/



//solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n, q, k, i, j;
    
    cin >> n;  //"enter no of arrays"
    
    cin >> q;  //"enter no of queries"
    
    
    vector <int> a[n];
    
    for(int x=0; x<n; x++)
    {
        cin >> k;  //"enter size of array"
        
        for(int y=0; y<k; y++)
        {   
            int l;
            
            cin >> l;
            
            a[x].push_back(l); 
            
            // for (auto& it : a[x]) {
  
            // // Print the values
            // cout << it << ' ';
            // }
        
            // cout << endl;
        
        }
    }
    
    for(int z=0; z<q; z++)
    {    
        cin >> i;  //enter index of vector in vector array
        //cout << i;
        cin >> j;  //enter index of element to be found in vector
        //cout << j; 
        vector<int>::iterator ptr = a[i].begin();
        
        advance(ptr, j);
        
        cout << *ptr << endl;
    }
     
    return 0;
}