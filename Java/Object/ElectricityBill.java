/*Create a class Electricity bill with data members as customer number, customer name, units consumed and methods as follows: XXX

1. 	readData() - to read the values of data members.
2.	showData - to display the customer details
3.	computeBill() - to calculate and return electricity charges to be paid.calculate 			the bill as specified below

             number of units		charges
		< = 100			Rs.1.20
	      for the next 200 units 	Rs. 2.00
	   for the next 300 units	Rs. 3.00
		for more		Rs. 5.00		
ex:  input = 320 units output = 100*1.20 +200*2.00+20*3.00 =  Rs. 580
 
Read customer object values, calculate electricity bill and display the values.
*/

public class ElectricityBill 
{
	int custno;
	String custname;
	int units;
	
	void readData(int custno,String custname,int units)
	{
		this.custno=custno;
		this.custname=custname;
		this.units=units;
	}
	
	void showData()
	{
		System.out.println("Customer no is "+custno);
		System.out.println("Customer name is "+custname);
		System.out.println("Units reading is "+units);
	}
	
	void computeBill(int units)
	{
		float charges=0;
		  
	    if(units<=100) charges=(100*1.2f);
	    else if(units>100 && units<=300) charges=(((units-100)*2)+(100*1.2f));
	    else if(units>300 && units<=600) charges=((units-300)*3+(200*2)+(100*1.2f));
	    else charges=((100*1.2f)+(200*2)+(300*3)+(units-600)*5);
		  
	    System.out.println("Your Bill is Rs. "+charges);
	}
	
	public static void main(String[] args)
	{
		ElectricityBill e = new ElectricityBill();
		e.readData(111,"sagar",320);
		e.showData();
		e.computeBill(320);
	}
}
