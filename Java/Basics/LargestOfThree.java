//Write Java Program  to  Find Largest of Three Numbers

import java.util.Scanner;

public class LargestOfThree 
{
	public static void main(String[] args)
	  {
		  int a;
		  int b;
		  int c;
		  int temp=0;
		  
		  Scanner s= new Scanner(System.in);
		  System.out.println("enter number=> ");
		  a= s.nextInt();
		  b= s.nextInt();
		  c= s.nextInt();
		  
		  if(a>b) temp=a;
		  else temp=b;
		  
		  if(temp>c)
			  System.out.println("largest num is "+temp);
		  else
			  System.out.println("largest num is "+c);
		  
		  s.close();
	  }
}
