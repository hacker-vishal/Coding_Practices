/*

Sample Input

6                 - size of vector
1 4 6 2 8 9	  - elements of vector
2		  - index of element to be deleted from vector
2 4               - range in which vector element to be deleted, inclusive of lower limit, exclusive of upper limit

Sample Output

3		  - size of vector after erase operation
1 8 9		  - print elements remaining in vector

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
    
    vector<int> v;
    int n=0;
    cin >> n;
    while(n>0)
    {
        int m=0;
        cin>>m;
        v.push_back(m);
        n--;
    }
    
    int remove_int_at_index_given=0;
    cin >> remove_int_at_index_given;
    v.erase(v.begin()+remove_int_at_index_given-1);
    
    int lower_limit=0;
    int upper_limit=0;
    
    cin >> lower_limit >> upper_limit;
    
    v.erase(v.begin()+lower_limit-1, v.begin()+upper_limit-1);
    
    cout << v.size() << endl;
    
    vector<int>::iterator it;
    
    for(it=v.begin(); it<v.end(); it++)
        cout << *it << " ";
    
    return 0;
}
