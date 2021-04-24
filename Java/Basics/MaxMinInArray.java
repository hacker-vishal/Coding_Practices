//Write a Java program to find the maximum and minimum value of an array

import java.util.Scanner;

public class MaxMinInArray 
{
	public static void main(String[] args)
    {
	    int max=0;
	    int min=0;
	    int temp=0;
        int[] mark= new int[5];	
	    Scanner s = new Scanner(System.in);
 		
	    System.out.println("enter the numbers");
 		for(int i=0;i<5;i++)
 		{
 		mark[i] = s.nextInt();
 		}
 		
 		for(int i=0;i<5;i++)
 		{
 			if (temp<mark[i])
 				max=mark[i];
 			else max=temp;
 			temp=max;
 		}
 		System.out.println("Max num is "+max);
 		
 		for(int i=0;i<5;i++)
 		{
 			if (temp<mark[i])
 				min=temp;
 			else min=mark[i];
 			temp=min;
 		}
 		System.out.println("Max num is "+min);
 		
 		s.close();
    }
}
