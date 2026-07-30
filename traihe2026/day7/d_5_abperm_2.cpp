#include <bits/stdc++.h>
#include "abperm.h"
using namespace std;

// Đổi chiều mảng để tăng tối đa cache locality
unsigned long long dp[1 << 20][21];
bool cp[21][21];
bool check = 0;

void precompute()
{
    if (check)
        return;
    check = 1;
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            cp[i][j] = (i == 0 || __gcd(i, j) == 1);
        }
    }
    for (int i = 0; i <= 20; i++)
        dp[(1 << 20) - 1][i] = 1;
    for (int mask = (1 << 20) - 2; mask >= 0; mask--)
    {
        for (int j = 1; j <= 20; j++)
        {
            if (!(mask & (1 << (j - 1))))
            {
                unsigned long long ways = dp[mask | (1 << (j - 1))][j];
                if (ways > 0)
                {
                    for (int i = 0; i <= 20; i++)
                    {
                        if (cp[i][j])
                        {
                            dp[mask][i] += ways;
                        }
                    }
                }
            }
        }
    }
}
namespace personA
{
    unsigned long long A2B(vector<int> _P)
    {
        precompute();
        unsigned long long rank = 0;
        int mask = 0, last = 0;
        for (int k = 0; k < 20; k++)
        {
            int cur = _P[k];
            for (int j = 1; j < cur; j++)
            {
                if (((mask & (1 << (j - 1))) == 0) && cp[last][j])
                    rank += dp[mask | (1 << (j - 1))][j];
            }
            mask |= (1 << (cur - 1));
            last = cur;
        }
        return rank;
    }
}

namespace personB
{
    vector<int> Btell(unsigned long long _Num)
    {
        precompute();
        vector<int> res;
        int mask = 0, last = 0;
        for (int k = 0; k < 20; k++)
        {
            for (int j = 1; j <= 20; j++)
            {
                if (((mask & (1 << (j - 1))) == 0) && cp[last][j])
                {
                    unsigned long long ways = dp[mask | (1 << (j - 1))][j];
                    if (_Num >= ways)
                    {
                        _Num -= ways;
                    }
                    else
                    {
                        res.push_back(j);
                        mask |= (1 << (j - 1));
                        last = j;
                        break;
                    }
                }
            }
        }
        return res;
    }
}