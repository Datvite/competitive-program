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
int n, m, q, a[N];
vector<int> cnt[28];
string str;
void solve()
{
    for (int i = 1; i <= n; i++)
        cnt[str[i] - 'a'].push_back(i);
    cin >> q;
    int mask = 0;
    int full = (1 << m) - 1;
    for (int i = n; i >= 1; i--)
    {
        int pos = str[i] - 'a';
        mask = On(mask, pos);
        if (mask == full)
        {
            a[i] = a[i + 1] + 1;
            mask = 0;
        }
        else
            a[i] = a[i + 1];
    }
    while (q--)
    {
        string x;
        cin >> x;
        int tmp = -1;
        bool check = 1;
        for (char c : x)
        {
            int cur = c - 'a';
            auto id = upper_bound(all(cnt[cur]), tmp);
            if (id != cnt[cur].end())
                tmp = *id;
            else
            {
                check = 0;
                break;
            }
        }
        if (check)
            cout << a[tmp + 1] + 1 << endl;
        else
            cout << 0 << endl;
    }
}
main()
{
    skibidi;
    file("");
    cin >> n >> m;
    cin >> str;
    str = " " + str;
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
