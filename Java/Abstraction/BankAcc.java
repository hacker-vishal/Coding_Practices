import java.util.Scanner;

//use runtime polymorphism;

abstract public class BankAcc 
{
  int accno;
  String cname;
  float totbal;
  float loanamount;
  
  BankAcc(int no,String name,float bal,float loan)
  {
	 accno=no;
	 cname=name;
	 totbal=bal;
	 loanamount=loan;
  }
  
  void dispcustomer()
  {
	  System.out.println("Your acc no is "+accno);
	  System.out.println("Your acc name is "+cname);
	  System.out.println("Your balance is "+totbal);
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
  
  abstract public void interestCalculation();
}
  
  class SBI extends BankAcc
  {
  	 int notrans;
  	

  	SBI(int notrans,int accno, String cname, float totbal, float loanamount) 
  	{
  		super(accno, cname, totbal, loanamount);
  		this.notrans = notrans;
  	}


	@Override
	public void interestCalculation() 
	{
		System.out.println("interest method of SBI");
		
	}
  }


  class ICICI extends BankAcc
  {
  	 int notrans;
  	

  	 ICICI(int notrans,int accno, String cname, float totbal, float loanamount) 
  	{
  		super(accno, cname, totbal, loanamount);
  		this.notrans = notrans;
  	}

	@Override
	public void interestCalculation() 
	{
		System.out.println("interest method of ICIci ");
		
	}
  }
  




abstract class Checkingaccount extends BankAcc
{
	int fee;
  
	Checkingaccount(int no,String name,float bal,float loan)
    {
	  super(no,name,bal,loan);
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



abstract class Savingaccount extends BankAcc
{
	float interestrate;
	
	Savingaccount(int no,String name,int bal,float loan) 
	{
		super(no,name,bal,loan);
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

class CheckBankAcc
{
	public static BankAcc createObject(String cname)
	{
		
		if(cname.equals("Sbi"))
		{
		
			return   new SBI(5,1001,"Rohan",4000,10000);

		}else if(cname.equals("Icici"))
		{
			return   new ICICI(5,1002,"shan",4000,10000);
		}else
			return null;
		
	}
	
	public static void main(String[] args)
  {
		BankAcc b;
		
		Scanner s = new Scanner(System.in);
		 
		 String cname;
		 
		 System.out.println("enter the class name");
		 cname = s.next();
		 
		b =  createObject(cname);
		 
		b.dispcustomer();
		b.getbalance();
		b.interestCalculation();
  }
}
