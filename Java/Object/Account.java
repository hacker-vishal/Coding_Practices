/*Write a Java program that creates a  account classs with instance 
variable accno,accname,amount and instance method  withdraw, 
deposit, and  interest. Create object of account class test all 
methods. */

public class Account 
{
	int accno;
	String accname;
	double amount;
	int totbal;
	
	Account(int accno,String accname,double amount)
	  {
		 this.accno=accno;
		 this.accname=accname;
		 this.amount=amount;
	  }
	
	void showAcc()
	{
		 System.out.println("Your account no is "+accno);
		 System.out.println("Account name is "+accname);
		 System.out.println("Your balance is Rs. "+amount);
		 System.out.println("========================================================");
	}
	
	public void deposit(int amnt)
	  {  
		System.out.println("Rs."+ amnt +" deposited in your account");
		  totbal=(int) (amount+amnt);
		  System.out.println("Your balance is Rs."+ totbal);
		  System.out.println("========================================================");
	  }
	  
	  public void withdraw(int amnt)
	  {
		  if(totbal<amnt)
			  System.out.println("Not enough balance"); 
		  else
			  {totbal=(int) (totbal-amnt);
		       System.out.println("Rs."+ amnt +" withdrawn from your account");
			  }
		  System.out.println("Your balance is Rs."+ totbal);
		  System.out.println("========================================================");
	  }
	  
	  void interest()
		{
		    float interestrate;
		    interestrate=6.5f;
			if(totbal>500)
			{
				int interest=(int) (totbal*(interestrate/100));
				totbal=totbal+interest;
				System.out.println("Rs."+interest+" has been added as an interest");
				System.out.println("Your balance is Rs."+ totbal);
				System.out.println("========================================================");
			}
		}
	  
	  public static void main(String[] args)
	  {
		  Account c = new Account(1,"akash",40000);
		  c.showAcc();
		  c.deposit(44000);
		  c.withdraw(50000);
		  c.interest();
	  }

}
