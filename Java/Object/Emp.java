/*Create a class called Emp with data members empno, empname, 
designation, dept and salary and   methods as 
readEmpData() (to read  values to data members) and 
displayEmpData() (to display data members values to the screen) 
create an employee instance and display its information.
*/
public class Emp 
{
	int empno;
    String empname;
    String desg;
    String dept;
    float sal;
    
    void readEmpData(int empno,String empname,String desg,String dept,float sal)
    {
    	this.empno=empno;
    	this.empname=empname;
    	this.desg=desg;
    	this.dept=dept;
    	this.sal=sal;
    }
    
    void dispEmpData()
    {
    	   	
    	System.out.println("Employee no is "+empno);
    	System.out.println("Employee name is "+empname);
    	System.out.println("Employee designation is "+desg);
    	System.out.println("Employee department is "+dept);
    	System.out.println("Employee salary is "+sal);
    }
   
    
    
    public static void main(String[] args) 
 	{
 	    Emp e1 = new Emp();
 	    e1.readEmpData(1,"sagar","director","management",150000);
 	    e1.dispEmpData();
 	}
}
