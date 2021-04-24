//2. counting valleys

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'countingValleys' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER steps
     *  2. STRING path
     */

    public static int countingValleys(int steps, String path) {
    // Write your code here
    // 8
    // UDDDUDUU
    
    int sea=0;
    int pos=0;
    int valley=0;
    
    char[] hike = path.toCharArray();
    
    for(int i=0; i<steps; i++)
    {
        if(hike[i]=='U')     //udddu
        sea++;
        else //if(hike[i]=='D') 
        sea--;
        // if(sea==-1)
        // {
        //     valley++;
        // }
        
        if(sea<0)
        {
            if(pos==0)
            {
                valley+=1;
                pos--;
            } 
            else if(sea<pos)
            {
                pos--; 
            }
            else
            {
                pos++;
            }
        }
        else
        { 
            if(sea>pos)
            {
                pos++;
            }
            else
            {
                pos--;
            } 
        }
    
        
    }
        return valley;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int steps = Integer.parseInt(bufferedReader.readLine().trim());

        String path = bufferedReader.readLine();

        int result = Result.countingValleys(steps, path);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}

/*
Input- UDDDUDUU (8 steps, U-uphill, D-downhill)

Output- 1 (valley)
*/
