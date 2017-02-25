#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int mid, int h)
{
    int aux[h+1];
    int i = 0, j = l, k = mid + 1;
    while (j <= mid && k <= h)
    {
        aux[i++] = min(arr[j], arr[k]);
        if (arr[j] < arr[k]) j++;
        else k++; 
    }
    while (j <= mid)
    {
        aux[i++] = arr[j++];
    }
    while (k <= h)
    {
        aux[i++] = arr[k++];
    }
    j = 0;
    for (int i = l; i <= h; i++)
    {
        arr[i] = aux[j++];
    }
} 
           
void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}    

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
