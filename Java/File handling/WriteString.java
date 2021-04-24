/*How to write string content to a file and how to read file content 
line by line?*/

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class WriteString 
{
	public static void main(String[] args) throws IOException 
	{
			FileWriter fw = new FileWriter("file.txt");
			
			InputStreamReader ir = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(ir);
			System.out.println("enter the string to write to the file");
			String str; 
			
			while(!(str = br.readLine()).equals("exit"))
			{
				
				fw.write(str + "\n");
			}
			
			fw.close();
			
			System.out.println("file is written");
			
			FileReader fr = new FileReader("file.txt");
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
