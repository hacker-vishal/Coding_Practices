class Checkbank
{
  public static void main(String[] args)
  {
	  Checkingaccount c = new Checkingaccount(1,"akash",400);
	  
      c.deposit(9000);
	  
	  c.withdraw(20000);
	  
	  c.deductfee(50);
	  
	  c.withdraw(9000);
	  
	  c.deductfee(50);
	  
	  c.getbalance();
	  
	  Savingaccount s1 = new Savingaccount(2,"sagar",5000);
	  
	  s1.addinterest(5.5f);
	  
	  Savingaccount s2 = new Savingaccount(3,"vishal",5000);
	  
	  s2.deposit(2000);
  }
}
