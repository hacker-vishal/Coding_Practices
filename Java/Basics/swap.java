//Write a program to swap the given two numbers.

import java.util.Scanner;

public class swap
{
	public static void main(String[] args)
	{
		  int a;
		  int b;
		  int temp;
		 
		  Scanner s= new Scanner(System.in);
		  System.out.println("enter number=> ");
		  a= s.nextInt();
		  b= s.nextInt();
		  
		  temp=a;
		  a=b;
		  b=temp;
		  
		  System.out.println("a= "+a);
		  System.out.println("b= "+b);
		  
		  s.close();
	}
}

