#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string decode(string s, string map)
{
   string code;
   for (int i = 0; i < s.size(); i++)
   {
       if (s[i] == ' ') code += ' ';
       else code += map[s[i] - 'A'];
   }
   return code;
}

int main()
{
   int N;
   cin >> N;
   for (int i = 1; i <= N; i++)
   {
       string s, map;
       getline(cin, s);
       getline(cin, s);
       getline(cin, map);
       cout << decode(s, map) << endl;
   }
   
   return 0;
}
