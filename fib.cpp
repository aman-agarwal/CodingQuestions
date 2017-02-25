#include <cstdio>
#include <cstdlib>

int fib(int n)
{
    int a = 0, b = 1, temp;
    while (n > 1) 
    {
        temp = b;
        b += a;
        a = temp;
        n--;
    }
    return b;
}     

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        int n = atoi(argv[1]);
        int m = fib(n);
        printf("%d \n", m);
    } 
    else
    {
        fprintf(stderr, "wrong input\n");
    }
  
    return 0;
}
