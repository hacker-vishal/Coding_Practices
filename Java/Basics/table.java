//Write a java program  to  print Table of given  Number 

import java.util.Scanner;

public class table 
{
  static int[] showtable(int a)
  {
	int[] ans= new int[10];
	int val=a;
	  for(int i=0; i<10; i++)
		  {
		    ans[i]=val;
	        val=val+a;
	      }
	return ans;  
  }
  
  
  public static void main(String[] args)
  {
	  int a;
	  int[] ans;
	  Scanner s= new Scanner(System.in);
	  System.out.println("enter number=> ");
	  a= s.nextInt();
	  
	  ans=showtable(a);
	  for(int i=0;i<10;i++)
		  System.out.println(ans[i]);
	  
	  s.close();
  }
}
