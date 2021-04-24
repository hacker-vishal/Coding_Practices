import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

/* 2) Write a Java program to perform the following operations using Map 

* Create a class called Book with the following instance variable 

name 
price 
author name 
isbn no; 
publication 

* Create 5 Objects of book class using array of objects 
* Add all the object in to the Map using key as integer(book id) and value as Book Object 
* Display all the map object using for each 
* Read any key from the user and display the particular book object based on key 
* Reduce the price by 10% for a particular publication books and display all object with reduced price. 
*/

public class Book 
{
	String name;
	int price;
	String author;
	int isbn;
	String publication;
	
	public Book(String name,int price,String author,int isbn,String publication)
	{
		super();
		this.name = name;
		this.price = price;
		this.author = author;
		this.isbn = isbn;
		this.publication= publication;
	}
	
	public String toString()
	{
		return "Player [name="+name+",price="+price+",author="+author+",isbn="+isbn+",publication="+publication+"]";	
	}

	void disp()
	{
		System.out.println(name+" price-"+price+" author-"+author+" isbn-"+isbn+" publication-"+publication);
	}
	
	
	public static void addBookObj(ArrayList<Book> al)
	{
		Book b1 = new Book("Let us C",350,"YK",1111,"tech");
		Book b2 = new Book("OOPS",250,"AB",2222,"knowit");
		Book b3 = new Book("JAVA",450,"JV",3333,"india");
		Book b4 = new Book("DBT",240,"AV",4444,"tata");
		Book b5 = new Book("OS",299,"BB",5555,"milan");
		
		al.add(b1);
		al.add(b2);
		al.add(b3);
		al.add(b4);
		al.add(b5);
	}
	
	public void mapBookObj()
	{
        HashMap<Integer, Object> m = new HashMap<>();
		
		m.put(1, al.b1);
		m.put(2, "DBDA BLR");
		m.put(3, "DAC PUNE");
		m.put(4, "DBDA PUNE");
		m.put(5, "DAC NOIDA");
		
		
		System.out.println(m);
	}
	
	public static void dispBookObj(ArrayList<Book> al)

	{
		for(Book obj :al)
		{	
			obj.disp();
		}
	}
	  
	public int getprice() 
    {
	    return price;
	}
	  
	public String getname()
	{
		return name;
	}
}
