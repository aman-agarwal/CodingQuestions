#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void helper(string & s, string & p, bool used[])
{
   bool end = true;
   for (int i = 0; i < s.length(); i++)
   {
       if (!used[i])
       {
           p += s[i];
           used[i] = true;
           end = false;
           helper(s, p, used);
           used[i] = false;
           p.erase(p.end() - 1);
       }
   }
   if (end) cout << p << endl;
}
          
void printPerms(string s)
{
   string p;
   bool used[s.length()];
   memset(used, false, sizeof(bool) * s.length());
   helper(s, p, used);
}

int main()
{
   string s;
   cin >> s;
   printPerms(s);
   return 0;
}
