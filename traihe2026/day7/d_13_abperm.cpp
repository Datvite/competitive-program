#include <bits/stdc++.h>
#include "abperm.h"
using namespace std;

namespace personA
{
    unsigned long long A2B(vector<int> _P)
    {
        unsigned long long rank = 0;
        unsigned long long f[36];
        f[0] = 1;
        for (int i = 1; i <= 30; i++)
            f[i] = f[i - 1] * i;
        for (int i = 1; i < _P.size(); i++)
            rank += f[i];
        for (int i = 0; i < _P.size(); i++)
        {
            int cur = _P[i] - 1;
            for (int j = 0; j < i; j++)
                if (_P[j] < _P[i])
                    cur--;
            rank += cur * f[_P.size() - 1 - i];
        }
        return rank;
    }
}

namespace personB
{
    vector<int> Btell(unsigned long long _Num)
    {
        vector<int> res;
        unsigned long long f[36];
        f[0] = 1;
        for (int i = 1; i <= 30; i++)
            f[i] = f[i - 1] * i;
        int n = 1;
        while (n <= 20 && _Num >= f[n])
        {
            _Num -= f[n];
            n++;
        }
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);
        for (int i = 1; i <= n; i++)
        {
            for (auto x : s)
            {
                if (_Num >= f[n - i])
                {
                    _Num -= f[n - i];
                }
                else
                {
                    res.push_back(x);
                    s.erase(x);
                    break;
                }
            }
        }
        return res;
    }
}
