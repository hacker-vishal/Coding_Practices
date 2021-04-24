//1.    calculate pair of socks  // hackerrank

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sockMerchant function below.
    static int sockMerchant(int n, int[] ar) {
        //Arrays.sort(ar);
        int ans=0;
        
        //System.out.println(Arrays.toString(ar));
        
        for(int i=0; i<n; i++)
        {
            int count=0;
            int terminator=0;
            
            int x = ar[i];
            
            for(int j=i; j<n; j++)
            {
                if(ar[j]==x)
                count++;
            }
            
            terminator+=count;
            
            if(count%2==0)
                ans+=1;
                
            if(terminator>n)
                return ans;
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] ar = new int[n];

        String[] arItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arItem = Integer.parseInt(arItems[i]);
            ar[i] = arItem;
        }

        int result = sockMerchant(n, ar);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

/*
Input- {10,20,20,10,10,30,40,10}

Output- 3 (pairs)
*/