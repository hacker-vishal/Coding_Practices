/*Write a Java program to create a class called player with name, 
age, country Name, total run as instance member.    Create 5 player
objects and write  instance method to display the details of Player 
having more than 5000 as total run*/

public class Player {
	String name;
	int age;
	String country;
	int run;

	Player(String name, int age, String country, int run) {
		this.name = name;
		this.age = age;
		this.country = country;
		this.run = run;
	}

	private void getPlayer() {

	}

	void checkPlayer(int run) {
		if (run > 5000)
			getPlayer();
	}
}

/*
 * import java.util.Scanner;
 * 
 * public class Player { String pName; int pAge; String pCountry; int runs;
 * Player(String pName,int pAge,String pCountry,int runs){ this.pName=pName;
 * this.pAge=pAge; this.pCountry=pCountry; this.runs=runs; } static void
 * display(Player p[]) { System.out.println("Players who scored more than:");
 * for(int i=0;i<p.length;i++) { if(p[i].runs>5000) {
 * System.out.println(p[i].pName +"  "+p[i].pCountry); } } } public static void
 * main(String[] args) {
 * 
 * Player p[]=new Player[2]; p[0]=new Player("Sachin",42,"India",22500);
 * p[1]=new Player("Ponting",39,"Aus",12300); System.out.println(p[0].runs);
 * 
 * 
 * 
 * System.out.println("Enter the no. of players you want to include :"); Scanner
 * s = new Scanner(System.in); int size=s.nextInt(); Player p[]=new
 * Player[size]; for(int i=0;i<p.length;i++) {
 * System.out.println("Enter Player Details :");
 * System.out.println("Player Name :"); String name=s.next();
 * System.out.println("Player Age :"); int age=s.nextInt();
 * System.out.println("Player Country :"); String con=s.next();
 * System.out.println("Runs Scored :"); int runs=s.nextInt(); p[i]=new
 * Player(name,age,con,runs); }
 * 
 * display(p);
 * 
 * for(int i=0;i<p.length;i++) { if(p[i].runs>=10000) {
 * System.out.println("Player Name :"+p[i].pName+"\n"+
 * "Player Age : "+p[i].pAge+"\n"+ "Nationality : "+p[i].pCountry); } }
 * 
 * s.close(); }
 * 
 * }
 */