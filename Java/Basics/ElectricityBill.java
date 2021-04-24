/* write a java program to input number of units consumed by a customer using scanner class 
      and generate electricity bill by the  following criteria.
	    number of units		            charges
		< = 100			                Rs.1.20
	    for the next 200 units 	        Rs. 2.00
	    for the next 300 units	        Rs. 3.00
		for more		                Rs. 5.00		
ex:  input = 320 units output = 100*1.20 +200*2.00+20*3.00 =  Rs. 580  
*/


import java.util.Scanner;

public class ElectricityBill 
{
	public static void main(String[] args)
	  {
		  int units;
		  float charges=0;
		  Scanner s= new Scanner(System.in);
		  System.out.println("enter units=> ");
		  units= s.nextInt();
		  
		  if(units<=100) charges=(100*1.2f);
		  else if(units>100 && units<=300) charges=(((units-100)*2)+(100*1.2f));
		  else if(units>300 && units<=600) charges=((units-300)*3+(200*2)+(100*1.2f));
		  else charges=((100*1.2f)+(200*2)+(300*3)+(units-600)*5);
		  
		  System.out.println("Your Bill is Rs. "+charges);
		  s.close();
	  }
}
