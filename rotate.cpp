#include <cstdio>
#include <cstdlib>
#include <cassert>

void swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
}

void rotate(int arr[], int n, int len)
{
    assert(len != 0);    
    n = n % len;
    int temp = arr[0], count = 0, i = n, prev = 0;
    
    while (count < len)
    {
       swap(temp, arr[i]);
       count++;
       if (i == prev)
       {
           i++;
           prev = i;
           temp = arr[i];
       }
       i = (i + n) % len;
    }
}

int main(int argc, char ** argv)
{
    int arr[argc - 2], n = atoi(argv[1]);
    for (int i = 0; i < argc - 2; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }
    
    rotate(arr, n, argc - 2);
    for (int i = 0; i < argc - 2; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
} 
