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
    int n, m, s, t, a[N];
    struct BFS
    {
        int n;
        vector<vector<int>> adj;
        vector<int> dist;
        BFS(int _n)
        {
            n = _n;
            adj.assign(n + 1, {});
            dist.assign(n + 1, 1e18);
        }
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        void run(int s)
        {
            queue<int> q;
            q.push(s);
            dist[s] = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (dist[v] > dist[u] + 1)
                    {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    };
    void solve()
    {
        BFS bfs(n);
        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                int v;
                cin >> v;
                bfs.addEdge(i, v);
            }
        }
        bfs.run(s);
        int ans = 0;
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (bfs.dist[i] != 1e18)
                {
                    ans++;
                    res.push_back(i);
                }
        }
        cout << ans << endl;
        for (int x : res)
            cout << x << " ";
        cout << endl;
    }
    main()
    {
        skibidi;
        file("");
        cin >> n >> s;
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
