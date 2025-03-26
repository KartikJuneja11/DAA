#include <iostream>
#include <vector>
using namespace std;

int cutrod(vector<int> p, int n)
{
    if (n == 0)
        return 0;
    int q = -1e9;
    for (int i = 1; i <= n; i++)
    {
        q = max(q, p[i - 1] + cutrod(p, n - i));
    }
    return q;
}

int main()
{
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << cutrod(p, 4);
    return 0;
}