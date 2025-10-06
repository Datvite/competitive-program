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
const int MOD = 2e9 + 11;
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
int n, a[N], t;
priority_queue<int, vector<int>> q;
set<int, greater<int>> s;
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else
        {
            if (q.empty())
                continue;
            int maxn = q.top();
            while (!q.empty() && maxn == q.top())
                q.pop();
        }
    }
    while (!q.empty())
    {
        s.insert(q.top());
        q.pop();
    }
    cout << s.size() << endl;
    for (auto x : s)
        cout << x << " ";
}
main()
{
    skibidi;
    file("PQ");
    solve();
}
