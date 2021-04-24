//Write a java program to reverse the given number.

import java.util.Scanner;

public class ReverseNumbers 
{
    public static int revnum(int a)
    {
    	int reverse=0;
    	int num;

        while(a != 0)
        {
            num=(a%10);
        	a /= 10;
        	reverse= reverse*10 + num;
        }
        return reverse;
    }
	
	public static void main(String[] args)
  {
	  int a;
	  int reverse;
	  Scanner s= new Scanner(System.in);
	  System.out.println("enter number=> ");
	  a= s.nextInt();
	  
	  reverse=revnum(a);
	  
	  System.out.println("reverse no is " + reverse);
	  
	  s.close();
  }
}