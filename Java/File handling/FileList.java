//How to get list of all file names from a folder?

import java.io.*; 

public class FileList 
{  
	public static void main(String[] args) {  
	    File f=new File("C:\\Users\\BK Vishal\\JAVA\\Day 11"); 
	    
	    File files[]=f.listFiles();  
	    
	    for(File file :files)
	    {  
	        System.out.println(file.getName()+" Can Write: "+file.canWrite()+
	        		
	        "Is Hidden: "+file.isHidden()+" Length: "+file.length()+" bytes");  
	    }  
	 
	}  
}
