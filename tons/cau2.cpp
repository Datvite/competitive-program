#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task "CHEG"

using namespace std;
const int INF = (int)1e18;
const int N = 105;

int n, m;
int dp[N][N][N][2];
bool vis[N][N][N][2];

int F(int bag, int h0, int h1, int t)
{
    if (bag == 0)
        return 0;
    if (vis[bag][h0][h1][t])
    {
        return dp[bag][h0][h1][t];
    }
    vis[bag][h0][h1][t] = true;

    if (t == 0)
    {
        int best = 0;
        for (int x = 1; x <= min(m, bag); ++x)
        {
            if (x < bag)
            {
                int val = F(bag - x, h0 + x, h1, 1);
                if (val > best)
                    best = val;
            }
            else
            {
                int ans = h0 + x;
                int val = ans + F(h1, 0, 0, 1);
                if (val > best)
                    best = val;
            }
        }
        dp[bag][h0][h1][t] = best;
        return best;
    }
    else
    {
        int best = INF;
        for (int x = 1; x <= min(m, bag); ++x)
        {
            if (x < bag)
            {
                int val = F(bag - x, h0, h1 + x, 0);
                if (val < best)
                    best = val;
            }
            else
            {
                int val = F(h0, 0, 0, 0);
                if (val < best)
                    best = val;
            }
        }
        dp[bag][h0][h1][t] = best;
        return best;
    }
}

void logic()
{
    cin >> n >> m;
    ms(vis, false);
    cout << F(n, 0, 0, 0) << '\n';
    // execute;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:
*/