/*
4.  some string repeated infinitely, some length will be given upto which we have to 
    consider the string, find occurences of particular letter in that string
*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the repeatedString function below.
    static long repeatedString(String s, long n) {

        long len = s.length();
        //System.out.println(len);
        long quot=0;
        long rem=0;
        long occur=0;
        char[] ch = s.toCharArray();
        
        for(char c: ch)
        {
            if(c == 'a')
            occur++;
        }
        
        quot = n/len;
        
        rem = n%len;
        
        // if(ch[0]=='a')
        // {
        //     quot = n/len;
            
        //     rem = n%len;
        
        //     return occur*quot+rem;
        // }
         
        //StringBuilder b = new StringBuilder();
            
        
        if(rem!=0)
        {
            int extra=0;
            char[] d = new char[(int)rem];
            
        for(int i=0; i<rem; i++)
        {      
            //b.append(ch[i]);
            d[i]=ch[i];
        }
                
            //char[] d = b.toString().toCharArray();
                
            for(char c: d)
            {
                if(c == 'a')
                extra++;
            }
            return occur*quot+extra;
        }
        else
            return occur*quot;
        
    //return 0;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        long n = scanner.nextLong();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        long result = repeatedString(s, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

/*
input- aba  string repeated infinitely
       10   length upto which we have to consider the string

output- 7  occurences of a
*/
