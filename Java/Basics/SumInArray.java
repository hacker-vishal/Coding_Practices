//Write a Java program to sum values of an array. 

import java.util.Scanner;

public class SumInArray 
{
   public static void main(String[] args)
	    {
		    int sum=0;    
	        int[] mark= new int[5];	
		    Scanner s = new Scanner(System.in);
	 		
		    System.out.println("enter the numbers");
	 		for(int i = 0 ;i<5;i++)
	 		{
	 		mark[i] = s.nextInt();
	 		}
	 		
	 		for(int i=0; i<5; i++)
	 		{
	 			sum=sum+mark[i];
	 		}
	 		System.out.println("sum is "+sum);
	 		
	 		s.close();
	    }
}
