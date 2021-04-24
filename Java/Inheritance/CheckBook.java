
public class CheckBook 
{
	public static void main(String[] args)
	{
		Author a = new Author("Y Kanitkar","yk@gmail.com",'M');
		System.out.println("==========================================");
		
		Book b = new Book("let us c",1,400,a);
		b.showbook();
		b.bookprice(4);
	}
}
