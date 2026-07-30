#include <bits/stdc++.h>
#include "abm.h"
using namespace std;
namespace personA
{
    pair<int, int> A2B(vector<int> _A)
    {
        int sum = 0, prod = 1;
        for (int i = 0; i < _A.size(); i++)
        {
            sum += _A[i];
            sum %= 101;
            prod *= _A[i];
            prod %= 101;
        }
        if (sum == 0)
            sum = 101;
        if (prod == 0)
            prod = 101;
        return {sum, prod};
    }
}
namespace personB
{
    pair<int, int> Btell(vector<int> _B, pair<int, int> _P)
    {
        int sumA = _P.first;
        int prodA = _P.second;
        int sumB = 0;
        int prodB = 1;
        int sum = 0;
        int prod = 1;
        for (int i = 1; i <= 100; i++)
        {
            sum += i;
            sum %= 101;
            prod *= i;
            prod %= 101;
        }
        vector<bool> check(105, false);
        for (int i = 0; i < _B.size(); i++)
        {
            sumB += _B[i];
            sumB %= 101;
            prodB *= _B[i];
            prodB %= 101;
            check[_B[i]] = 1;
        }
        int x, y;
        for (int i = 1; i <= 100; i++)
        {
            if (check[i])
                continue;
            for (int j = i + 1; j <= 100; j++)
            {
                if (check[j])
                    continue;
                if ((1LL * i * j * prodB * prodA) % 101 == prod && (i + j + sumA + sumB) % 101 == sum)
                {
                    return {i, j};
                }
            }
        }
    }
}
