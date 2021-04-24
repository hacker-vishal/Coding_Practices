//Write a Java program to find the second largest element in an array

import java.util.Arrays;
import java.util.Scanner;

public class SecondLargest 
{
	public static void main(String[] args)
    {
	    int max=0;
	    int[] others=new int[5];
        int[] mark= new int[5];	
	    Scanner s = new Scanner(System.in);
 		
	    System.out.println("enter the numbers");
 		for(int i=0;i<5;i++)
 		{
 		mark[i] = s.nextInt();
 		}
 		
 		max = Arrays.stream(mark).max().getAsInt();
 		
 		for(int i=0;i<5;i++)
 		{
 			if(mark[i]<max)
 				others[i]=mark[i];
 		}
 		
 		max = Arrays.stream(others).max().getAsInt();
 		
 		System.out.println("second largest in array is "+max);
 		
 		s.close();
    }
}
