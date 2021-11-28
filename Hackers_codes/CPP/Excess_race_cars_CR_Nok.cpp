/*
*******************************************
Excess race cars
Max. score: 50
*******************************************
You are given an integer N and a string S of length N.

There are 26 teams in the contest. The first team is represented by character 'A', the second team is represented by character 'B', and so on.

Each team has their race cars (possibly zero) lined up at the start point. It is represented by string S. Some teams have more race cars than required.

Task

For every team, you have to remove 2^j(j>=1)  cars from the start line without changing the order of other cars. Print the final sequence of the cars at the start line.

Notes

1-based indexing is followed.
The cars are numbered from left to right.
Example

Assumptions

N = 7
S = "ABCAABA"
Approach

For team 'A', there are 4 cars:
Index 1, Index 4, Index 5, Index 7
For j = 1,
2^j=2; Remove the second car (Index 4)
For j = 2,
2^j=4; Remove the fourth car (Index 7)
For team 'B', there are 2 cars:
Index 2, Index 6
For j = 1,
2^j=2; Remove the second car (Index 6)
For team 'C', there is 1 car:
Index 3
Therefore, the final sequence of cars is:
"ABCA"

Function description

Complete the solve function provided in the editor. This function takes the following 2 parameters and returns the final sequence of cars at the start point:

N: Represents the total number of cars
S: Represents the sequence of cars lined up at the start point
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains an integer T denoting the number of test cases. T also denotes the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains an integer N denoting the total number of cars.
The second line contains a string S of length N representing the sequence of cars lined up at the start point.
Output format

For each test case in a new line, print the final sequence of cars.

Constraints
1<=T<=10
1<=N<=10^5
|S|=N

S only consists of uppercase letters.

Code snippets (also called starter code/boilerplate code)

This question has code snippets for C, CPP, Java, and Python.

SAMPLE INPUT 
2
5
ABCDE
7
ABCAABA
SAMPLE OUTPUT 
ABCDE
ABCA
Explanation
The first line contains the number of test cases, T = 2

The first test case

Given

N = 5
S = "ABCDE"
Approach

Each team has only one race car.

Therefore, the answer is "ABCDE"


***********************************
*/

//Solution

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

string solve (int N, string S) {
    // Write your code here
    string solution;
    // solution+='M';

    // cout<<int('C');
    int arr[26]={};

    // for(int i:arr)
    //     cout<<i<<" ";
    int count=0;
   
    for(char c: S)
    {  
        count=arr[int(c)-65];
        count++;
        arr[int(c)-65]=count;

        bool flag=0; int x=1; int z=arr[int(c)-65];

        while(pow(2,x)<=z)
        {
            if(pow(2,x)==z)
            {
                flag=1;break;
            }
            else
                x++;
        }

        if(flag)
            continue;
        else
            solution+=c;
    }
   
    return solution;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        string out_;
        out_ = solve(N, S);
        cout << out_;
        cout << "\n";
    }
}
