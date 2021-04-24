//3. Jumping On clouds problem


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the jumpingOnClouds function below.
    static int jumpingOnClouds(int[] c) {
        
        int jump=0;
        
        for(int i=0; i<c.length; i++)
        {
            if(c[i]==0)
            {
                if(i<c.length-2 && c[i+2]==0)
                {
                    jump++;
                    i=i+1;
                }
                else if(i<c.length-1 && c[i+1]==0)
                {
                    jump++;
                }  
            }
        }

        return jump;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] c = new int[n];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int result = jumpingOnClouds(c);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

/*
Input - 0010010 (cannot jump on 1, from 0 can jump to next or next+1)
Output - 4 (minimum 4 jumps) 
*/
