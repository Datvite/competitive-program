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
const int N = 1e3 + 69;
const int MAX_STEP = 2069;
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

int n, m;
vector<int> adj[N];
int parent1[MAX_STEP][N], parent2[MAX_STEP][N];
bool has1[N], has2[N];

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (1 == n)
    {
        cout << 0 << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }

    vector<int> cur1 = {1};
    vector<int> cur2 = {n};

    for (int step = 1; step < MAX_STEP; step++)
    {
        vector<int> nxt1, nxt2;
        vector<bool> vis1(n + 1, false);
        vector<bool> vis2(n + 1, false);

        for (int u : cur1)
        {
            for (int v : adj[u])
            {
                if (!vis1[v])
                {
                    vis1[v] = true;
                    parent1[step][v] = u;
                    nxt1.push_back(v);
                }
            }
        }

        for (int u : cur2)
        {
            for (int v : adj[u])
            {
                if (!vis2[v])
                {
                    vis2[v] = true;
                    parent2[step][v] = u;
                    nxt2.push_back(v);
                }
            }
        }

        if (nxt1.empty() || nxt2.empty())
        {
            cout << -1 << endl;
            return;
        }

        int meet = -1;
        for (int v : nxt1)
        {
            if (vis2[v])
            {
                meet = v;
                break;
            }
        }

        if (meet != -1)
        {
            cout << step << endl;

            vector<int> path1, path2;
            int node1 = meet;
            for (int s = step; s >= 1; s--)
            {
                path1.push_back(node1);
                node1 = parent1[s][node1];
            }
            path1.push_back(1);
            reverse(all(path1));

            int node2 = meet;
            for (int s = step; s >= 1; s--)
            {
                path2.push_back(node2);
                node2 = parent2[s][node2];
            }
            path2.push_back(n);
            reverse(all(path2));

            for (int x : path1)
                cout << x << " ";
            cout << endl;

            for (int x : path2)
                cout << x << " ";
            cout << endl;
            return;
        }

        cur1 = move(nxt1);
        cur2 = move(nxt2);
    }

    cout << -1 << endl;
}

main()
{
    skibidi;
    file("RMOVE");
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
