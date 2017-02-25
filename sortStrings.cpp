#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int compare(const void * s1, const void * s2)
{
    string a = *((string *) s1);
    string b = *((string *) s2);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return strcmp(a.c_str(), b.c_str());
}

void sortStringsAnagram(string arr[], int N)
{
    qsort(arr, N, sizeof(string), compare);
}

int main()
{ 
    int N; 
    cin >> N;
    string arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    sortStringsAnagram(arr, N);
    for (int i = 0; i < N; i++) cout << arr[i] << endl;
    return 0;
}

