/*

Convert given decimal int to binary and find max no of consecutive 1's in it.

Sample Input 1
5

**binary of 5 is 101

Sample Output 1
1

Sample Input 2
13

**binary of 13 is 1101

Sample Output 2
2

*/

//Solutions

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string convertToBin(int n)
{
    int rem = 0;
    
    int quot = -1;
    
    string strbin = "";
    
    while (quot != 0) 
    {
        quot = n/2;
        
        rem = n % 2;
        
        strbin += to_string(rem);
        
        n = quot;
    }
    
    reverse(strbin.begin(), strbin.end());
    
    // Convert string to int using stringstream
    
    // stringstream getStrbinToInt(strbin);
    
    // getStrbinToInt >> n;
    
    // return n;
    
    return strbin;
}

int countMaxConsecutiveOnes(string str)
{
    // Convert int to string using ostrinstream
    
    // ostringstream ostr;
    
    // ostr << n;
    
    // string str = ostr.str();
    
    /*
    string str = to_string(n);
    */
    
    int l = str.length();
    
    // int n = 1;
    
    // for(int i = 0; i < l; i++)
    // {
    //     if(str[i] == '0')
    //     {
    //         n++;
    //     }
    // }
    
    int count = 0;
    
    //int arr[n];
    
    //int index = 0;
    int max = 0;
    for(int i = 0; i < l-1; i++)
    {
        if(str[i] == '1' && str[i+1] == '1')
        {
            count++;
            
            if(max < count)
                max = count;
        }
        else
        {
            //arr[index] = count;
            count = 0;
            //index++;
        }
    }
    
    //arr[index] = count;
    
    return max + 1;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string bin = convertToBin(n);
    
    int ans = countMaxConsecutiveOnes(bin);
    
    cout << ans;
    
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
