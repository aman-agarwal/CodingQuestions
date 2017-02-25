#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int len;
    char str[] = "abcdef";
    cout << strlen(str) << endl; 
    for(len = 0; str[len] != '\0'; len++);
    cout << len << endl; 
    
    return 0;
}
