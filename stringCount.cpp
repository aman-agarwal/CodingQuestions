#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; 
    cout << "Enter string" << endl;
    getline(cin, s);
 
    int arr[256], i;
    for (i = 0; i < 256; i++)
    {
        arr[i] = 0;
    }
    for (i = 0; i < s.length(); i++)
    {
        arr[s[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if(arr[i])
        { 
            cout << (char) i << " " << arr[i] << endl;
        } 
    }
    return 0;
}    
