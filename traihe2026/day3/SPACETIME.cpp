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
const int N = 1005;
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
int n, m, q, pre[N][N];
const int MAXQ = 500005;
int ans[MAXQ];
int a[N][N];
int up[N][N], down[N][N];
struct query
{
    int x1, y11, x2, y2, id;
};
vector<query> queries;
void dnc(int l, int r, int l1, int r1, vector<query> &vec)
{
    if (vec.empty())
        return;
    if (l > r || l1 > r1)
        return;
    if (r - l >= r1 - l1)
    {
        vector<query> L, R, cross;
        int mid = (l + r) >> 1;
        for (auto q : vec)
        {
            if (q.x2 < mid)
                L.push_back(q);
            else if (q.x1 > mid)
                R.push_back(q);
            else
                cross.push_back(q);
        }
        for (int k = l1; k <= r1; k++)
        {
            for (int i = mid; i >= l; i--)
            {
                for (int j = r1; j >= l1; j--)
                {
                    up[i][j] = 1e18;
                    if (i == mid && j == k)
                        up[i][j] = a[i][j];
                    else
                    {
                        if (i + 1 <= mid)
                            up[i][j] = min(up[i][j], up[i + 1][j] + a[i][j]);
                        if (j + 1 <= r1)
                            up[i][j] = min(up[i][j], up[i][j + 1] + a[i][j]);
                    }
                }
            }
            for (int i = mid; i <= r; i++)
            {
                for (int j = l1; j <= r1; j++)
                {
                    down[i][j] = 1e18;
                    if (i == mid && j == k)
                        down[i][j] = a[i][j];
                    else
                    {
                        if (i - 1 >= mid)
                            down[i][j] = min(down[i][j], down[i - 1][j] + a[i][j]);
                        if (j - 1 >= l1)
                            down[i][j] = min(down[i][j], down[i][j - 1] + a[i][j]);
                    }
                }
            }
            for (auto q : cross)
            {
                if (q.y11 <= k && k <= q.y2)
                {
                    ans[q.id] = min(ans[q.id], up[q.x1][q.y11] + down[q.x2][q.y2] - a[mid][k]);
                }
            }
        }
        dnc(l, mid - 1, l1, r1, L);
        dnc(mid + 1, r, l1, r1, R);
    }
    else
    {
        vector<query> L, R, cross;
        int mid = (l1 + r1) >> 1;
        for (auto q : vec)
        {
            if (q.y2 < mid)
                L.push_back(q);
            else if (q.y11 > mid)
                R.push_back(q);
            else
                cross.push_back(q);
        }
        for (int k = l; k <= r; k++)
        {
            for (int i = r; i >= l; i--)
                for (int j = mid; j >= l1; j--)
                {
                    {
                        up[i][j] = 1e18;
                        if (i == k && j == mid)
                            up[i][j] = a[i][j];
                        else
                        {
                            if (i + 1 <= r)
                                up[i][j] = min(up[i][j], up[i + 1][j] + a[i][j]);
                            if (j + 1 <= mid)
                                up[i][j] = min(up[i][j], up[i][j + 1] + a[i][j]);
                        }
                    }
                }
            for (int i = l; i <= r; i++)
                for (int j = mid; j <= r1; j++)
                {
                    {
                        down[i][j] = 1e18;
                        if (i == k && j == mid)
                            down[i][j] = a[i][j];
                        else
                        {
                            if (i - 1 >= l)
                                down[i][j] = min(down[i][j], down[i - 1][j] + a[i][j]);
                            if (j - 1 >= mid)
                                down[i][j] = min(down[i][j], down[i][j - 1] + a[i][j]);
                        }
                    }
                }
            for (auto q : cross)
            {
                if (q.x1 <= k && k <= q.x2)
                {
                    ans[q.id] = min(ans[q.id], up[q.x1][q.y11] + down[q.x2][q.y2] - a[k][mid]);
                }
            }
        }
        dnc(l, r, l1, mid - 1, L);
        dnc(l, r, mid + 1, r1, R);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({x1, y1, x2, y2, i});
        ans[i] = 1e18;
    }
    dnc(1, n, 1, m, queries);
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }
}
main()
{
    skibidi;
    file("SPACETIME");
    cin >> n >> m;
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
