#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char ** argv)
{
    int n;
    cout << "Enter whole number" << endl;
    cin >> n;
    string s; 
    while(n)
    { 
       if (n & 1) 
       {
           s = "1" + s;
       }
       else
       {
           s = "0" + s;
       }
       n = n >> 1;
    }
    cout << s << endl;

    cout << endl << "Enter decimal number" << endl;
    cin >> s; 
    bool neg = false;
    if (s[0] == '-') 
    {
        neg = true;
        s.erase(0,1);
    }
    string s1, s2;
    bool dec = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')  dec = true;
        else if (dec) s2 += s[i];
        else s1 += s[i];
    }
    int a = atoi(s1.c_str()), b = atoi(s2.c_str());
    s1.erase();
    s2.erase();
    
    return 0;
}
