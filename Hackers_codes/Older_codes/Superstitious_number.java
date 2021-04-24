/*
superstitious number-
true if-
1)in number if 8 is not followed by 9 and
2)if there is 9 in number, it should be divisible by 3 but not by 6
*/

import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		Boolean isSuperStitious=false;
		int n;
		n=sc.nextInt();
		long[] arr =new long[n];
		long num;
		for(int i=0; i<n; i++) {
		//System.out.println("Input number: ");
		num=sc.nextLong();
		//System.out.println(num);
		arr[i]=num;
		}
		

		for (int i = 0; i < arr.length; i++) {
			String s="";
			//char c;
			s=String.valueOf(arr[i]);
			//System.out.println(s);
			for(int j=0; j<s.length(); j++)
			{
				if(j+1 < s.length() && s.charAt(j)=='8' && s.charAt(j+1)!='9')
				{
					isSuperStitious=true;
				}
				
				for(int m=0; m<s.length(); m++)
				{
				if(s.charAt(j)=='9')
				{
					if(arr[i]%3==0 && arr[i]%6!=0)
					{
						isSuperStitious=true;
					}
				}
				}
			}
			
			System.out.println("number: "+arr[i]);
			System.out.println("Is superstitious: "+isSuperStitious);
		}
		
	}

}

/*
input-
2
795
798

output-
number: 795
Is superstitious: true
number: 798
Is superstitious: false
*/
