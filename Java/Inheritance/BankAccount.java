//Write java program to implement Inheritance with BankAccount example
 
public class BankAccount 
{
  int accno;
  String accname;
  float totbal=0;
  
  BankAccount(int no,String name,int bal)
  {
	 accno=no;
	 accname=name;
	 totbal=bal;
  }
  
  public void deposit(int amnt)
  {
	  System.out.println("Rs."+ amnt +" deposited in your account");
	  totbal=totbal+amnt;
	  System.out.println("Your balance is Rs."+ totbal);
	  System.out.println("========================================================");
  }
  
  public void withdraw(int amnt)
  {
	  if(totbal<amnt)
		  System.out.println("Not enough balance"); 
	  else
		  {totbal=totbal-amnt;
	       System.out.println("Rs."+ amnt +" withdrawn from your account");
		  }
	  System.out.println("Your balance is Rs."+ totbal);
	  System.out.println("========================================================");
  }
  
  public void getbalance()
  {
	  System.out.println("Your balance is Rs."+ totbal);
	  System.out.println("========================================================");
  }
  
  void addinterest()
	{
		float interestrate;
	    interestrate=6.5f;
		if(totbal>500)
		{
			totbal=totbal+(totbal*(interestrate/100));
			System.out.println("Your balance is Rs."+ totbal);
			System.out.println("========================================================");
		}
	}
}


class Checkingaccount extends BankAccount
{
	int fee;
  
	Checkingaccount(int no,String name,int bal)
    {
	  super(no,name,bal);
	  System.out.println("Your balance is Rs."+ totbal);
	  System.out.println("========================================================");
    }
	
	void deductfee(int fee)
    {
    	this.fee=fee;
		if(totbal<500)
    	{
    		totbal=totbal-fee;
    		System.out.println("Rs."+fee+" has been deducted from your account");
    	    System.out.println("Your balance is Rs."+ totbal);
    	    System.out.println("Maintain your balance above Rs.500");
    	    System.out.println("========================================================");
    	}  
    }
	
	void addinterest(float rate)
	{
		float interestrate;
		
		interestrate=rate;
		if(totbal>500)
		{
			totbal=totbal+(totbal*(interestrate/100));
			System.out.println("Your balance is Rs."+ totbal);
			System.out.println("========================================================");
		}
	}
}



class Savingaccount extends BankAccount
{
	float interestrate;
	
	Savingaccount(int no,String name,int bal) 
	{
		super(no,name,bal);
		System.out.println("Your balance is Rs."+ totbal);
		System.out.println("========================================================");
	}
	
	void addinterest(float rate)
	{
		this.interestrate=rate;
		if(totbal>500)
		{
			totbal=totbal+(totbal*(interestrate/100));
			System.out.println("Your balance is Rs."+ totbal);
			System.out.println("========================================================");
		}
	}
}


