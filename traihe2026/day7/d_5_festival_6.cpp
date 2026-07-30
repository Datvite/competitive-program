#include <bits/stdc++.h>
using namespace std;
vector<int> solveGenius(int N, int S, const vector<int> &U, const vector<int> &V)
{
    if (U.size() == 0 && V.size() == 0)
    {
        if (S >= 2)
        {
            vector<int> v;
            v.push_back(1);
            v.push_back(1);
            return v;
        }
        else
        {
            vector<int> v;
            v.push_back(1);
            v.push_back(2);
            return v;
        }
    }
    if (U[0] == 0)
    {
        vector<int> v;
        v.push_back(2);
        v.push_back(1);
        return v;
    }
    else
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        return v;
    }
}
bool solveCitizen(const vector<int> &A, const vector<vector<int>> &history)
{
    if (A[0] == 1)
        return 1;
    if (A[0] == 2)
    {
        if (history.size() > 0)
            return 1;
        else
            return 0;
    }
}
/*main()
{
    vector<int> v = solveGenius(2, 1, {}, {});
    for (int i = 1; i <= 2; i++)
    {
        vector<int> cur;
        cur.push_back(v[i - 1]);
        if (solveCitizen(cur, {}))
        {
            cout << i << " ";
        }
    }
    return 0;
}*/