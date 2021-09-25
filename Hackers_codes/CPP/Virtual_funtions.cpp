/*
For given no. of Person objects to be created, if input is 1, the object is for Professor else if input is 2, the object is for Student.
Person is base class, Professor and Student are derived class

Sample Input

4                             -> No. of Person objects to be created
1                             -> 1 is object for Professor
Walter 56 99                  -> name, age, publication
2                             -> 2 is object for Student
Jesse 18 50 48 97 76 34 98    -> name, age, marks of 6 subjects
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Sample Output

Walter 56 99 1                -> name, age, publication, no. of appearance for Professor
Jesse 18 403 1                -> name, age, sum of marks, no. of appearance for Student
Pinkman 22 135 2
White 58 87 2

*/

//Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
public:
    string name;
    int age; 

    virtual void getdata()
    {
        //cin >> name >> age;
    }
    
    virtual void putdata()
    {
        //cout << name << " " << age << endl;
    }
};

class Professor : public Person
{
    int publications;
    static int id;
    int cur_id;
    
public:
    Professor()
    {
        cur_id = ++id;
    }
    
    void getdata()
    {
        cin >> name >> age >> publications;
    }
    
    void putdata()
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id=0;

class Student : public Person
{
    int marks[6];
    static int id;
    int cur_id;
    int sum;
    
public:
    Student()
    {
        cur_id = ++id;
        sum=0;
    }

    void getdata()
    {
        cin >> name >> age;
        for(int i=0; i<6; i++)
        {
            cin >> marks[i];
            sum+=marks[i];
        }
    }
    
    void putdata()
    {
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
};

int Student::id=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

