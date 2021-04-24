//Monk and Inversion-

import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Write your code here
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        
        for(int i=0; i<T;i++)
        {
            int pair=0;

            int N = s.nextInt();
            int[][] M = new int[N][N];
            
            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    M[j][k]=s.nextInt();
                }
                //System.out.println();
            }

            for(int j=0;j<N;j++)
            {
                for(int k=0;k<N;k++)
                {
                    for(int p=0;p<N;p++)
                    {
                        for(int q=0;q<N;q++)
                        {
                            if(j<=p && k<=q && M[j][k]>M[p][q])
                            {
                                pair++;
                            }
                        }
                    } 
                }
            }
            System.out.println(pair);
        }
    }
}

/*
Input 
2
3
1 2 3
4 5 6
7 8 9
2
4 3
1 4

4>3 and 3>1 are the only cases where condition satisfies 

Output 
0
2
*/