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
const int N = 1e3 + 69;
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
int n, a[N][N], sum = 0;
vector<int> r, c;
vector<ii> ans;
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    sum /= n;
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (int j = 1; j <= n; j++)
            cur += a[i][j];
        if (cur != sum)
            r.push_back(i);
    }
    for (int j = 1; j <= n; j++)
    {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            cur += a[i][j];
        if (cur != sum)
            c.push_back(j);
    }
    if (r.size() == 2 && c.size() == 2)
    {
        int r1 = r[0], c1 = c[0];
        int r2 = r[1], c2 = c[1];
        bool check = 0;
        swap(a[r1][c1], a[r2][c2]);
        int cur = 0;
        for (int i = 1; i <= n; i++)
            cur += a[r1][i];
        if (cur == sum)
            check = 1;
        if (check)
        {
            ans.push_back({r1, c1});
            ans.push_back({r2, c2});
        }
        else
        {
            ans.push_back({r1, c2});
            ans.push_back({r2, c1});
        }

    }
    else if (c.size() == 1)
    {
        int r1 = r[0], r2 = r[1], c1 = c[0];
        ans.push_back({min(r1, r2), c1});
        ans.push_back({max(r1, r2), c1});
    }
    else
    {
        int c1 = c[0], c2 = c[1], r1 = r[0];
        ans.push_back({r1, min(c1, c2)});
        ans.push_back({r1, max(c1, c2)});
    }
    if (ans.size() >= 2 && ans[0] > ans[1])
        swap(ans[0], ans[1]);
    for (auto [x, y] : ans)
        cout << x << " " << y << endl;
}
main()
{
    skibidi;
    file("MAGICSQUARE");
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
