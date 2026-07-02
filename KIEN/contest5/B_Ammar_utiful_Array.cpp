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
#define int long long
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
const int BASE = 256;
const int MOD = 1e9 + 7;
int add(int a, int b)
{
    return (a + b) % MOD;
}
int sub(int a, int b)
{
    return ((a - b) % MOD + MOD) % MOD;
}
int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n, q, a[N], dif[N], S = 0;
vector<int> color[N], sum[N];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        color[x].push_back(a[i]);
    }
    for (int i = 1; i < N; i++)
    {
        if (!color[i].size())
            continue;
        sum[i].resize(color[i].size() + 1, 0);
        for (int j = 0; j < color[i].size(); j++)
            sum[i][j + 1] = sum[i][j] + color[i][j];
    }
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int col, val;
            cin >> col >> val;
            dif[col] += val; 
            S += val;
        }
        else
        {
            int col, val;
            cin >> col >> val;
            int l = 1, r = color[col].size(), ans = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (sum[col][mid] + mid * (S - dif[col]) <= val)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cout << ans << endl;
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> n;
    solve();
}
/*  I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/
