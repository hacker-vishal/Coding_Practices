/*
2D array is given, find max value out of possible hourglasses there.

Hourglass' shape-> 
a b c
  d
e f g

Sample Input

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0

Sample Output

19

Explanation

Given array contains the following hourglasses:

1 1 1   1 1 0   1 0 0   0 0 0
  1       0       0       0
1 1 1   1 1 0   1 0 0   0 0 0

0 1 0   1 0 0   0 0 0   0 0 0
  1       1       0       0
0 0 2   0 2 4   2 4 4   4 4 0

1 1 1   1 1 0   1 0 0   0 0 0
  0       2       4       4
0 0 0   0 0 2   0 2 0   2 0 0

0 0 2   0 2 4   2 4 4   4 4 0
  0       0       2       0
0 0 1   0 1 2   1 2 4   2 4 0

The hourglass with the maximum sum (19) is:

2 4 4
  2
1 2 4
*/


//solution

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int hourglassSum(vector<vector<int>> ar)
{
    int sum=0;
    int hgrow = 3;
    int hgcol = 3;
    int hourglass[hgrow][hgcol];
    int count=0;
    int ctr=0;
    int x=-1; 
    int y=-1;
        
    for(int m=0; m<4; m++)
    {   x++; 
        y=-1;
        
        for(int n=0; n<4; n++)
        {   
            y++;
            for(int i=m; i<m+3; i++)
            {
                for(int j=n; j<n+3; j++)
                {   
                    //cout << i << " " << j << " " << x << " " << y << endl;
                    hourglass[i-x][j-y]= ar[i][j];  
                }
            }
              
            for(int i=0;i<hgrow;i++)
            {
                for(int j=0;j<hgcol;j++)
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

int main()
{

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }
    
    int result = hourglassSum(arr);
        
    cout << result << endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
