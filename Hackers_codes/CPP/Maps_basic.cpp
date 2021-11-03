/*
 
Given a number Q viz. no. of queries. For each query, 
if format is '1 X Y' -> add marks Y to student X, 
if format is '2 X' -> erase marks for student X,
if format is '3 X' -> print marks for student X.

Sample Input

7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
Sample Output

30
20
0
*/

//Solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int Q;
    cin >> Q;
    string y;
    int x, marks;
    map<string, int> m;

    while(cin >> x >> y)
    {
       switch (x)
       {
            case 1:
                cin >> marks;
                m[y]+=marks;
                break;
            case 2:
                m.erase(y);
                break;
            case 3:
                cout << m[y] << endl;
       }
    }

    return 0;
}
