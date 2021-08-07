/*
Two strings are given, print their length, then concatenate them and print.
Now swap first chars of strings and again print them.

Sample Input

abcd
ef

Sample Output

4 2       //length of strings
abcdef    //printed concatenated string
ebcd af   //swapped first chars and printed again
*/

//Solution
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    
    string str1, str2;
    
    cin >> str1;
    
    cin >> str2;
    
    cout << str1.size() << " " << str2.size() << endl;
    
    cout << str1 + str2 << endl;
    
    char temp = str1[0];
    
    str1[0] = str2[0];
    
    str2[0] = temp;
  
    cout << str1 << " " << str2;
    
    return 0;
}
