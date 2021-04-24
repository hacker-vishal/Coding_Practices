//Implementation of interface on Bank

import java.util.Scanner;

public interface Credit
{
	public void Currency();
}

class Rupees implements Credit
{

	public void Currency() 
	{
	    System.out.println("Enter amount in Rs.");
	}
}

class Dollars implements Credit
{

	public void Currency() 
	{
	    System.out.println("Enter amount in Dollars.");
	}
}

class Pounds implements Credit
{

	public void Currency() 
	{
	    System.out.println("Enter amount in Pounds.");
	}
}

abstract class TestCredit
{

	public static Credit Object(String currency)
	{
		if(currency.equals("Rupees"))
			return new Rupees();
		if(currency.equals("Dollars"))
			return new Dollars();
		if(currency.equals("Pounds"))
			return new Pounds();
		return null;
	}
	
	public static void main(String[] args)
	{
		Credit c;
		
		Scanner s = new Scanner(System.in);
		System.out.println("enter the currency name");
		String currency = s.next();
		
		
		c = Object(currency);
		c.Currency();
		
	}
}