/*Write a program to serialize the student object ( no,name,marks) 
Write a student object into the file and read the same from the file, 
and find result.*/

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class FileStudent implements Serializable
{
	    private static final long serialVersionUID = 1L;
	    
		int no;
		String name;
		float marks;
		   
		public FileStudent(int id, String name,float mk) 
		{
			this.no = id;
			this.name = name;
			this.marks = mk;
		}


	  
		void disp()
		{
			System.out.println(no + " "+name+ " "+marks);
			
		}
//		public String toString() {
//			return "Person [id=" + id + ", name=" + name + "]";
//		}

		public static void main(String[] args) throws IOException,ClassNotFoundException ,EOFException
		{
			FilePerson p1 = new FilePerson(1001,"shan",50);
			
			FileOutputStream fos = new FileOutputStream("studentfile.txt");
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			
			oos.writeObject(p1);
			
			fos.close();
			oos.close();
			
			System.out.println("object write is over");
			
			FileInputStream fis = new FileInputStream("studentfile.txt");
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