/*
2D 6*6 array calculate max possible hourglass value-

failed cases

-1 -1  0 -9 -2 -2
-2 -1 -6 -8 -2 -5
-1 -1 -1 -2 -3 -4
-1 -9 -2 -4 -4 -5
-7 -3 -3 -2 -9 -9
-1 -3 -1 -2 -4 -5

-1 -1  0
   -1
-1 -1 -1

answer= -6


-1  1 -1  0  0 0
 0 -1  0  0  0 0
-1 -1 -1  0  0 0
 0 -9  2 -4 -4 0
-7  0  0 -2  0 0
 0  0 -1 -2 -4 0

answer= 0
*/


import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        int sum=0;
        //int i=0;
         int[][] hourglass=new int[3][3];
        int count=0;
        int ctr=0;
        int x=-1; int y=-1;
        
        for(int m=0; m<4; m++)
    {   x++; y=-1;
        for(int n=0; n<4; n++)
        {   y++;
        for(int i=m; i<m+3; i++)
        {
            for(int j=n; j<n+3; j++)
            { 
                hourglass[i-x][j-y]= arr[i][j];  
            }
        }
        
        // for(int i=0; i<3; i++)
        // {
        //     System.out.println(Arrays.toString(hourglass[i]));
        // }  
        // System.out.println("next");
              
        for(int i=0;i<hourglass.length;i++)
        {
            for(int j=0;j<hourglass.length;j++)
            {
                if((i==1 && j==0) || (i==1 && j==2))
                    continue;
                else
                {
                    count += hourglass[i][j];
                }
            }
        }
        
        if(count>=sum)
        {
            sum=count;
        }
        else
        if(count<0)
        {
            if(sum==0 && ctr==0)
            {
                sum=count;
                ctr++;
            }
        }
        count=0;
    }
    }   
        return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
