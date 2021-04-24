using System;

	class SineDegRad
	{
		
		static void Main(string[] args)
		{
			
			int num;
			int n;
			Console.WriteLine("Enter the number of terms:");
			n = int.Parse(Console.ReadLine());
			Console.WriteLine("Enter the Angle in degrees:");
			num= int.Parse(Console.ReadLine());
			
			float x, sum=0.0f, term;
			x=(float)Math.PI*num/180f;
			sum=x;
			term=x;
			for(int i=1; i<=n; i++)
			{
				
				term = (-term*x*x)/((2*i)*(2*i+1));
				sum = sum+term;
				
			}
			Console.WriteLine("Sin({0})={1}",num,sum);
			
		}
		
	}
	
