//problem statement
//Java currency formatter
/*
On the first line, print US: u where u is payment formatted for US currency.
On the second line, print India: i where i is payment formatted for Indian currency.
On the third line, print China: c where c is payment formatted for Chinese currency.
On the fourth line, print France: f, where f is payment formatted for French currency.

Sample Input

12324.134

Sample Output

US: $12,324.13
India: Rs.12,324.13
China: ￥12,324.13
France: 12 324,13 €

*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();

        // Write your code here.
        
        NumberFormat localPayment; 
        
        localPayment = NumberFormat.getCurrencyInstance(Locale.US);
        System.out.println("US: " + localPayment.format(payment));  
               
        localPayment = NumberFormat.getCurrencyInstance(new Locale("en", "in"));
        System.out.println("India: " + localPayment.format(payment));
        
        localPayment = NumberFormat.getCurrencyInstance(Locale.CHINA);
        System.out.println("China: " + localPayment.format(payment));
        
        localPayment = NumberFormat.getCurrencyInstance(Locale.FRANCE);
        System.out.println("France: " + localPayment.format(payment));
    }
}