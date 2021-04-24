/*Read source and destination file from the user as an argument. 
Copy the contents of the source into another destination file in a 
faster, efficient way.*/ 

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class CopyFile 
{
	public static void main(String[] args) throws IOException,FileNotFoundException 
	{
		String source=null;
		String dest=null;
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("enter source file name");
		source=s.next();
		FileInputStream fis = new FileInputStream(source);
		
		System.out.println("enter dest file name");
		dest=s.next();
		FileOutputStream fos = new FileOutputStream(dest);
		
		int b;
		
		while((b=fis.read())!=-1)
			fos.write(b);
		
		fis.close();
		fos.close();
		
		FileReader fr = new FileReader(dest);
		BufferedReader br1 = new BufferedReader(fr);
		
		String str1=null; 
		
		while((str1 = br1.readLine()) != null)
		{
			
			System.out.println(str1);
		}
		
	fr.close();
	br1.close();
	}
}
