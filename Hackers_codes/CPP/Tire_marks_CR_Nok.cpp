/*
*************************************************

Tire marks
Max. score: 50

*************************************************

A tire is the main component of any car. Each tire has a specific pattern printed on it. Each pattern is denoted by a positive integer. Each car has four wheels and it is not necessary that all four wheels should contain the same pattern. You will denote the four wheels of each car in a 2D array as shown in Fig 1. You can access each tire by its row and column. 

 
The race starts at 0th sec at which all the cars are in the same position. The race ends after N seconds. You know the tire mark of the vehicle which was at the first position of the race at ith second. The data is represented in the form of a 2D matrix containing N + 1 columns. The tire mark of the car at the ith second includes the column at ith and i-1th seconds as shown in Fig 2. Assume that no two cars can have the same tire configuration.

Task

Count of the total number of cars which were in the first position for most of the time.

Note: 0-based indexing is followed.

Example

Assumptions

N = 5
A = [[2, 2, 2, 3, 3, 3], [1, 1, 1, 2, 2, 2]]
Approach

Let's look at the tire marks on every second

At 1st second, the tire mark is [[2, 2], [1, 1]].
At 2nd second, the tire mark is [[2, 2], [1, 1]].
At 3rd second, the tire mark is [[2, 3], [1, 2]].
At 4th second the tire mark is [[3, 3], [2, 2]].
At 5th second the tire mark is [[3, 3], [2, 2]].
Hence you can see that the tire marks [[2, 2], [1, 1]] and [[3, 3], [2, 2]] appear 2 times each on the first position, and no other tire marks appear more than 2 times. Therefore the count is 2.

Function description

Complete the solve function provided in the editor. This function takes the following parameter and returns the answer:

N: Represents the duration of the race
A: Represents a 2D array of integers containing N+1 columns and 2 rows
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains an integer T denoting the number of test cases. T also denotes the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains an integer N denoting the duration of the race.
The second and third line contains N + 1 space-separated integers denoting the array A.
Output format

For each test case in a new line, print the answer.

Constraints
1<=T<=10
1<=N<=10^5
1<=A[i]<100

Code snippets (also called starter code/boilerplate code)

This question has code snippets for C, CPP, Java, and Python.

SAMPLE INPUT 
2
5
1 2 2 1 2 2
3 4 4 3 4 4
2
3 3 3
3 3 3
SAMPLE OUTPUT 
2
1
Explanation
The first line represents the number of test cases, T = 2

The first test case

Given

N = 5
A = [[1, 2, 2, 1, 2, 2], [3, 4, 4, 3, 4, 4]]
Approach

Let's look at the tire marks on every second

At 1st second, the tire mark is [[1, 2], [3, 4]].
At 2nd second, the tire mark is [[2, 2], [4, 4]].
At 3rd second, the tire mark is [[2, 1], [4, 3]].
At 4th second the tire mark is [[1, 2], [3, 4]].
At 5th second the tire mark is [[2, 2], [4, 4]].
Hence the tire marks [[1, 2], [3, 4]] and [[2, 2], [4, 4]] appear 2 times each on the first position, and no other tire marks appear more than 2 times. Therefore the count is 2.

The second test case

Given

N = 2
A = [[3, 3, 3], [3, 3, 3]]
Approach

Let's look at the tire marks on every second

At 1st second, the tire mark is [[3, 3], [3, 3]].
At 2nd second, the tire mark is [[3, 3], [3, 3]].
Hence the tire marks [[3, 3], [3, 3]] appear 2 times on the first position, and no other tire marks appear. Therefore the count is 1.

***************************************************
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

int solve (int N, vector<vector<int> > A) {
    // Write your code here
    int k=2; int answer=0;
    int arr[k][k];

    //cout<<A[0].size();
    int detarr[4]; int pos=0;
    int x, y, help, inc, f;
    unordered_multiset<int> s[N];
    //multiset<int> :: iterator itr;

    while(x<2 && inc<N)
    {
        y=inc;
        for(int m=0; m<2; m++)
        {
            help=y;
            for(int n=0; n<2; n++)
            {
                arr[m][n]=A[x][y];
                y++; 
            }
            y=help; x++;
        }
             
        for(int d=0; d<2; d++)
        {
            for(int e=0; e<2; e++)
            {
                detarr[f]=arr[d][e];
                f++;
            }
        }

        //sort(detarr, detarr+4);

        // for(int d: detarr)
        //     cout<<d<<" ";
        // cout<<endl;

        for(int g=0; g<4; g++)
        {//cout<<pos<<" "<<detarr[g];
            s[pos].insert(detarr[g]);
        }//cout<<endl;

        // for(auto h:s[pos])
        //    cout<<h<<" ";
        // cout<<endl;

        x=0; pos++; inc++; f=0;
    }


    int max=0; int oldmax=0; bool flag=1;

    for(int i=0; i<N-1; i++)
    {
        // for(auto h:s[i])
        //     cout<<h<<" ";
        // cout<<endl;

        for(int j=i+1; j<N; j++)
        {
            if(s[i]==s[j]  && *s[i].begin()==*s[j].begin() && *s[i].begin()+1==*s[j].begin()+1 && *s[i].begin()+2==*s[j].begin()+2)
            {
                max++; //cout<<"y "<<i<<" "<<j;
            }
        }//cout<<endl;//cout<<max<<" ";

        if(flag)
        {
            oldmax=max; flag=0;
        }

        if(oldmax==max)
        {
            answer++;
        }
        else if(oldmax<max)
        {
            answer=1; oldmax=max;
        }  

        max=0;
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
        vector<vector<int> > A(2, vector<int>(N+1));
        for (int i_A = 0; i_A < 2; i_A++)
        {
        	for(int j_A = 0; j_A < N+1; j_A++)
        	{
        		cin >> A[i_A][j_A];
        	}
        }

        int out_;
        out_ = solve(N, A);
        cout << out_;
        cout << "\n";
    }
}
