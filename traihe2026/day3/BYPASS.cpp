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
int n, m, q, a[N][N], pre[N][N];
const int MAXQ = 500005;
bool ans[MAXQ];
char ch[N][N];
struct query
{
    int x1, y11, x2, y2, id;
};
vector<query> queries;
bitset<1005> up0[505][N], up1[505][N], down0[N], down1[N], prev_down0[N], prev_down1[N];
void dnc(int l, int r, vector<query> &vec)
{
    if (vec.empty())
        return;
    if (l == r)
    {
        for (auto q : vec)
            ans[q.id] = (pre[q.x1][q.y2] - pre[q.x1][q.y11 - 1] <= 1);
        return;
    }
    vector<query> L, R, cross[N];
    int mid = (l + r) >> 1;
    for (auto q : vec)
    {
        if (q.x2 <= mid)
            L.push_back(q);
        else if (q.x1 > mid)
            R.push_back(q);
        else
            cross[q.x1].push_back(q);
    }
    for (int nxtf = mid + 1; nxtf <= r; nxtf++)
    {
        int dif = nxtf - mid;
        for (int j = 1; j <= m; j++)
        {
            up0[dif][j].reset();
            up1[dif][j].reset();
            bitset<1005> temp0, temp1;
            if (dif == 1)
            {
                temp0.set(j);
                temp1.set(j);
            }
            else
            {
                temp0 |= up0[dif - 1][j];
                temp1 |= up1[dif - 1][j];
            }
            if (j > 1)
            {
                temp0 |= up0[dif][j - 1];
                temp1 |= up1[dif][j - 1];
            }
            if (ch[nxtf][j] == '.')
            {
                up0[dif][j] = temp0;
                up1[dif][j] = temp1;
            }
            else
                up1[dif][j] = temp0;
        }
    }
    for (int nxtf = mid; nxtf >= l; nxtf--)
    {
        for (int j = m; j >= 1; j--)
        {
            down0[j].reset();
            down1[j].reset();
            bitset<1005> temp0, temp1;
            if (nxtf == mid)
            {
                temp0.set(j);
                temp1.set(j);
            }
            else
            {
                temp0 |= prev_down0[j];
                temp1 |= prev_down1[j];
            }
            if (j < m)
            {
                temp0 |= down0[j + 1];
                temp1 |= down1[j + 1];
            }
            if (ch[nxtf][j] == '.')
            {
                down0[j] = temp0;
                down1[j] = temp1;
            }
            else
                down1[j] = temp0;
        }
        for (int j = 1; j <= m; j++)
        {
            prev_down0[j] = down0[j];
            prev_down1[j] = down1[j];
        }
        for (auto [x1, y11, x2, y2, id] : cross[nxtf])
        {
            int dif = x2 - mid;
            if ((down0[y11] & up0[dif][y2]).any())
                ans[id] = 1;
            if ((down0[y11] & up1[dif][y2]).any())
                ans[id] = 1;
            if ((down1[y11] & up0[dif][y2]).any())
                ans[id] = 1;
        }
    }
    dnc(l, mid, L);
    dnc(mid + 1, r, R);
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            pre[i][j] = pre[i][j - 1] + (ch[i][j] == '#');
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({x1, y1, x2, y2, i});
        ans[i] = 0;
    }
    dnc(1, n, queries);
    for (int i = 1; i <= q; i++)
    {
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
main()
{
    skibidi;
    file("BYPASS");
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
