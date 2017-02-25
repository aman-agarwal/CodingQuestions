#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX (1000000)

enum dir {L, R, U, D, H, INV};

dir min_dir(int ** arr, int i, int j, int & min)
{
    min = MAX;
    dir d;
    if (arr[i-1][j] < min) 
    {
        min = arr[i-1][j];
        d = L;
    }
    if (arr[i+1][j] < min) 
    {
        min = arr[i+1][j];
        d = R;
    }
    if (arr[i][j-1] < min) 
    {
        min = arr[i][j-1];
        d = U;
    }
    if (arr[i][j+1] < min) 
    {
        min = arr[i][j+1];
        d = D;
    }
    return d;
}

void explore(dir ** direct, int i, int j, int & count)
{
    count++;
    if (direct[i-1][j] == R) explore(direct, i-1, j, count);
    if (direct[i+1][j] == L) explore(direct, i+1, j, count);
    if (direct[i][j-1] == D) explore(direct, i, j-1, count);
    if (direct[i][j+1] == U) explore(direct, i, j+1, count);
}

vector<int> basins(int ** arr, dir ** direct, int S)
{
    dir d;
    int min;
    for (int i = 1; i <= S; i++)
    {
        for (int j = 1; j <= S; j++)
        {
             d = min_dir(arr, i, j, min);
             if (min < arr[i][j]) direct[i][j] = d;
             else direct[i][j] = H;
        }
    }
    
    vector<int> basin_sizes;
    int count;
    for (int i = 1; i <= S; i++)
    {
        for (int j = 1; j <= S; j++)
        {
             if (direct[i][j] == H)
             {
                 count = 0;
                 explore(direct, i, j, count);
                 basin_sizes.push_back(count);
             }
        }
    }
    sort(basin_sizes.begin(), basin_sizes.end());
    reverse(basin_sizes.begin(), basin_sizes.end());
    return basin_sizes;
}

template <class T>
void free_memory(T ** M, int N)
{
    for (int i = 0; i < N; i++) delete[] M[i];
    delete[] M;
}

int main()
{
    int S;
    cin >> S;
    int ** arr = new int * [S+2];
    dir ** direct = new dir * [S+2];

    for (int i = 0; i < S+2; i++)
    {
        arr[i] = new int[S+2];
        direct[i] = new dir[S+2];
    }

    for (int i = 0; i < S+2; i++)
    {
        arr[i][0] = MAX;
        arr[0][i] = MAX;
        arr[i][S+1] = MAX;
        arr[S+1][i] = MAX;

        direct[i][0] = INV;
        direct[0][i] = INV;
        direct[i][S+1] = INV;
        direct[S+1][i] = INV;
    }

    for (int i = 1; i <= S; i++)
    {
        for (int j = 1; j <= S; j++)
        {
             cin >> arr[i][j];
        }
    }

    vector<int> res = basins(arr, direct, S);
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";    
    cout << endl;    

    free_memory<dir>(direct, S+2);
    free_memory<int>(arr, S+2);
    return 0;
}
