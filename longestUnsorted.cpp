#include <cstdio>
#include <cstdlib>

bool longestUnsorted(int * arr, int & s, int & e, int n)
{
    s = 0;
    while (s < n - 1)
    { 
       if (arr[s] <= arr[s + 1]) { s++; }
       else { break; }
    }
    
    e = n - 1;
    while (e > s)
    {
       if (arr[e] >= arr[e - 1]) { e--; }
       else { break; }
    }
    
    if (e == s)
       return false;

    int min = arr[s];
    int max = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < min) { min = arr[i]; }
        else if (arr[i] > max) { max = arr[i]; }
    }
    
    while (s > 0)
    { 
       if (arr[s - 1] > min) { s--; }
       else { break; }
    }

    while (e < n - 1)
    { 
       if (arr[e + 1] < max) { e++; }
       else { break; }
    }
    
    return true;
}



int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Wrong input\n");
    }
    else
    {
        int n = argc - 1;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = atoi(argv[i + 1]);
        }
              
       int s, e;
       if (longestUnsorted(arr, s, e, n))        
           printf("%d, %d\n", s, e);
       else
           printf("Already sorted\n");
 
    }
    return 0;
}
