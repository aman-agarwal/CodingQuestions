#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int a = 6;
    char c = (char) (a-1) + '1';
    std::cout<<"Hello world " << c << std::endl;
    

    /* v.size changes */
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        v.push_back(i+1);
        if (i == 10) break;
    }    


    return 0;
}
