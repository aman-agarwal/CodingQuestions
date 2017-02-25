#include <iostream>
#include <algorithm>

using namespace std;

void rotate(int ** arr, int N)
{
   int temp;
   for (int i = 0; i < N/2; i++)
   {
       for (int j = i; j < N - i - 1; j++)
       {
           temp = arr[i][j];
           swap(temp, arr[N-j-1][i]);
           swap(temp, arr[N-i-1][N-j-1]);
           swap(temp, arr[j][N-i-1]);
           arr[i][j] = temp;
       }
   }
}

int main()
{
   int N; 
   cin >> N;
   int ** arr = new int * [N];
   for (int i = 0; i < N; i++) arr[i] = new int[N];
   
   for (int i = 0; i < N; i++)
   {
       for (int j = 0; j < N; j++)
       {
           cin >> arr[i][j];
       }
   }
   rotate(arr, N);
   cout << endl;
   for (int i = 0; i < N; i++)
   {
       for (int j = 0; j < N; j++)
       {
           cout << arr[i][j] << " ";
       }
       cout << endl;
   }
   
   for (int i = 0; i < N; i++) delete[] arr[i];
   delete[] arr;  
   return 0;
}
