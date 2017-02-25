#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string a, int i, string b, int j)
{
   if (j == b.length()) return true;
   else if (i == a.length()) return false;
   else if (a[i] == b[j]) return check(a, i+1, b, j+1);
   else if (a[i] < b[j]) return check(a, i+1, b, j);
   else return false;
}   

int main()
{
   string a, b;
   cin >> a >> b;
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   cout << check(a, 0, b, 0) << endl;
   return 0;
}
   
