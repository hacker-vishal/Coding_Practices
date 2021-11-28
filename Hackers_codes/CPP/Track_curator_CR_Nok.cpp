/*
***************************************

Track curator
Max. score: 100
***************************************
Your friend is a race track curator. His job is to prepare tracks for Formula 1 races, but recently your friend has been very sloppy at his job and he did not notice earlier that there are large boulders on the race track. 

Now, the race is very close and he can remove at most one boulder from the race track and since he may lose his job if he fails to clear a long enough track for the race, you must help him decide which one boulder he should remove to maximize the length of the clear track.

Assume that the track is given to you in the form of a string S of size N and each character of S represents one unit length of the track. The string S consists of characters ' * ' and ' . ', where ' * ' represents boulders and ' . ' represents clear track portion.

Task
Determine the maximum length of the clear track that can be obtained by removing at most one boulder.

Notes

1-based indexing is followed.
There can be multiple such boulders, removing any one of which maximizes the length of the clear track.
Since your friend is very poor at his job, it may be the case that there is not even a single boulder on the whole track. In that case, the whole length of the track is available for use.
Example

Assumptions

N = 7
S = *..*..*
Approach

You can remove the boulder at position 4 to clear the track from position 2 to 6. Hence the answer is 5.

Function description

Complete the solve function provided in the editor. This function takes the following 2 parameters and returns an integer denoting the answer:

N: Represents an integer denoting the length of the string S
S: Represents the input string denoting the track
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains an integer N denoting the length of the string S.
The second line contains the string S.
Output format
For each test case in a new line, print the answer.

Constraints
1<=T<=10
1<=N<=10^5
S contains '.' and '*'

Code snippets (also called starter code/boilerplate code)

This question has code snippets for C, CPP, Java, and Python.

SAMPLE INPUT 
2
5
*...*
7
*..*..*
SAMPLE OUTPUT 
4
5
Explanation
The first line contains the number of test cases, T = 2.

For the first test case

Given

N = 5
S = *...*
Approach

You can remove the boulder at position 1 to clear the track from position 1 to 4. Hence the answer is 4.

For the second test case

Given

N = 7
S = *..*..*
Approach

You can remove the boulder at position 4 to clear the track from position 2 to 6. Hence the answer is 5.

*************************************
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

int solve (int N, string S) {
    // Write your code here
    int answer;

    vector<int> help;

    for(int i=0; i<N; i++)
    {
        if(S[i]=='*')
            help.push_back(i);
    }

    int size=0; int lim=help.size(); //cout<<lim;

    // for(int i: help)
    //     cout<<i<<" ";

    while(size<lim)
    {
        // cout<<"y ";
        int dcount=0, temp=0, x=0, j=0;
        string s=S; //cout<<s<<endl;
        s[help[size]]='.';  //for(char c:s)cout<<c; cout<<endl;
        // for(int i=0, j=i; i<N; i++)
        // {
            while(s[j]!='\0')
            {
                if(s[j]=='.')
                    dcount++;
                else
                {
                    //x=j;
                    temp=dcount; dcount=0;
                }

                if(temp<dcount)
                    temp=dcount;

                j++;
            }
        //     i=x; 
        // }
        if(answer<temp)
            answer=temp;

        size++;
    }

    return answer;
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

        int out_;
        out_ = solve(N, S);
        cout << out_;
        cout << "\n";
    }
}
