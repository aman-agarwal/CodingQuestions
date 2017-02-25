#include <iostream>
using namespace std;

int getNumberSameIndex(int arr[], int n)
{
   int l = 0, h = n - 1;
   while (l <= h)
   {
      int mid = (l + h)/2;
      if (arr[mid] - mid == 0) return arr[mid];
      else if (arr[mid] - mid > 0) h = mid - 1;
      else l = mid + 1;
   }
   return -1;  
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << getNumberSameIndex(arr, n) << endl;             
            
  return 0;
}


