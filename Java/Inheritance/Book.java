/*A class called Author is designed as shown in the class diagram. It contains:
•	Three private member variables: name (String), email (String), and gender (char of either 'm' or 'f' - you might also use a boolean variable called isMale having value of true or false).
•	A constructor to initialize the name, email and gender with the given values.
(There is no default constructor, as there is no default value for name, email and gender.)
•	Public getters/setters: getName(), getEmail(), setEmail(), and getGender().
(There are no setters for name and gender, as these properties are not designed to be changed.)

A Book is written by one Author - Using an "Object" Member Variable 
Let's design a Book class. Assume that a book is written by one (and exactly one) author. The Book class (as shown in the class diagram) contains the following members:
•	Four private member variables: name (String), author (an instance of the Author class we have just created, assuming that each book has exactly one author), price (double), and qty (int).
•	The public getters and setters: getName(), getAuthor(), getPrice(), setPrice(), getQty(), setQty().
*/

public class Book 
{
   String bname;
   Author auth;
   int qnty;
   double price;
   
   Book(String bname,int qnty,double price,Author auth)
   {
	   this.bname=bname;
	   this.qnty=qnty;
	   this.price=price;
	   this.auth=auth;
   }
   
   void bookprice(int qnty)
   {
	   int totalprice;
	   
	   totalprice=(int) (price*qnty);
	   System.out.println("Price of books is "+totalprice);
   }
   
   
   void showbook()
   {
	   System.out.println("Book name is "+bname);
	   System.out.println("Quantity is "+qnty);
	   System.out.println("Author of book "+bname+" is "+auth.aname); 
   }
}

class Author
{
	String aname;
	String email;
	char gender;
	
	Author(String aname,String email,char gender)
	{
		this.aname=aname;
		this.email=email;
		this.gender=gender;
		System.out.println("Author name is "+aname);
		System.out.println("Gender is "+gender+" and email is "+email);
	}
}
