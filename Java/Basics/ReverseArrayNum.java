//Write a Java program to reverse an array of integer values

import java.util.Scanner;

public class ReverseArrayNum 
{
	public static void main(String[] args)
	{
        int[] arr= new int[5];
        int[] rev= new int[5];
        
	    Scanner s = new Scanner(System.in);
 		
	    System.out.println("enter the numbers");
 		for(int i=0;i<5;i++)
 		{
 		arr[i] = s.nextInt();
 		}
 		
 		for(int i=4;i>=0;i--)
 		{
 			rev[4-i]=arr[i];
 		} 
 		
 		System.out.println("reversed string is= ");
 		for(int i=0;i<5;i++)
 		{
 			System.out.println(rev[i]);
 		} 
 		s.close();
    }
}
