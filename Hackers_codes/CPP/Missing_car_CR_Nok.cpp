/*
***************************************

Missing car
Max. score: 50

***************************************
The race is about to start and the referee is waiting at the starting line for the infinite number of cars. Every minute, a car arrives at starting line in the sequence S of size N. Each car is given some number that is unique.  

Task

The referee needs to report the kth missing car from the starting line every minute after sorting all the missing cars in increasing order. Determine the kth missing car for every minute.

Note: 1-based indexing is followed.

Example

Assumptions

N = 3
K = 2
S = [2, 1, 3]
Approach

In first minute: 2 arrives on starting line 
Starting line = [2]
Missing cars = [1, 3, 4, 5, ...]
Kth missing car is 3. 
In second minute: 1 arrives on starting line 
Starting line = [1, 2]
Missing cars = [3, 4, 5, 6, ...]
Kth missing car is 4.
In third minute: 3 arrives on starting line 
Starting line = [1, 2, 3]
Missing cars = [4, 5, 6, 7, ...]
Kth missing car is 5.
Function description
Complete the solve function provided in the editor. This function takes the following 3 parameters and returns an array where the ith element indicates the answer to ith minute:

N: Represents the size of the stream of cars S
K: Represents the value of K as described in the problem statement
S: Represents the numbers of the stream S of size N
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button)

The first line contains an integer T denoting the number of test cases. T also denotes the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains an integer N denoting the size of the stream S.
The second line contains an integer K.
The third line contains an array S of N integers.
Output format
For each test case, print an array representing the answer where the ith element indicates the answer to ith minute.

Constraints
1<=T<=10
1<=N<=10^5
1<=K<=N
1<=S[i]<=N

Code snippets (also called starter code/boilerplate code)
This question has code snippets for C, CPP, Java, and Python.

SAMPLE INPUT 
1
5
3
5 4 3 2 1
SAMPLE OUTPUT 
3 3 6 7 8 
Explanation
The first line contains the number of test cases, T = 1.

The first test case

Given

N = 5
K = 3
S = [5, 4, 3, 2, 1]
Approach

In first minute: 5 arrives on starting line 
Starting line = [5]
Missing cars = [1, 2, 3, 4, 6, ...]
Kth missing car is 3. 
In second minute: 4 arrives on starting line
Starting line = [4, 5]
Missing cars = [1, 2, 3, 6, 7, ...]
Kth missing car is 3. 
In third minute: 3 arrives on starting line 
Starting line = [3, 4, 5]
Missing cars = [1, 2, 6, 7, 8, ...]
Kth missing car is 6. 
In fourth minute: 2 arrives on starting Line, 
Starting Line = [2, 3, 4, 5]
Missing cars = [1, 6, 7, 8, 9, ...]
Kth missing car is 7. 
In fifth minute: 1 arrives on starting line
Starting line = [1, 2, 3, 4, 5]
Missing cars = [6, 7, 8, 9, 10, ...]
Kth missing car is 8. 

*****************************************
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

vector<int> solve (int N, int K, vector<int> S) {
    // Write your code here
    vector<int> answer;
    set<int> miss;
    set<int>:: iterator itr;
    set<int>:: iterator it;

    for(int j=1; j<=N; j++)
        miss.insert(j);

    int temp=1; int help=N; int k=K-1;

    while(temp<=N)
    {
        for(int i=0; i<temp; i++)
        {
            itr=miss.find(S[i]);
            
            if(itr!=miss.end())
            {
                miss.erase(itr); miss.insert(++help); //cout<<endl<<help<<endl;
            }
        }

        // for(it=miss.begin(); it!=miss.end(); it++)
        //     cout<<*it;
        // cout<<endl;

        it=miss.begin();

        for(int l=0; l<k; l++)
            it++;

        //cout<<*miss.begin()<<endl;

        answer.push_back(*it);

        temp++;
    }

    //miss.clear();

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
        int K;
        cin >> K;
        vector<int> S(N);
        for(int i_S = 0; i_S < N; i_S++)
        {
        	cin >> S[i_S];
        }

        vector<int> out_;
        out_ = solve(N, K, S);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}
