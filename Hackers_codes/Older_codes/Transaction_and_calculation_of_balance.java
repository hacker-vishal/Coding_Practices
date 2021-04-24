//transaction and balance

public class Main
{
	public static void main(String[] args) {
		
		double ans = transactionmethod(120,30);
		
		System.out.println(ans);
	}
	
	double x=0; //balance
	double y=0; //withdrawal amount
	
	static double charges=0.50;
	
	static double transactionmethod(double balance, double amount)
	{
	    if(balance!=0)
	    {
	        if(balance%5==0)
	        {
	            if(balance>(amount+charges))
	            {
	                balance-=(amount+charges);
	            }
	        }
	        return balance;
	    }
	    else
	        return balance;
	}
}