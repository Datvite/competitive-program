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
const int N = 1e5 + 69;
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

int n;
vector<ii> adj[N];
int best_down[N], best_child[N];
int max_len = -1e18;
int best_u = -1, best_v1 = -1, best_v2 = -1;

void dfs(int u, int p)
{
    best_down[u] = 0;
    best_child[u] = 0;

    vector<pair<int, int>> branches; // {weight, child}

    for (auto [v, w] : adj[u])
    {
        if (v == p)
            continue;

        dfs(v, u);

        int branch_val = w + best_down[v];
        branches.push_back({branch_val, v});
    }

    sort(all(branches), greater<pair<int, int>>());

    if (!branches.empty())
    {
        // Xét trường hợp đường đi chỉ từ u đi xuống nhánh tốt nhất
        if (branches[0].fi > max_len)
        {
            max_len = branches[0].fi;
            best_u = u;
            best_v1 = branches[0].se;
            best_v2 = -1;
        }

        // Xét trường hợp đường đi nối 2 nhánh tốt nhất qua u
        if (branches.size() >= 2)
        {
            int two_branch = branches[0].fi + branches[1].fi;
            if (two_branch > max_len)
            {
                max_len = two_branch;
                best_u = u;
                best_v1 = branches[0].se;
                best_v2 = branches[1].se;
            }
        }

        // Cập nhật best_down cho u để cha của u sử dụng
        if (branches[0].fi > 0)
        {
            best_down[u] = branches[0].fi;
            best_child[u] = branches[0].se;
        }
    }
}

void solve()
{
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0);

    cout << max_len << endl;

    vector<int> path;
    if (best_v2 == -1)
    {
        // Đường đi từ best_u xuống best_v1
        path.push_back(best_u);
        int cur = best_v1;
        while (cur != 0)
        {
            path.push_back(cur);
            cur = best_child[cur];
        }
    }
    else
    {
        // Nối từ lá của nhánh best_v1 lên best_u rồi sang best_v2
        vector<int> left_arm;
        int cur = best_v1;
        while (cur != 0)
        {
            left_arm.push_back(cur);
            cur = best_child[cur];
        }
        reverse(all(left_arm));

        for (int x : left_arm)
            path.push_back(x);

        path.push_back(best_u);

        cur = best_v2;
        while (cur != 0)
        {
            path.push_back(cur);
            cur = best_child[cur];
        }
    }

    for (int x : path)
        cout << x << " ";
    cout << endl;
}

main()
{
    skibidi;
    file("LP");
    cin >> n;
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
