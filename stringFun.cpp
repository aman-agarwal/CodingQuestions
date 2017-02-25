#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

bool allUnique(string s)
{
   bool arr[256];
   memset(arr, false, 256 * sizeof(bool));
   for (int i = 0; i < s.size(); i++)
   {
       if (arr[s[i]]) return false;
       arr[s[i]] = true;
   }
   return true;
}

bool allUnique2(string s)
{
   sort(s.begin(), s.end());
   for (int i = 0; i < s.size() - 1; i++)
   {
       if (s[i] == s[i+1]) return false;
   }
   return true;
}

void removeDups(string & s)
{
   bool arr[256];
   memset(arr, false, 256 * sizeof(bool));
   int j = 0;
   for (int i = 0; i < s.size(); i++)
   {
       if (!arr[s[i]])
       {
           arr[s[i]] = true;
           s[j++] = s[i];      
       }
   }
   s.erase(j, string::npos);
}  

/* Cleaner with buffer string. */
void replaceSpaces(string & s)
{
   int count = 0;
   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == ' ') count++;
   }
   int len = s.size();
   s.resize(s.size() + 2 * count);
   int k = s.size() - 1;
   for (int j = len-1; j >= 0; j--)
   {
       if (s[j] == ' ') 
       { 
           s[k--] = '0'; s[k--] = '2'; s[k--] = '%';
       }
       else
       {
           s[k--] = s[j];
       }
   }       
}

int main()
{
   string s;
 /*  cin >> s;
   cout << allUnique(s) << endl;
   cout << allUnique2(s) << endl;
   removeDups(s);
   cout << s << endl; 
   */
   getline(cin, s);
   replaceSpaces(s);   
   cout << s << endl;
   return 0;
}
