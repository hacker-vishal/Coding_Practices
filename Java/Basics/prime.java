//Write a java program to print prime numbers upto given number. 

import java.util.Scanner;

public class prime 
{
	public static void main(String[] args)
	  {
		  int a;
		  Scanner s= new Scanner(System.in);
		  System.out.println("enter number=> ");
		  a= s.nextInt();
		  s.close();
		  
		  String num="";
	       int n=0;
	       int i=0;

	       for (i = 1; i <= a; i++)         
	       { 		  	  
	          int cntr=0; 	  
	          for(n=i; n>=1; n--)
		  {
	             if(i%n==0)
		     {
	 		cntr = cntr + 1;
		     }
		  }
		  if (cntr ==2)
		  {
		     num = num + i + " ";
		  }	
	       }	
	       System.out.println("Prime numbers up to "+a+" are :");
	       System.out.println(num);
	  }
}