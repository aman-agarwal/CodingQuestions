#include <iostream>
using namespace std;

void spiralMatrix(int ** arr, int m, int n)
{
   int count = 0, i = 0;
   while (count < m * n)
   {
       for (int j = i; j < n - i; j++)
       {
            cout << arr[i][j] << " ";
            count++;
       }
       for (int j = i+1; j < m - i; j++)
       {
            cout << arr[j][n-i-1] << " ";
            count++;
       }
       if (i != m - i -1)
       {
           for (int j = n - i - 2; j >= i; j--)
           {
               cout << arr[m-i-1][j] << " ";
               count++;
           }
       }
       if (i != n - i - 1)
       {
           for (int j = m - i - 2; j > i; j--)
           {
               cout << arr[j][i] << " ";
               count++;
           }
       }  
       i++;
   }
   cout << endl;
}

int main()
{
   int m, n;
   cin >> m;
   cin >> n;
   int ** arr = new int * [m];
   for (int i = 0; i < m; i++) arr[i] = new int[n];

   for (int i = 0; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
           cin >> arr[i][j];
       }
   }

   spiralMatrix(arr, m, n);
   return 0;
}

