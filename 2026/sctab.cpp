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
int n, m, s;
vector<int> a[N];
vector<int> stablesort(vector<int> cur, int k)
{
    stable_sort(all(cur), [&](int x, int y)
                { return a[x][k] < a[y][k]; });
    return cur;
}
struct str
{
    vector<int> pos;
    vector<int> ops;
    int mask;
};
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        a[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    vector<int> posa(n);
    for (int i = 0; i < n; i++)
            posa[i] = i + 1;
    vector<int> posb = posa;
    for (int i = 1; i <= s; i++)
    {
        int k;
        cin >> k;
        posb = stablesort(posb, k);
    }
    if (posa == posb)
    {
        cout << 0 << endl;
        exit(0);
    }
    queue<str> q;
    set<vector<int>> vis;
    q.push({posa, {}, 0});
    vis.insert(posa);
    while (!q.empty())
    {
        str cur = q.front();
        q.pop();
        for (int k = 1; k <= m; k++)
        {
            if (cur.mask & (1LL << (k - 1)))
                continue;
            vector<int> ntxpos = stablesort(cur.pos, k);
            if (vis.find(ntxpos) == vis.end())
            {
                vector<int> ntxops = cur.ops;
                ntxops.push_back(k);
                if (ntxpos == posb)
                {
                    cout << ntxops.size() << endl;
                    for (int i = 0; i < ntxops.size(); i++)
                        cout << ntxops[i] << " ";
                    exit(0);
                }
                vis.insert(ntxpos);
                q.push({ntxpos, ntxops, On(cur.mask, k - 1)});
            }
        }
    }
}
main()
{
    skibidi;
    file("sctab");
    cin >> n >> m >> s;
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
