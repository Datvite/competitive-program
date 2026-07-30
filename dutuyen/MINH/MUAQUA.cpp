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
int k, n, S;
vector<int> vals[N];
vector<int> res;
void backtrack(int id, int last, int sum)
{
    if (id > k)
    {
        if (sum == S)
        {
            cout << "YES" << endl;
            for (int x : res)
                cout << x << " ";
            exit(0);
        }
        return;
    }
    for (auto x : vals[id])
    {
        if (x >= last && sum + x <= S)
        {
            res.push_back(x);
            backtrack(id + 1, x, sum + x);
            res.pop_back();
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            vals[j].push_back(x);
        }
    }
    for (int i = 1; i <= k; i++)
        sort(all(vals[i]));
    backtrack(1, 0, 0);
    cout << "NO";
}
main()
{
    skibidi;
    file("");
    cin >> k >> n >> S;
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
