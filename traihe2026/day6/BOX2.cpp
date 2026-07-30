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

const int N = 3e5 + 69; // Adjust MAX based on specific problem constraints if needed
const int BASE = 256;
const int MOD = 1e9 + 7;

int n, m; 
int a[N], b[N];
bool in_tree[N];
int ans[N];

vector<ii> adj[N];
int par[N], depth[N], edge_up[N];
int dsu_link[N];

// DSU find to quickly skip tree edges that have already been assigned a weight
int find_set(int v) {
    if (v == dsu_link[v]) return v;
    return dsu_link[v] = find_set(dsu_link[v]);
}

// DFS to build the tree properties (parents, depths, and the edge connecting them)
void dfs(int u, int p, int d, int e_idx) {
    par[u] = p;
    depth[u] = d;
    edge_up[u] = e_idx;
    for (auto edge : adj[u]) {
        int v = edge.fi;
        int id = edge.se;
        if (v != p) {
            dfs(v, u, d + 1, id);
        }
    }
}

void solve() {
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    
    // Read the subset R that forms our spanning tree
    for (int i = 1; i < n; i++) {
        int id;
        cin >> id;
        in_tree[id] = true;
        adj[a[id]].push_back({b[id], id});
        adj[b[id]].push_back({a[id], id});
    }

    // Initialize Tree Structure (root at node 1)
    dfs(1, 0, 0, 0);

    // Initialize DSU (each node points to itself initially)
    for (int i = 1; i <= n; i++) {
        dsu_link[i] = i;
    }

    int nxt_wt = 1;

    // Iterate through all roads to build the lexicographically smallest permutation
    for (int i = 1; i <= m; i++) {
        if (ans[i] != 0) continue; // Already processed as a path dependency

        if (in_tree[i]) {
            // It's a tree edge, assign the next smallest available weight
            ans[i] = nxt_wt++;
            int u = a[i], v = b[i];
            if (depth[u] < depth[v]) swap(u, v); 
            
            // Mark the edge as assigned in the DSU so future non-tree edges skip it
            dsu_link[find_set(u)] = find_set(par[u]);
        } else {
            // It's a non-tree edge. Walk up the exact tree path to find dependencies.
            int u = find_set(a[i]);
            int v = find_set(b[i]);
            vector<int> path_edges;

            // Walk up to the Lowest Common Ancestor (LCA)
            while (u != v) {
                if (depth[u] < depth[v]) 
                    swap(u, v);
                path_edges.push_back(edge_up[u]);
                
                // Union the sets to compress the path for future traversals
                int p = find_set(par[u]);
                dsu_link[u] = p;
                u = p;
            }

            // Sort dependencies by edge index (lexicographically smallest rule)
            sort(all(path_edges));
            
            for (int idx : path_edges) {
                ans[idx] = nxt_wt++;
            }
            
            // Finally, assign the weight to the current non-tree edge
            ans[i] = nxt_wt++;
        }
    }

    // Output the resulting weights
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << (i == m ? "" : " ");
    }
    cout << endl;
}

main() {
    skibidi;
    file("");
    if (cin >> n >> m) {
        solve();
    }
}
/* I am the bone of my sword
    Steel is my body and fire is my blood
    I have created over a thousand blades
    Unknown to Death,
    Nor known to Life.
    Have withstood pain to create many weapons
    Yet, those hands will never hold anything
    So as I pray, unlimited blade works.
*/