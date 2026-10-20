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
int n, q, a[N], cnt[N];
ii query[N], ans[N];
vector<int> prime;
vector<ii> vec;
void backtrack(int id, int val, int cur)
{
    if (id >= prime.size())
        return;
    vec.push_back({val, cur});
    int p = prime[id];
    int limit = 1e18;
    while (val <= limit / p)
    {
        if (id >= 1 && cnt[id] >= cnt[id - 1])
            break;
        cnt[id]++;
        backtrack(id + 1, val * p, cur * (cnt[id] + 1));
        p *= prime[id];
    }
    cnt[id] = 0;
}
void solve()
{
    for (int i = 2; i <= 50; i++)
    {
        bool check = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                check = 0;
                break;
            }
        }
        if (check)
            prime.push_back(i);
    }
    backtrack(0, 1, 1);
    sort(vec.begin(), vec.end());
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> query[i].fi;
        query[i].se = i;
    }
    sort(query + 1, query + q + 1);
    int j = 0, maxn = 0, res = 0;
    for (int i = 1; i <= q; i++)
    {
        while (j < vec.size() && vec[j].fi <= query[i].fi)
        {
            if (vec[j].se > maxn)
                {
                    maxn = vec[j].se;
                    res = vec[j].fi;
                }
            j++;
        }
        ans[query[i].se] = {res, maxn};
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i].fi << " " << ans[i].se << endl;
}
main()
{
    skibidi;
    file("BAI1");
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
