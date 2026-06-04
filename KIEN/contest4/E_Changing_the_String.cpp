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
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 2e5 + 69;
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
int t, n, m, a[N];
set<int> tr[3][3];
string str;
void solve()
{
    cin >> n >> m;
    cin >> str;
    for (int i = 1; i <= m; i++)
    {
        char x, y;
        cin >> x >> y;
        tr[x - 'a'][y - 'a'].insert(i);
    }
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch == 'b')
        {
            if (!tr[1][0].empty())
            {
                str[i] = 'a';
                tr[1][0].erase(tr[1][0].begin());
            }
            else if (!tr[1][2].empty() && !tr[2][0].empty())
            {
                int id = *tr[1][2].begin();
                auto it = tr[2][0].lower_bound(id);
                if (it != tr[2][0].end())
                {
                    tr[2][0].erase(it);
                    tr[1][2].erase(tr[1][2].begin());
                    str[i] = 'a';
                }
            }
        }
        else if (ch == 'c')
        {
            if (!tr[2][0].empty())
            {
                str[i] = 'a';
                tr[2][0].erase(tr[2][0].begin());
            }
            else if (!tr[2][1].empty() && !tr[1][0].empty())
            {
                int id = *tr[2][1].begin();
                auto it = tr[1][0].lower_bound(id);
                if (it != tr[1][0].end())
                {
                    tr[1][0].erase(it);
                    tr[2][1].erase(tr[2][1].begin());
                    str[i] = 'a';
                }
                else if (!tr[2][1].empty())
                {
                    str[i] = 'b';
                    tr[2][1].erase(tr[2][1].begin());
                }
            }
            else if (!tr[2][1].empty())
            {
                str[i] = 'b';
                tr[2][1].erase(tr[2][1].begin());
            }
        }
    }
    cout << str << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tr[i][j].clear();
        }
    }
}
main()
{
    skibidi;
    file("");
    cin >> t;
    while (t--)
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
