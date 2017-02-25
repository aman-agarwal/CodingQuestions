#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void helper(int arr[], string & p)
{
    bool end = true;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i])
        {
            arr[i]--;
            p += ('a' + i);
            helper(arr, p);
            p.erase(p.end() - 1);
            arr[i]++;
            end = false;
        }
    }
    if (end) cout << p << endl;  
}

void printDistinctPerms(string s)
{
   int arr[26];
   memset(arr, 0, sizeof(int) * 26);
   for (int i = 0; i < s.length(); i++) arr[s[i] - 'a']++;
  
   string p;
   helper(arr, p);
}

int main() {
  string s;
  cin >> s;
  printDistinctPerms(s);
  return 0;
}
