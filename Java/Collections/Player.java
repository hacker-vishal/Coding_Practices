import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.List;

/*1) Write a Java program to perform the following operations-using Array List 
       Create a class called Player with the following instance variable 

Player name 
total run 
no of wicket 
no of matches 
country 
no-of-century 
Category = null 

* Create 5 Players using array of objects and add into the Array List 
* Display the player details who has scored maximum no of runs 
* Sort the players by name 
* Remove the player who has scored less than 100 runs and played more than 3 matches. 
* Update Category ‘A’ if player has got 10 century else update Grade ‘ B’ 
*/

public class Player extends Object
{
	String name;
	int run;
	int wkts;
	int matches;
	String country;
	int cent;
	String cat=null;
	
	public Player(String name,int run,int wkts,int matches,String country,int cent,String cat)
	{
		super();
		this.name = name;
		this.run = run;
		this.wkts = wkts;
		this.matches = matches;
		this.country = country;
		this.cent = cent;
		this.cat = cat;
	}
	
	public String toString()
	{
		return "Player [name="+name+",run="+run+",wkts="+wkts+",matches="+matches+",country="+country+",cent="+cent+",cat="+cat+"]";	
	}

	void disp()
	{
		System.out.println(name+" runs-"+run+" wickets-"+wkts+" matches-"+matches+" country-"+country+" centuries-"+cent+" category-"+cat);
	}
	
	
	public static void addPlayerObj(ArrayList<Player> al)
	{
		Player p1 = new Player("Sachin",35000,40,400,"India",100,"AR");
		Player p2 = new Player("Akash",80,0,4,"India",0,"BT");
		Player p3 = new Player("Dhoni",18000,2,300,"India",20,"WB");
		Player p4 = new Player("Virat",24000,4,290,"India",70,"B");
		Player p5 = new Player("Hardik",6000,40,150,"India",5,"AR");
		
		al.add(p1);
		al.add(p2);
		al.add(p3);
		al.add(p4);
		al.add(p5);
	}
	
	
	public static void dispPlayerObj(ArrayList<Player> al)

	{
		for(Player obj :al)
		{	
			obj.disp();
		}
	}
	
	public static void getplayernamesorted(ArrayList<Player> al) 
	  { 
		  al.sort(Comparator.comparing(Player::getname)); 
		  
		  for(Player obj:al)
			  System.out.println("Player name-"+obj.name);
	  }
	  
	  
	  public static void getplayerwithmaxrun(ArrayList<Player> al) 
	  {
		  Player play = Collections.max(al,Comparator.comparing(s -> s.getrun()));
		  System.out.println("details of player with max runs- "+play.run+" is "+"name-"+play.name+" country-"+play.country+" matches-"+play.matches+" runs-"+play.run+" wkts-"+play.wkts+" cat-"+play.cat);
	  }
	  
	  public static void removePlayer(ArrayList<Player> al)
	  {
		  int pos =0;
		  for(Player obj :al)
			{
				if(obj.run< 100 && obj.matches>3)
				{
					pos = al.indexOf(obj);
				}
			}
		  
		  al.remove(pos);
		  System.out.println("given id object is removed");
	  }
	  
	  public static void updateCateg(ArrayList<Player> al)
	  {
		  for(Player obj :al)
			{
				if(obj.cent >= 10)
					obj.cat = "A";
				else
					obj.cat = "B";
			}
	  }
	  
	  public int getrun() 
	  {
		 return run;
	  }
	  
	  public String getname()
	  {
		  return name;
	  }
	
	
	public static void main(String[] args) 
	{
		ArrayList<Player> al = new ArrayList<>();
		
		addPlayerObj(al);
		dispPlayerObj(al);
		System.out.println("======================================================================================");
		
		getplayernamesorted(al);
		System.out.println("======================================================================================");
	
		getplayerwithmaxrun(al);
		System.out.println("======================================================================================");
		
		removePlayer(al);
		System.out.println("======================================================================================");
		dispPlayerObj(al);
		System.out.println("======================================================================================");
		
		updateCateg(al);
		dispPlayerObj(al);
		System.out.println("======================================================================================");
	}
}


