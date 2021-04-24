class CheckEmployee
{
	public static void main(String[] args) 
	{
		HourlyEmployee h = new HourlyEmployee(22,"Amit","Mishra");
		h.salary(500);
		
		SalariedEmployee s = new SalariedEmployee(20,"Suraj","Shinde");
		s.salary(50000,5);
	}
}