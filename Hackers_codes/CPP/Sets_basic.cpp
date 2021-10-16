/*
No. of queries are given. For each query two numbers are given y and x. 
If y==1, insert x in set
   y==2, erase x from set
   y==3, check if x is present in set or not, if present print 'Yes', else print 'No'.

Sample Input

8    -> No of queries
1 9  -> Pair of y and x values
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output

Yes
No
No

*/

//Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int Q=0;
    cin >> Q;
    set<int> myset;
    set<int> :: iterator temp;
    
    for(int i=0; i<Q; i++)
    {
        int y=0; int x=0; 
        cin >> y >> x;
        
        if(y==1)
        {
            myset.insert(x);
            continue;
        }
        else if(y==2)
        {
            myset.erase(x);
            continue;
        }
        else
        {
            temp=myset.find(x);
            if((temp!=myset.end()))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
       
    return 0;
}




