//problem statement

/*
Simple Max Difference

In securities research, an analyst will look at a number of attributes for a stock. One analyst would like to keep a record of the highest positive spread between a closing price and the closing price on any prior day in history. Determine the maximum positive spread for a stock given its price history. If the stock remains flat or declines for the full period, return -1.

Example 0

px = [7, 1, 2, 5]

Calculate the positive difference between each price and its predecessors:

• At the first quote, there is no earlier quote to compare to.

• At the second quote, there was no earlier price that was lower.

• At the third quote, the price is higher than the second quote:

• 2-1=1

. For the fourth quote, the price is higher than the

third and the second quotes:

a 5-2=3

o 5-1 4

• The maximum difference is 4.
*/

//solution-

import java.util.*;

public class Main
{
	public static void main(String[] args) {
		//System.out.println("Hello World");
		
		Scanner sc = new Scanner(System.in);
		
		//int n = sc.nextInt();
		
		List<Integer> l = new ArrayList<Integer>();
		
		l.add(7);
		l.add(5);
		l.add(3);
		l.add(2);
// 		l.add(4);
// 		l.add(8);
// 		l.add(1);
		
		int ans = 0;
		
		ans = Main.maxDifference(l);
		
		System.out.println("maxDifference is "+ans);
	}
	
	public static int maxDifference(List<Integer> l)
	{
	    int maxdiff=-1;
	    int temp=0;
	    
	    if(l.size()==1)
	        return maxdiff;
	        
	   int arr[] = new int[l.size()];
	   
	   for (int i =0; i < l.size(); i++)
            arr[i] = l.get(i);
	    
	    for(int i=1; i<arr.length; i++)
	    {
	        for(int j=0; j<i; j++)
	        {
	            if(arr[j]>arr[i])
	                continue;
	            else
	                temp=arr[i]-arr[j];
	                
	            if(temp>maxdiff)
	                maxdiff=temp;
	        }
	    }
	    
	    return maxdiff;
	}
}