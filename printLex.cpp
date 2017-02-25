#include <iostream>
using namespace std;

void helper(int N, int M)
{
    if (M <= N)
    {
       if (M > 0) cout << M << endl;
       for (int i = 0; i <= 9; i++)
       {
            if (M + i) helper(N, M * 10 + i);
       }
    }
}  

void printLex(int N)
{
    int M = 0;
    helper(N, M);
}

int main()
{
    int N;
    cin >> N;
    printLex(N);
    return 0;
}
