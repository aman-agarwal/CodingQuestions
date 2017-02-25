#include <iostream>

using namespace std;

int recPalin(int m)
{
   if (m == 0 || m == 1) return 1;
   int count = 0;
   if (m % 2)
   {
       for (int i = 1; i <= m; i += 2) count += recPalin((m - i)/2);
   }
   else
   {
       for (int i = 0; i <= m; i += 2) count += recPalin((m - i)/2);
   }
   return count;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int m;
        cin >> m;
        cout << i << " " << recPalin(m) << endl;
    }
    return 0;
}

 
