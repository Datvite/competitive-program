#include <bits/stdc++.h>
using namespace std;
long long n, s;
bool snt[10000068];
long long _swap(long long val)
{
    s = 0;
    while (val != 0)
    {
        s = val % 10 + s * 10;
        val /= 10;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("PPRIME.INP", "r", stdin);
    freopen("PPRIME.OUT", "w", stdout);
    cin >> n;
    memset(snt, true, sizeof(snt));
    snt[1] = false;
    snt[0] = false;
    for (int i = 2; i <= sqrt(10000069); i++)
    {
        if (snt[i] == true)
        {
            for (int j = i * i; j <= 10000069; j += i)
            {
                snt[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (snt[i] == true && snt[_swap(i)] == true)
        {
            cout << i << " ";
        }
    }
}
