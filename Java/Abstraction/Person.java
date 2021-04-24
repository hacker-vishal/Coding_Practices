public abstract class Person 
{
  String name;
  int age;
  
  Person(String name, int age)
  {
	  this.name=name;
	  this.age=age;
	  System.out.println("I am a person");
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

class CheckPerson
{
	public static void main(String[] args)
	{
		PEmployee e = new PEmployee("sagar",34);
		e.myprofession();
		System.out.println("=================================");
		
		Teacher t = new Teacher("alpesh",50);
		t.myprofession();
		System.out.println("=================================");
		
		ContractEmployee c = new ContractEmployee("siju",50);
		c.myprofession();
		System.out.println("=================================");
		
		PermanentEmployee p = new PermanentEmployee("siju",50);
		p.myprofession();
		System.out.println("=================================");
	}
}