#include <bits/stdc++.h>
#include "abkm.h"
using namespace std;
namespace personA
{
    vector<int> A2B(vector<int> _A, int _K)
    {
        if (_K == 1)
        {
            int sum = 0;
            for (int i = 0; i < _A.size(); i++)
            {
                sum += _A[i];
                sum %= 100;
            }
            return {sum + 1};
        }
        else if (_K == 2)
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
}
namespace personB
{
    vector<int> Btell(vector<int> _B, vector<int> _P)
    {
        if (_P.size() == 1)
        {
            int sumA = _P[0] - 1;
            int sumB = 0;
            int sum = 0;
            for (int i = 1; i <= 100; i++)
            {
                sum += i;
                sum %= 100;
            }
            for (int i = 0; i < _B.size(); i++)
            {
                sumB += _B[i];
                sumB %= 100;
            }
            int res = 0;
            if (sum - sumA - sumB >= 0)
            {
                res = sum - sumA - sumB;
            }
            else
            {
                res = (sum - sumA - sumB + 200) % 100;
            }
            if (res == 0)
                res = 100;
            return {res};
        }
        else if (_P.size() == 2)
        {
            int sumA = _P[0];
            int prodA = _P[1];
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
}
