#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define endl "\n"
using namespace std;
const int N = 2e3 + 69;
ll n, m, ans = 0, maxlength;
string a, b, res;
ll f[N][N];
void sol()
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (a[i] != b[j])
            {
                if (f[i + 1][j] > f[i][j + 1])
                {
                    f[i][j] = f[i + 1][j];
                }
                else if (f[i + 1][j] < f[i][j + 1])
                {
                    f[i][j] = f[i][j + 1];
                }
                else if (a[i + 1] > b[j + 1])
                    f[i][j] = f[i + 1][j];
                else
                    f[i][j] = f[i][j + 1];
            }
            else
            {
                f[i][j] = f[i + 1][j + 1] + 1;
            }
        }
    }
    string ans;
    ll i = 1, j = 1, k = 0;
    while (i <= n && j <= m)
    {
        if (a[i] == b[j])
        {
            ans += a[i];
            i++;
            j++;
        }
        else if (f[i + 1][j] > f[i][j + 1])
            i++;
        else if (f[i + 1][j] < f[i][j + 1])
            j++;
        else
        {
            if (a[i + 1] > b[j + 1])
                i++;
            else
                j++;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    /*i = 1, j = 1;
    while (k < ans.size())
    {
        while (a[i] != ans[k])
        {
            res += a[i];
            i++;
        }
        while (b[j] != ans[k])
        {
            res += b[j];
            j++;
        }
        res += ans[k];
        k++;
        i++;
        j++;
    }
    while (i <= n)
    {
        res += a[i];
        i++;
    }
    while (j <= m)
    {
        res += b[j];
        j++;
    }
    cout << res << endl;*/
}
main()
{
    skibidi;
    file("LEXLCS");
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    sol();
}
