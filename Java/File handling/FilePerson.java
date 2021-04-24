/*Write a program to store person details(no,name,sal) into a file and  
read and display file content(person detail) on console?*/

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class FilePerson implements Serializable
{
	    private static final long serialVersionUID = 1L;
	    
		int no;
		String name;
		float sal;
		   
		public FilePerson(int id, String name,float sal) 
		{
			this.no = id;
			this.name = name;
			this.sal = sal;
		}


	  
		void disp()
		{
			System.out.println(no + " "+name+ " "+sal);
			
		}
//		public String toString() {
//			return "Person [id=" + id + ", name=" + name + "]";
//		}

		public static void main(String[] args) throws IOException,ClassNotFoundException ,EOFException
		{
			FilePerson p1 = new FilePerson(1001,"shan",2000);
			
			FileOutputStream fos = new FileOutputStream("personfile.txt");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			
			oos.writeObject(p1);
			
			fos.close();
			oos.close();
			
			System.out.println("object write is over");
			
			FileInputStream fis = new FileInputStream("personfile.txt");
			ObjectInputStream ois = new ObjectInputStream(fis);
			
			FilePerson obj;
			try
			{
			while((obj = (FilePerson) ois.readObject())!=null)
			{
				obj.disp();
				
			}
			}catch(EOFException e)
			{
				System.out.println("end of file reached");
			}
		}

}