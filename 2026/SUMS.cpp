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
#define endl "\n"
using namespace std;
const int N = 205;
int n, S, a[N];
vector<ii> v1;
vector<ii> v2;
void backtrack1(int id, int sum, int mask)
{
    if (sum > S)
        return;
    if (id > n / 2)
    {
        v1.push_back({sum, mask});
        return;
    }
    backtrack1(id + 1, sum, mask);
    backtrack1(id + 1, sum + a[id], mask | (1LL << (id - 1)));
}
void backtrack2(int id, int sum, int mask)
{
    if (sum > S)
        return;
    if (id > n)
    {
        v2.push_back({sum, mask});
        return;
    }
    backtrack2(id + 1, sum, mask);
    backtrack2(id + 1, sum + a[id], mask | (1LL << (id - 1 - n / 2)));
}
void solve()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    backtrack1(1, 0, 0);
    backtrack2(n / 2 + 1, 0, 0);
    sort(v1.begin(), v1.end());
    for (auto x : v2)
    {
        int sum2 = x.fi;
        int mask1 = x.se;
        int tm = S - sum2;
        auto it = lower_bound(v1.begin(), v1.end(), ii(tm, 0LL));
        if (it != v1.end() && it->fi == tm)
        {
            int mask2 = it->se;
            vector<int> chosen;
            for (int i = 1; i <= n / 2; i++)
            {
                if ((mask2 >> (i - 1)) & 1)
                    chosen.push_back(a[i]);
            }
            for (int i = n / 2 + 1; i <= n; i++)
            {
                if ((mask1 >> (i - 1 - n / 2)) & 1)
                    chosen.push_back(a[i]);
            }
            cout << 1 << endl;
            for (int i = 0; i < chosen.size(); i++)
                cout << chosen[i] << " ";
            return;
        }
    }

    cout << -1 << endl;
}
bool dp[40007];
int trace[207][40007];
void solve2()
{
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 0; j <= S; j++)
        dp[j] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = S; j >= a[i]; j--)
        {
            if (!dp[j] && dp[j - a[i]])
            {
                dp[j] = 1;
                trace[i][j] = 1;
            }
        }
    }
    if (!dp[S])
    {
        cout << -1 << endl;
        return;
    }
    cout << 1 << endl;
    vector<int> chosen;
    int curs = S;
    for (int i = n; i >= 1; i--)
    {
        if (trace[i][curs] == 1)
        {
            chosen.push_back(a[i]);
            curs -= a[i];
        }
    }
    reverse(chosen.begin(), chosen.end());
    for (int i = 0; i < chosen.size(); i++)
        cout << chosen[i] << " ";
}
signed main()
{
    skibidi;
    file("SUMS");
    cin >> n >> S;
    if (n <= 40)
        solve();
    else
        solve2();
    return 0;
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