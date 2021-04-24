/*Program to count the number of character ,no of word, 
no of lines in a given file.*/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CountFile 
{
	public static void main(String[] args) throws IOException,FileNotFoundException 
	{
		File f =new File("C:\\Users\\BK Vishal\\JAVA\\Day 11\\dac.txt");
		
		FileReader fr = new FileReader(f);
		BufferedReader br = new BufferedReader(fr);
		
		int charCount=0;
		int wordCount=0;
		int lineCount=0;
		
		String line=br.readLine();
		
		while(line != null)
		{
			lineCount++;
			
			String[] words = line.split(" ");
			wordCount+=words.length;
			
			for(String word: words)
			{
				charCount+=word.length();
			}
			
			line=br.readLine();
		}
		
		System.out.println("no of char "+charCount);
		System.out.println("no of word "+wordCount);
		System.out.println("no of lines "+lineCount);
		
		fr.close();
		br.close();
	}
}
