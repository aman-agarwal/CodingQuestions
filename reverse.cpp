#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

/*
void reverse(char * s)
{
    int i, len = 0;
    char c; 
    for (i = 0; s[i] != '\0'; i++) len++;
    for (i = 0; i < len/2; i++)
    {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }  
}*/

void reverse(string & s)
{
    char c;
    int len = s.length();
    for(int i = 0; i < len/2;  i++)
    {
        c = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = c;
    }
}

int main(int argc, char ** argv)
{
   // char * s;
    string s;
    if (argc == 2)
    {
        s = argv[1];
    //    printf("%p %p\n", s, argv[1]);

        reverse(s);
        printf("%s \n", s.c_str());
    }
    else
    {
        fprintf(stderr, "Wrong input");
    }

    return 0;
} 
