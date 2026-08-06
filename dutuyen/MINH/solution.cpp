#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
// Allocate enough nodes for Segment Tree Merging (O(N log N) space)
const int MAX_NODES = 15000000; 

struct SegNode {
    int ls, rs;
    int max_in, max_out;
} tr[MAX_NODES];

int root[MAXN], node_cnt;
int val[MAXN];
int mapped_val[MAXN];
vector<int> adj[MAXN];
int n, K;
int global_ans = 1;

void update(int &p, int L, int R, int pos, int in_val, int out_val) {
    if (!p) p = ++node_cnt;
    tr[p].max_in = max(tr[p].max_in, in_val);
    tr[p].max_out = max(tr[p].max_out, out_val);
    if (L == R) return;
    int mid = L + (R - L) / 2;
    if (pos <= mid) update(tr[p].ls, L, mid, pos, in_val, out_val);
    else update(tr[p].rs, mid + 1, R, pos, in_val, out_val);
}

int query_in(int p, int L, int R, int ql, int qr) {
    if (!p || ql > qr) return 0;
    if (ql <= L && R <= qr) return tr[p].max_in;
    int mid = L + (R - L) / 2;
    int res = 0;
    if (ql <= mid) res = max(res, query_in(tr[p].ls, L, mid, ql, qr));
    if (qr > mid) res = max(res, query_in(tr[p].rs, mid + 1, R, ql, qr));
    return res;
}

int query_out(int p, int L, int R, int ql, int qr) {
    if (!p || ql > qr) return 0;
    if (ql <= L && R <= qr) return tr[p].max_out;
    int mid = L + (R - L) / 2;
    int res = 0;
    if (ql <= mid) res = max(res, query_out(tr[p].ls, L, mid, ql, qr));
    if (qr > mid) res = max(res, query_out(tr[p].rs, mid + 1, R, ql, qr));
    return res;
}

int merge(int p, int q, int L, int R) {
    if (!p || !q) return p ? p : q;
    
    // If at a leaf, we don't update cross-paths because values are equal (not strictly increasing)
    if (L == R) {
        tr[p].max_in = max(tr[p].max_in, tr[q].max_in);
        tr[p].max_out = max(tr[p].max_out, tr[q].max_out);
        return p;
    }
    
    int mid = L + (R - L) / 2;
    
    // Check valid cross paths between the two different subtrees
    if (tr[p].ls && tr[q].rs) {
        if (tr[tr[p].ls].max_in > 0 && tr[tr[q].rs].max_out > 0) {
            global_ans = max(global_ans, tr[tr[p].ls].max_in + tr[tr[q].rs].max_out);
        }
    }
    if (tr[q].ls && tr[p].rs) {
        if (tr[tr[q].ls].max_in > 0 && tr[tr[p].rs].max_out > 0) {
            global_ans = max(global_ans, tr[tr[q].ls].max_in + tr[tr[p].rs].max_out);
        }
    }
    
    // Recursively merge children
    tr[p].ls = merge(tr[p].ls, tr[q].ls, L, mid);
    tr[p].rs = merge(tr[p].rs, tr[q].rs, mid + 1, R);
    
    // Push up the max values
    tr[p].max_in = max(tr[tr[p].ls].max_in, tr[tr[p].rs].max_in);
    tr[p].max_out = max(tr[tr[p].ls].max_out, tr[tr[p].rs].max_out);
    
    return p;
}

void dfs(int u, int p) {
    int in_u = 1;
    int out_u = 1;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        // Find best paths from the current child 'v'
        int best_in_C = query_in(root[v], 1, K, 1, mapped_val[u] - 1);
        int best_out_C = query_out(root[v], 1, K, mapped_val[u] + 1, K);
        
        // Update global answer for paths crossing through 'u'
        if (best_out_C > 0) global_ans = max(global_ans, in_u + best_out_C);
        if (best_in_C > 0) global_ans = max(global_ans, out_u + best_in_C);
        
        // Update the best paths ending/starting exactly at 'u'
        in_u = max(in_u, best_in_C + 1);
        out_u = max(out_u, best_out_C + 1);
        
        // Merge the child's segment tree into the parent's
        root[u] = merge(root[u], root[v], 1, K);
    }
    
    // Single node path edge case
    global_ans = max(global_ans, max(in_u, out_u));
    
    // Expose u's optimal sequences to the rest of the tree above it
    update(root[u], 1, K, mapped_val[u], in_u, out_u);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> n)) return 0;
    
    vector<int> vals(n);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        vals[i-1] = val[i];
    }
    
    // Coordinate compression to map large node values into [1, K]
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    K = vals.size();
    
    for (int i = 1; i <= n; i++) {
        mapped_val[i] = lower_bound(vals.begin(), vals.end(), val[i]) - vals.begin() + 1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Process the tree from an arbitrary root
    dfs(1, 0);
    
    cout << global_ans << "\n";
    
    return 0;
}