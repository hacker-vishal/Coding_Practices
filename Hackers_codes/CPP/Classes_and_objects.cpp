/*
Given number of students in class, first students marks are given on first line, find 
no. of students from remaining students who has scored more than first student.

Sample Input

3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output

1

*/

//Solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here

class Student
{
    int scores [5];
    int total;
    
public:
    Student()
    {
        total = 0;
    }
    
    void input()
    {
        for(int i = 0; i < 5; i++)
        {
            cin >> scores[i];
            total += scores[i];
        }
    }
    
    int calculateTotalScore()
    {
        return total;
    }
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
