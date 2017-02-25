#include <cstdio>
#include <cstdlib>

bool bsearch(int arr[], int n, int len)
{
     int l = 0, h = len - 1;
     int mid;
     while (l <= h)
     {
         mid = (l + h)/2;
         if (arr[mid] == n)
         {
             return true;
         }
         else if (arr[mid] < n)
         {
             l = mid + 1;
         }
         else
         {
             h = mid - 1;
         }
     }
     return false;
}


int main(int argc, char ** argv)
{
     int i, arr[argc-2];
     for(i = 1; i < argc - 1; i++)
     {
         arr[i-1] = atoi(argv[i]);
     }
        
     int n = atoi(argv[argc-1]);
     if (bsearch(arr, n, argc - 2))
     {
         printf("Found\n");
     }
     else
     {
         printf("Not found\n");
     }
     
     return 0;
} 
