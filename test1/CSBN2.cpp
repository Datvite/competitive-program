#include <bits/stdc++.h>
using namespace std;
int n, a[10000003];
long long ans = 0;
int main()
{
    freopen("CSBN.inp", "r", stdin);
    freopen("CSBN.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long cnt = 1;
    a[n + 1] = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i + 1])
            cnt++;
        else
        {
            ans += (cnt * (cnt - 1)) / 2;
            cnt = 1;
        }
    }
    cout << ans;
}
