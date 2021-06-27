/*
Problem statement=>

after execution of each input, age will get increased by some no, again we'll calculate
for age and acc. to condition, we've to print the answer.


Sample Input

4  --> no of test inputs
-1 --> if no is less than 0, make it as zero and print 'age is not valid, setting to 0', 
       'you are young' is o/p, got increased to 3, again o/p is 'you are young'.
10 --> if no is less than 13, print 'you are young', got increased to 13, now o/p 
       became 'you are a teenager'(same for others)
16 --> if no < 18 and no >= 13, print 'you are a teenager'
18 --> if no > 18, print 'you are old'

Sample Output

Age is not valid, setting age to 0.
You are young.
You are young.

You are young.
You are a teenager.

You are a teenager.
You are old.

You are old.
You are old.



*/

//answer

using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if(initialAge < 0)
        {
            cout << "Age is not valid, setting age to 0." << endl;
            age = 0;
        }
        else
            age = initialAge;
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
        if(age < 13)
            cout << "You are young." << endl;
        else if(age>=13 && age<18)
            cout << "You are a teenager." << endl;
        else
            cout << "You are old." << endl;
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age += 1;
    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}