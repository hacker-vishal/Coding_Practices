//problem statement
//Java string introduction
/*
There are three lines of output:
For the first line, sum the lengths of  and .
For the second line, write Yes if  is lexicographically greater than  otherwise print No instead.
For the third line, capitalize the first letter in both  and  and print them on a single line, separated by a space.

Sample Input 0

hello
java

Sample Output 0

9
No
Hello Java

*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        
        System.out.println(A.length() + B.length());
        
        char[] first = A.toLowerCase().toCharArray();
        char[] second = B.toLowerCase().toCharArray();
        
        String lexicographicOrNot = "Yes";
        if(Integer.valueOf(first[0]) <= Integer.valueOf(second[0]))
            lexicographicOrNot = "No";
        
        System.out.println(lexicographicOrNot);
        
        System.out.println(A.substring(0, 1).toUpperCase()+A.substring(1) + " " +
            B.substring(0, 1).toUpperCase()+B.substring(1));
        
    }
}