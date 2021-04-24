/*Write a java program which takes input from 1 to 9 and  
prints "ONE", "TWO",... , "NINE", "OTHER" respectively. 
Use switch  statement.*/

import java.util.Scanner;

public class SwitchNum 
{
  public static void main(String[] args)
  {
	  int a;
	  Scanner s= new Scanner(System.in);
	  System.out.println("enter number=> ");
	  a= s.nextInt();
	  
	  switch(a)
	  {
	  case 1: if(a==0)
		   System.out.println("ZERO");
	  case 2: if(a==1)
	       System.out.println("ONE");
	  case 3: if(a==2)
	       System.out.println("TWO");
	  case 4: if(a==3)
	       System.out.println("THREE");
	  case 5: if(a==4)
	       System.out.println("FOUR");
	  case 6: if(a==5)
	       System.out.println("FIVE");
	  case 7: if(a==6)
	       System.out.println("SIX");
	  case 8: if(a==7)
	       System.out.println("SEVEN");
	  case 9: if(a==8)
	       System.out.println("EIGHT");
	  case 10: if(a==9)
	       System.out.println("NINE");
	  case 11: if(a>=10)
	       System.out.println("OTHER");
	  }
	  
	  s.close();
  }
}
