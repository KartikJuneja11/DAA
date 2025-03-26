#include <iostream>
#include <vector>
using namespace std;

//Inefficient implementation
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

//top-down implementationi
int memoized_cut_rod_aux(vector<int> p, int n, vector<int> r){
    int q;
    if(r[n] >= 0){
        return r[n];
    }
    if(n == 0) q = 0;
    else{
        q = -1e9;
        for(int i = 1; i <= n; i++){
            q = max(q, p[i - 1] + memoized_cut_rod_aux(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}

int memoized_cut_rod(vector<int> p, int n){
    vector<int> r(n+1);
    for(int i = 0; i <= n; i++){
        r[i] = -1e9;
    }
    return memoized_cut_rod_aux(p, n, r);
}

int main()
{
    vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    // cout << cutrod(p, 4);
    cout << memoized_cut_rod(p, 10);
    return 0;
}