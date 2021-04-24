import java.sql.*;
import java.util.Scanner;  
public class Product 
{
	static Scanner sc  = new Scanner(System.in);
	
	public static void insert(String s, PreparedStatement p) throws SQLException
	{
		//insert product data 
		PreparedStatement pmt1=p;
		System.out.println("enter id,name,category,price,manufacturer,qnty");
		
		int id = sc.nextInt(); 
		String name = sc.next(); 
		String category = sc.next();
		float price = sc.nextFloat(); 
		String manufacturer = sc.next(); 
		int quantity =sc.nextInt();
		int totamount=0;
		pmt1.setInt(1, id); 
		pmt1.setString(2, name); 
		pmt1.setString(3, category);
		pmt1.setFloat(4, price); 
		pmt1.setString(5, manufacturer); 
		pmt1.setInt(6,quantity);
		pmt1.setInt(7,totamount);
		pmt1.executeUpdate(); 
		System.out.println("row updated");
	}
	
	public static void dispManufact(String s, PreparedStatement p) throws SQLException
	{
		//display products of a manufacturer  
		PreparedStatement pmt2 =p; 
		System.out.println("enter manufacturer name");
		String manufacturer = sc.next(); 
		pmt2.setString(1, manufacturer);
		pmt2.execute();
	}
	
	public static void discOnCateg(String s, PreparedStatement p) throws SQLException
	{
		//discount on category with update
		PreparedStatement pmt3 =p;
		System.out.println("enter category"); 
		String category = sc.next();
		pmt3.setString(1, category); 
		pmt3.execute();
	}
	
	public static void dispTotAmnt(String s, PreparedStatement p) throws SQLException
	{
		//display details with totalamount 
		PreparedStatement pmt4 =p; 
		pmt4.execute();
	}
	
	public static void callProc(CallableStatement c) throws SQLException
	{
		//call procedure 
		CallableStatement cmt =c;
	    System.out.println("enter the cat");
		String cat=sc.next(); 
		cmt.setString(1, cat);
		cmt.registerOutParameter(2, Types.VARCHAR); 
		cmt.registerOutParameter(3,Types.VARCHAR); 
		cmt.execute(); 
		String c1=cmt.getString(2); 
		String c2=cmt.getString(3); 
		System.out.println("details of "+cat+"  is "+c1+" "+c2);
	}



	
	public static void main(String args[]) throws ClassNotFoundException, SQLException
	{
		Class.forName("com.mysql.cj.jdbc.Driver"); 

		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/eidb","root","shiva@123");  
		
		String q1= "insert into product values(?,?,?,?,?,?,?)";
		PreparedStatement pmt1 = con.prepareStatement(q1);
		insert(q1,pmt1);
		
		String q2="select id,name from product where manufacturer=?";
		PreparedStatement pmt2 = con.prepareStatement(q2);
		dispManufact(q2,pmt2);
		
		String q3="update product set price = (price*0.95) where category=?";
		PreparedStatement pmt3 = con.prepareStatement(q3);
		discOnCateg(q3,pmt3);
		
		String q4="update product set totamount=(quantity*price)"; 
		PreparedStatement pmt4 = con.prepareStatement(q4);
		dispTotAmnt(q4,pmt4);
		
		CallableStatement cmt = con.prepareCall("{ call getmaxpriceproduct(?,?,?) }");   
		callProc(cmt);
	}
}
