/*
Number n is given. n amount of map entries are provided.
Random no of keys will be given. For those keys, if map entry found,
print that entry in the format 'key=value', else print 'Not found'.

Sample Input

3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry

Sample Output

sam=99912222
Not found
harry=12299933
*/

//solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     
    int n;
    string s;
    long x;
    
    cin >> n;
    cin.ignore();
     
    map<string, long> mp;    
    
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cin >> x;
       
        mp[s] = x;
    }
    
    //map<string, long> :: iterator itr;
    
    while(cin >> s)
    {
        //cout << s;
        // cout << itr->first << "\t" << itr->second << endl;
        if(mp.find(s)->first == s)
        {
            cout << s << "=" << mp.find(s)->second << endl;
        }
        else 
        {
            cout << "Not found" << endl;
        }
    }
     
    return 0;
}
