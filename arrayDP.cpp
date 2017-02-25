#include <iostream>
#include <algorithm>
using namespace std;

int compute(int ** board, int n, int m)
{
   for (int i = 0; i < n; i++)
   {
     for (int j = 0; j < m; j++)
     {
         if (i || j)
         {
             if (i == 0) board[i][j] += board[i][j-1];
             else if (j == 0) board[i][j] += board[i-1][j];
             else board[i][j] += max(board[i-1][j], board[i][j-1]);     
         }
     }
   }
   return board[n-1][m-1];
}


int main() {
  int n, m;
  cin >> n >> m;
  
  int ** board = new int * [n];
  for (int i = 0; i < n; i++) board[i] = new int[m];
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
        cin >> board[i][j];
    }
  }
  cout << compute(board, n, m) << endl;
  
  
  return 0;
}
