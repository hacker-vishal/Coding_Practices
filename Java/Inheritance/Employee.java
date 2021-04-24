//Write java program to implement Inheritance with Employee example

public class Employee 
{
  int SSN;
  String fname;
  String lname;
  
  Employee(int no,String fn,String ln)
  {
	  this.SSN=no;
	  this.fname=fn;
	  this.lname=ln;
  }
  
  void salary()
  {
	  System.out.println("Employee has salary");
  }
}

class HourlyEmployee extends Employee
{
	HourlyEmployee(int no, String fn, String ln) 
	{
		super(no, fn, ln);
		System.out.println("This is an hourly employee");
		System.out.println("My SSN is "+SSN);
		System.out.println("My name is "+fname+" "+lname);
	}
	
	void salary(int sal)
	{
		int salary=sal;
		System.out.println("Hourly employee gets Rs."+salary);
	}
}

class SalariedEmployee extends Employee
{
	SalariedEmployee(int no, String fn, String ln) 
	{
		super(no, fn, ln);
		System.out.println("My SSN is "+SSN);
		System.out.println("My name is "+fname+" "+lname);
	}
	
	void salary(int sal,float tx)
	{
		int salary=sal;
		float tax;
		
		tax=sal*(tx/100);
		salary=(int) (salary-tax);
		System.out.println("Regular employee gets Rs."+salary);
	}
}



