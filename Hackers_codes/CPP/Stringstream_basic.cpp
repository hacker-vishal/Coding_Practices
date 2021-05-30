
//problem statement

/*
A string with n number of integers is given, parse it and put each number in
vector. Return this vector and display results as shown in sample.


Sample Input

23,4,56
Sample Output

23
4
56
*/



//Solution

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> v;
    
    stringstream ss(str);
    char ch;
    int a;
    // int b, c;
    
    // ss >> a >> ch >> b >> ch >> c;
    
    // v.push_back(a);
    // v.push_back(b);
    // v.push_back(c);
    
    while(ss >> a)
    {
        v.push_back(a);
        ss >> ch;
    }
    
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}