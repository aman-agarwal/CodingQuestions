#include <cstdio>
#include <iostream>
#include <string>

using namespace std; 

bool find(string s, string sub)
{
   int i, j, k;
   for(i = 0; i < s.length() - sub.length() + 1; i++)
   {
       for(j = 0; j < sub.length(); j++)
       {
           if(s[i + j] != sub[j]) break;
       }   
       if (j == sub.length()) return true;
   }
   return false;
}

int main()
{
   string s, sub; 
   cout << "Enter string" << endl;
   getline(cin, s); 
   cout << "Enter substring" << endl;
   getline(cin, sub);
   cout << find(s, sub) << endl;
   return 0;
}
   
   
