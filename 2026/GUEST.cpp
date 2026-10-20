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
    int n, a[N], dp[N][2];
    vector<int> trace[N][2];
    int root;
    vector<int> adj[N];
    void dfs(int u, int par)
    {
        dp[u][1] = a[u];
        trace[u][1].push_back(u);
        for (int v : adj[u])
        {
            if (v != par)
            {
                dfs(v, u);
                if (dp[v][0] > dp[v][1])
                {
                    dp[u][0] = dp[u][0] + dp[v][0];
                    for (int x : trace[v][0])
                        trace[u][0].push_back(x);
                }
                else
                {
                    dp[u][0] = dp[u][0] + dp[v][1];
                    for (int x : trace[v][1])
                        trace[u][0].push_back(x);
                }
                dp[u][1] = dp[u][1] + dp[v][0];
                for (int x : trace[v][0])
                    trace[u][1].push_back(x);
            }
        }
        //cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
    }
    void solve()
    {
        for (int i = 1; i <= n; i++)
        {
            int u, w;
            cin >> u >> w;
            a[i] = w;
            if (u == 0)
                root = i;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
        dfs(root, 0);
        if (dp[root][0] > dp[root][1])
        {
            cout << trace[root][0].size() << " ";
            cout << dp[root][0] << endl;
            sort(all(trace[root][0]));
            for (int x : trace[root][0])
                cout << x << endl;
        }
        else
        {
            cout << trace[root][1].size() << " ";
            cout << dp[root][1] << endl;
            sort(all(trace[root][1]));
            for (int x : trace[root][1])
                cout << x << endl;
        }
    }
    main()
    {
        skibidi;
        file("GUEST");
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
