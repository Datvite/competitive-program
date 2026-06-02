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
const int BASE = 1e6;
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
int n, m, a[N], h[N], col[N], cnt1 = 0, cnt2 = 0, cnt3 = 0;
string s;
int pw[N];
vector<int> g[N];
int build_hash(vector<int> &s)
{
    int H = 0;
    for (int i = 0; i < s.size(); i++)
        H = (H * BASE + s[i]) % MOD;
    return H;
}
void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
        h[i] = build_hash(g[i]);
    }
    int s1 = -1, s2 = -1, s3 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] != s1)
        {
            if (s1 == -1)
                s1 = h[i];
            else if (h[i] != s2)
            {
                if (s2 == -1)
                    s2 = h[i];
                else if (h[i] != s3)
                {
                    if (s3 == -1)
                        s3 = h[i];
                    else
                    {
                        cout << -1;
                        return;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (h[i] == s1)
        {
            col[i] = 1;
            cnt1++;
        }
        else if (h[i] == s2)
        {
            col[i] = 2;
            cnt2++;
        }
        else if (h[i] == s3)
        {
            col[i] = 3;
            cnt3++;
        }
    }
    if (cnt1 == 0 || cnt2 == 0 || cnt3 == 0)
    {
        cout << -1;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (col[i] == 1 && g[i].size() != cnt2 + cnt3)
        {
            cout << -1;
            return;
        }
        else if (col[i] == 2 && g[i].size() != cnt1 + cnt3)
        {
            cout << -1;
            return;
        }
        else if (col[i] == 3 && g[i].size() != cnt1 + cnt2)
        {
            cout << -1;
            return;
        }
    for (int i = 1; i <= n; i++)
        cout << col[i] << " ";
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * BASE % MOD;
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
