#include <bits/stdc++.h>
#include "abcards.h"

using namespace std;
long long C[55][55];
void tohop()
{
    for (long long i = 0; i <= 52; i++)
    {
        C[i][0] = 1;
        for (long long j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
namespace personA
{
    long long A2B(vector<int> _C)
    {
        long long res = 0;
        tohop();
        sort(_C.begin(), _C.end());
        int n = _C.size();
        int k = n;
        for (int i = 10; i < k; i++)
        {
            res += C[52][i];
        }
        int last = 0;
        for (int i = 0; i < k; i++)
        {
            for (int v = last + 1; v < _C[i]; v++)
            {
                res += C[52 - v][k - 1 - i];
            }
            last = _C[i];
        }

        return res;
    }
}

namespace personB
{
    vector<int> Btell(long long _Num)
    {
        tohop();
        vector<int> res;
        int k = 10;
        int last = 0;
        for (; k <= 20; k++)
        {
            if (_Num >= C[52][k])
            {
                _Num -= C[52][k];
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < k; i++)
        {
            for (int v = last + 1; v <= 52; v++)
            {
                long long ways = C[52 - v][k - 1 - i];
                if (_Num >= ways)
                {
                    _Num -= ways;
                }
                else
                {
                    res.push_back(v);
                    last = v;
                    break;
                }
            }
        }
        return res;
    }
}
