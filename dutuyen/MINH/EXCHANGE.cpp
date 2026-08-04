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
const int INF = 1e9;
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
int n, S, a[N], W, res = 0;
unordered_map<int, int> mp;
vector<ii> items;
void solve()
{
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        res += a[i];
    }
    items.push_back({0, 0});
    for (auto [v, c] : mp)
    {
        if (v > 0)
            items.push_back({v, c});
    }
    int m = items.size() - 1;
    vector<int> cur(res + 1, INF);
    cur[0] = 0;
    vector<vector<int>> trace(m + 1, vector<int>(res + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        int v = items[i].fi;
        int c = items[i].se;
        vector<int> ntx = cur;
        int k = 1;
        int rem = c - 1;
        while (rem > 0)
        {
            int take = min(k, rem);
            int W = take * v;
            for (int j = res; j >= W; j--)
            {
                if (ntx[j - W] < ntx[j])
                {
                    ntx[j] = ntx[j - W];
                    trace[i][j] = trace[i][j - W] + take;
                }
            }
            rem -= take;
            k *= 2;
        }
        int W = c * v;
        for (int j = res; j >= W; j--)
        {
            if (cur[j - W] != INF && cur[j - W] + 1 < ntx[j])
            {
                ntx[j] = cur[j - W] + 1;
                trace[i][j] = c;
            }
        }
        cur = move(ntx);
    }
    int minn = INF;
    int bests = -1;
    for (int j = S; j <= res; j++)
    {
        if (cur[j] < minn)
        {
            minn = cur[j];
            bests = j;
        }
    }
    int total = mp.size();
    cout << total - minn << " " << bests << "\n";
    vector<int> ans;
    int currs = bests;
    for (int i = m; i >= 1; i--)
    {
        int k = trace[i][currs];
        int v = items[i].fi;
        for (int j = 0; j < k; j++)
            ans.push_back(v);
        currs -= k * v;
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

main()
{
    skibidi;
    file("EXCHANGE");
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