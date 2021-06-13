/*
given is a int, double and string. Read another set of int, double and string.
Print addition of ints and doubles and print concatenated strings

Given

4
4.0
HackerRank

Sample Input

12
4.0
is the best place to learn and practice coding!

Sample Output

16
8.0
HackerRank is the best place to learn and practice coding!
*/

//solution

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int j = 0;
    double e = 0.0;
    string t = "";
    string u = "";
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    cin >> j;
    cin >> e;
    getline(cin >> ws,t);
    //cin.ignore();
    //getline(cin, t);
    
    // Print the sum of both integer variables on a new line.
    cout << i + j << endl;
    
    // Print the sum of the double variables on a new line.
    e = d + e;
    cout << fixed << setprecision(1);
    cout << e << endl;
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + t << endl;
    return 0;
}