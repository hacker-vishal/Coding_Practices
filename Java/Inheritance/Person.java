//2. Write java program to implement Inheritance with following example:
//Person will have name and age as data members. Teacher and employee will inherit data members in the super class and
//create its own method myProfession() to display their profession. Then create objects of Teacher, Permanent, and
//Contract employee to display their profession.. 


public class Person 
{
  String name;
  int age;
  
  Person(String name, int age)
  {
	  this.name=name;
	  this.age=age;
  }
}

class PEmployee extends Person
{
	PEmployee(String name, int age) 
	{
		super(name, age);
	}

	void myprofession()
	{
		System.out.println("My profession is employee");
		System.out.println("My name is "+name);
		System.out.println("My age is "+age);
	}
}

class Teacher extends Person
{
    Teacher(String name, int age) 
	{
		super(name, age);
	}
	
	void myprofession()
	{
		System.out.println("My profession is teacher");
		System.out.println("My name is "+name);
		System.out.println("My age is "+age);
	}
}


class PermanentEmployee extends PEmployee
{

	PermanentEmployee(String name, int age) 
	{
		super(name, age);
	}
	
	void myprofession()
	{
		System.out.println("I'm permanent employee");
		System.out.println("My name is "+name);
		System.out.println("My age is "+age);
	}
}


class ContractEmployee extends PEmployee
{

	ContractEmployee(String name, int age) 
	{
		super(name, age);
	}
	
	void myprofession()
	{
		System.out.println("I'm contract employee");
		System.out.println("My name is "+name);
		System.out.println("My age is "+age);
	}
}