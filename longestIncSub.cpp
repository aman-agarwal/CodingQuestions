#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int L[], int A[], int ind, int m)
{
    int l = 0, h = ind;
    while (l <= h)
    {
        int mid = (l + h)/2;
        if (A[L[mid]] <= m && (mid == ind || A[L[mid + 1]] > m))
        {
            return mid;
        }
        else if (A[L[mid]] <= m)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

vector<int> longestIncSub(int A[], int N)
{
    int L[N], P[N];
    int maxL = 0;
    L[0] = 0; P[0] = -1;

    for (int i = 1; i < N; i++)
    {
        int l = binarySearch(L, A, maxL, A[i]);
        if (l == maxL || A[L[l + 1]] > A[i]) L[l + 1] = i;
        if (l == maxL) maxL++;
  
        if (l >= 0) P[i] = L[l];
        else P[i] = -1;
    }     
    
    vector<int> v;
    int ind = L[maxL];
    while (ind >= 0)
    {
        v.push_back(A[ind]);
        ind = P[ind];
    }
    reverse(v.begin(), v.end());
    return v;
}    


int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> v = longestIncSub(arr, N);
    
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}
    

