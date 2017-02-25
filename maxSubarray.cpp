#include <iostream>
#include <cstdlib>

using namespace std;

void maxSubarray(int arr[], int n)
{
     int i, max = arr[0], curr = arr[0];
     int m1 = 0, m2 = 0, c1 = 0, c2 = 0;
     for(i = 1; i < n; i++)
     { 
         if (curr > 0)
         {
             curr += arr[i];
         }
         else
         {
             curr = arr[i];
             c1 = i;
         }
         if (curr > max)
         {
             m1 = c1;  
             m2 = i;
             max = curr;
         }
     } 

     for(i = m1; i <= m2; i++)
     {
         cout << arr[i] << " ";
     }
     cout << endl;
}

int main(int argc, char ** argv)
{
     int arr[argc -1];
     int i; 
     for(i = 0; i < argc - 1; i++)
     {
         arr[i] = atoi(argv[i+1]);
     }
     
     maxSubarray(arr, argc - 1);
     return 0;
}



