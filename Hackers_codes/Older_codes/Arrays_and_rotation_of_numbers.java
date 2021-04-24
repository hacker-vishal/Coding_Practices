//Arrays and rotation

import java.util.Scanner;
class TestClass {
    public static void main(String args[] ) throws Exception {
        /* Sample code to perform I/O:
         * Use either of these methods for input

        //BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();                // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        //Scanner
        Scanner s = new Scanner(System.in);
        String name = s.nextLine();                 // Reading input from STDIN
        System.out.println("Hi, " + name + ".");    // Writing output to STDOUT

        */

        // Write your code here

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        int N=0,K=0;
        for(int k=0; k<T; k++)
        {
             N = sc.nextInt();
             K = sc.nextInt();
        
        int[] A = new int[N];

        for(int i=0; i<N;i++)
        {
            A[i]= sc.nextInt();
           // System.out.print(A[i]+ " ");
        }

        if(N<K)
        {
            K=K%N;
        
       //int[] rev = new int[5];
       for(int i=0;i<K;i++)
       {
           int last = A[N-1];
           for(int j=N-1;j>0;j--)
           {
               A[j]=A[j-1];
           }
           A[0]=last;
       }}
       else if(K>N/2)
       {
           K=N-K;

           for(int i=0;i<K;i++)
       {
           int first = A[0];
           for(int j=1;j<N;j++)
           {
               A[j-1]=A[j];
           }
           A[N-1]=first;
       }
       }
       else
       {
           for(int i=0;i<K;i++)
       {
           int last = A[N-1];
           for(int j=N-1;j>0;j--)
           {
               A[j]=A[j-1];
           }
           A[0]=last;
       }
       }

       for(int i=0; i<N; i++)
       {
           System.out.print(A[i]+" ");
       }
       System.out.println();
        }
        
    }
}

/*
1-no of test case
5-size of array
2-no of right rotation
1 2 3 4 5-no in array

ans= 4 5 1 2 3
*/
