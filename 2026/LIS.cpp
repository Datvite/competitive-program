#include <bits/stdc++.h>
#define task "LCS2"
#define ll long long
#define ii std::pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ins insert
using namespace std;
const int N = 1e3 + 67;
const int mod = 1e9 + 7;

ll add(ll a, ll b)
{
    return (a + b) % mod;
}
ll sub(ll a, ll b)
{
    return (a - b + mod) % mod;
}
ll mul(ll a, ll b)
{
    return (a * b) % mod;
}
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    ll tmp = power(x, y / 2) % mod;
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return tmp * tmp % mod * x % mod;
    }
}
int n, m, f[N][N];
char a[N], b[N];
string str1, str2;
signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> str1;
    n = str1.size();
    for (int i = 1; i <= str1.size(); i++)
        a[i] = str1[i - 1];
    cin >> str2;
    m = str2.size();
    for (int i = 1; i <= str2.size(); i++)
        b[i] = str2[i - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    // trace
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            lcs = a[i] + lcs;
            i--;
            j--;
        }
        else if (f[i - 1][j] > f[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << lcs;
}
