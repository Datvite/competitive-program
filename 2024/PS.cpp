#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("AVER.INP", "r", stdin);
    freopen("AVER.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, k;
    cin >> n >> k;
    long long a[1000068], s[1000068], smin[1000068];
    s[0] = 0;
    smin[0] = 0;
    long long m = 0, y, dau = 0, x = 0, cuoi = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] - k + s[i - 1];
        if (s[i] < smin[i - 1])
            smin[i] = s[i];
        else
            smin[i] = smin[i - 1];
    }
    y = n;
    x = n;
    while (y > 0)
    {
        while (s[x] - smin[y] < 0)
            x--;
        if (s[x] - smin[y - 1] >= 0 && x - y > cuoi - dau)
        {
            dau = y;
            cuoi = x;
        }
        y--;
    }
    cout << cuoi - dau + 1;
}
