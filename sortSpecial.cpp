#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

void sortSpecial(string arr[], int n)
{ 
   vector<int> vInt;
   vector<string> vS;

   for (int i = 0; i < n; i++)
   {
       int c = atoi(arr[i].c_str());

       if (c || arr[i] == "0") vInt.push_back(c);
       else vS.push_back(arr[i]);  
   }     
        
   sort(vInt.begin(), vInt.end());
   sort(vS.begin(), vS.end());
   
   int j = 0, k = 0;
   for (int i = 0; i < n; i++)
   {
       if (arr[i] == "0" || atoi(arr[i].c_str()) != 0) arr[i] = to_string(vInt[j++]); // C++ 11
       else arr[i] = vS[k++];
   }

}

int main()
{
   int n;
   cin >> n;
   string arr[n];
   for (int i = 0; i < n; i++) cin >> arr[i];

   sortSpecial(arr, n);
   for (int i = 0; i < n; i++) cout << arr[i] << " ";

   cout << endl;

   return 0;
}
