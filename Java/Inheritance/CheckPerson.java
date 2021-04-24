class CheckPerson
{
	public static void main(String[] args)
	{
		PEmployee e = new PEmployee("sagar",34);
		e.myprofession();
		System.out.println("=================================");
		
		Teacher t = new Teacher("alpesh",50);
		t.myprofession();
		System.out.println("=================================");
		
		ContractEmployee c = new ContractEmployee("siju",50);
		c.myprofession();
		System.out.println("=================================");
		
		PermanentEmployee p = new PermanentEmployee("siju",50);
		p.myprofession();
		System.out.println("=================================");
	}
}