#include <iostream>
#include <algorithm>

using namespace std;

int knockOver(int arr[], int N)
{
   int max = -1, temp;
   int aux[N];
   for (int i = 0; i < N; i++)
   {
       if (i == 0) aux[i] = arr[i] == 0;
       else aux[i] = aux[i-1] + (arr[i] == 0);
   }
         
   for (int i = N-1; i >= 0; i--)
   {
      temp = min(i + arr[i], N-1);
      for (int j = i+1; j <= min(i + arr[i], N-1); j++)
      {
          if (arr[j] > temp) temp = arr[j];
      }
      arr[i] = temp;
      if (i) temp = temp - i + 1 - (aux[temp] - aux[i-1]);
      else temp = temp - i + 1 - aux[temp];

      if (temp > max) max = temp;
   }
   return max;
}

int main()
{
   int N;
   cin >> N;
   int arr[N];
   for (int i = 0; i < N; i++) cin >> arr[i];
   cout << knockOver(arr, N) << endl;
   return 0;
}
