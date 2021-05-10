#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
   // cout<<"Hello World";
   list <int> l;
   
   l.push_back(4);
   l.push_back(3);
   l.push_back(1);
   l.push_back(2);
   
//   test if list has element added
//   for(int c : l)
//   cout << c << " ";

// convert list into vector
   vector<int> a;
   for(int c : l)
   a.push_back(c);
   
   
//   check if vector has element added
//   for(int c : v)
//   cout << c << " ";

// manipulate vector to get the result
   int total = 0;
   int n = a.size();
    
    for (int i = 0; i < n; i++) {
    // Track number of elements swapped during a single array traversal
    int numswap = 0;
    
    for (int j = 0; j < n - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            numswap++;
        }
    }
    
    // If no elements were swapped during a traversal, array is sorted
    if (numswap == 0)
        break;
    else
        total += numswap;
    }
    
//  print the result
    cout<<"Array is sorted in "<< total <<" swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[n-1];

    return 0;
}