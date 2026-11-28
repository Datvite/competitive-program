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
int n, m, c;
int a[N];
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> dqmax, dqmin;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        while (!dqmax.empty() && dqmax.front() <= i - m)
            dqmax.pop_front();
        while (!dqmin.empty() && dqmin.front() <= i - m)
            dqmin.pop_front();
        while (!dqmax.empty() && a[dqmax.back()] <= a[i])
            dqmax.pop_back();
        while (!dqmin.empty() && a[dqmin.back()] >= a[i])
            dqmin.pop_back();
        dqmax.push_back(i);
        dqmin.push_back(i);
        if (i >= m && a[dqmax.front()] - a[dqmin.front()] <= c)
            ans.push_back(i - m + 1);
    }
    if (ans.empty())
    {
        cout << "NONE" << endl;
        return;
    }
    for (int pos : ans)
        cout << pos << endl;
}
main()
{
    skibidi;
    file("CLIMBING");
    cin >> n >> m >> c;
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
