import java.util.Scanner;

abstract public class Bank implements Credit
{
   int cid;
   String cname;
   float balance;
   float loanamount;
   
   
   Bank(int cid, String cname, float balance, float loanamount)
   {
	
	this.cid = cid;
	this.cname = cname;
	this.balance = balance;
	this.loanamount = loanamount;
}

   void deposit()
   {
	   System.out.println("deposit done");
   }
   
   void withdraw()
   {
	   System.out.println("withdraw done");
   }
   
   void getbalance()
   {
	   System.out.println(balance);
   }
   
   
   abstract public void interestCalucation();
   
   
  /* void interestCalucation()
   {
	   
	      float interestamount=0;
	      interestamount = loanamount*0.03f;
	      
	     float emi = loanamount+interestamount/12;
	      
	   System.out.println(interestamount + emi);
   }*/
   
   void dispcustomer()
   {
	   System.out.println(cid+cname+balance+loanamount);
   }
   
}

class Sbi extends Bank
{
	 int notrans;
	

	Sbi(int notrans,int cid, String cname, float balance, float loanamount) 
	{
		super(cid, cname, balance, loanamount);
		this.notrans = notrans;
	}


   public  void interestCalucation() {
		
		System.out.println("interest method of SBI");
		
	}


@Override
public void Currency() {
	// TODO Auto-generated method stub
	
}
	}


class Icici extends Bank
{
	 int notrans;
	

	 Icici(int notrans,int cid, String cname, float balance, float loanamount) 
	{
		super(cid, cname, balance, loanamount);
		this.notrans = notrans;
	}


	public void interestCalucation() {
		
		System.out.println("interest method of ICIci ");
		
	}


	@Override
	public void Currency() {
		// TODO Auto-generated method stub
		
	}
	}


class TestBank
{
	
	
	public static Bank createBankObject(String cname)
	{
		
		if(cname.equals("Sbi"))
		{
		
			return   new Sbi(5,1001,"shan",4000,100000);

		}else if(cname.equals("Icici"))
		{
			return   new Icici(5,1001,"shan",4000,100000);
		}else
			return null;
		
	}
	
	
	
	
	public static void main(String[] args) 
	{
		
		Bank b;
		Credit c;
		
		Scanner s = new Scanner(System.in);
		 
		 String cname;
		 
		 System.out.println("enter the class name");
		 cname = s.next();
		 
		b =  createBankObject(cname);
		 
		b.dispcustomer();
		b.getbalance();
		b.interestCalucation();
		
	}
}