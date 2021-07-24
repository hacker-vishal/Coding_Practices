/*
You are given two classes, Person and Student, where Person is the base class and Student 
is the derived class. Observe that Student inherits all the properties of Person.

Sample Input

Heraldo Memelli 8135627 //firstname, lastname, id
2                       //no of subjects
100 80                  //scores --> find avrg and print grade for that

Sample Output

Name: Memelli, Heraldo
ID: 8135627
Grade: O
*/

//Solution
#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        string firstName;
        string lastName;
        int id;
        vector<int> scores;
        
        Student(string firstName, string lastName, int id, vector<int> scores):Person(firstName, lastName, id)
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->id = id;
            this->scores = scores;
        }
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
            int num = scores.size();
            int sum = 0;
            char grade;
            
            for(int i: scores)
            {
                sum += i;
            }
            
            int avrg = sum/num;
            
            if(avrg<=100 && avrg>=90)
                grade = 'O';
            else if(avrg<90 && avrg>=80)
                grade = 'E';
            else if(avrg<80 && avrg>=70)
                grade = 'A';
            else if(avrg<70 && avrg>=55)
                grade = 'P';
            else if(avrg<55 && avrg>=40)
                grade = 'D';
            else 
                grade = 'T';
                
            return grade;
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}