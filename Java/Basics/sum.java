//Write a program to find SUM of a given digit.

import java.util.Scanner;

public class sum 
{
 static int calcsum(int a, int b)
	  {
		 int sum =a+b;
		 return sum;
	  }
  public static void main(String[] args)
  {
	  int a;
	  int b;
	  int sum=0;
	  
	  
	  Scanner s= new Scanner(System.in);
	  
	  System.out.println("enter numbers");
	  a= s.nextInt();
	  b= s.nextInt();
	  
	  sum=calcsum(a,b);
	  
	  System.out.println("sum is "+sum);
	  
	  s.close();
  }
}
