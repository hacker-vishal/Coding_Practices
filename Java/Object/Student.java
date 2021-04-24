/*Write a Java program to create Student class with member variable 
as id, name, mark and result. Use method to initialize the value 
of name, id and marks. Write a member function to find the result 
and display the student details with result.  */

import java.util.Scanner;

public class Student 
{
	 int id;
	 String name;
	 int[] mark= new int[5];
	 int result;
	 
	 void setStudDetails()
	    {
	    	 Scanner s = new Scanner(System.in);
	 		
	 		System.out.println("enter the details");
	 		id = s.nextInt();
	 		name  = s.next();
	 		for(int i = 0 ;i<5;i++)
	 		{
	 		mark[i] = s.nextInt();
	 		}
	 		s.close();
	    }
	 
	  int createResult()
	  {
		  int sum=0;

		  for(int i = 0 ;i<5;i++)
		  {
		  sum= sum+mark[i];
		  }

		  result=sum/5;
		  return result;
	  }
	    
	    void dispStudDetails()
	    {  	
	    	System.out.println(id);
	    	System.out.println(name);
	    	System.out.println("result is "+result+" %");
	    }
    
	public static void main (String[] args)
	{
		Student s1 = new Student();
		s1.setStudDetails();
		s1.createResult();
		s1.dispStudDetails();
	}
}
