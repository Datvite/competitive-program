#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int INF = 2e18;

struct Node {
    int sum;
    int mx1, mx2, cnt;
};

int n, q;
vector<int> a;
vector<Node> st;
vector<int> lazy_add;

void merge_node(int id) {
    int lc = id << 1, rc = id << 1 | 1;
    st[id].sum = st[lc].sum + st[rc].sum;

    if (st[lc].mx1 == st[rc].mx1) {
        st[id].mx1 = st[lc].mx1;
        st[id].cnt = st[lc].cnt + st[rc].cnt;
        st[id].mx2 = max(st[lc].mx2, st[rc].mx2);
    } else if (st[lc].mx1 > st[rc].mx1) {
        st[id].mx1 = st[lc].mx1;
        st[id].cnt = st[lc].cnt;
        st[id].mx2 = max(st[lc].mx2, st[rc].mx1);
    } else {
        st[id].mx1 = st[rc].mx1;
        st[id].cnt = st[rc].cnt;
        st[id].mx2 = max(st[lc].mx1, st[rc].mx2);
    }
}

void apply_add(int id, int l, int r, int val) {
    st[id].sum += val * (r - l + 1);
    st[id].mx1 += val;
    if (st[id].mx2 != -INF) st[id].mx2 += val;
    lazy_add[id] += val;
}

void apply_min(int id, int x) {
    if (x >= st[id].mx1) return;
    st[id].sum -= (st[id].mx1 - x) * st[id].cnt;
    st[id].mx1 = x;
}

void push(int id, int l, int r) {
    int mid = (l + r) >> 1;
    int lc = id << 1, rc = id << 1 | 1;

    if (lazy_add[id] != 0) {
        apply_add(lc, l, mid, lazy_add[id]);
        apply_add(rc, mid + 1, r, lazy_add[id]);
        lazy_add[id] = 0;
    }

    apply_min(lc, st[id].mx1);
    apply_min(rc, st[id].mx1);
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l], a[l], -INF, 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    merge_node(id);
}

void update_add(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        apply_add(id, l, r, val);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update_add(id << 1, l, mid, u, v, val);
    update_add(id << 1 | 1, mid + 1, r, u, v, val);
    merge_node(id);
}

void update_min(int id, int l, int r, int u, int v, int x) {
    if (v < l || r < u || st[id].mx1 <= x) return;
    if (u <= l && r <= v && st[id].mx2 < x) {
        apply_min(id, x);
        return;
    }
    push(id, l, r);
    int mid = (l + r) >> 1;
    update_min(id << 1, l, mid, u, v, x);
    update_min(id << 1 | 1, mid + 1, r, u, v, x);
    merge_node(id);
}

int query_sum(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].sum;
    push(id, l, r);
    int mid = (l + r) >> 1;
    return query_sum(id << 1, l, mid, u, v) + query_sum(id << 1 | 1, mid + 1, r, u, v);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    a.resize(n + 1);
    st.resize(4 * n + 5);
    lazy_add.assign(4 * n + 5, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 0) {
            cin >> x;
            update_min(1, 1, n, l, r, x);
        } else if (op == 1) {
            cin >> x;
            update_add(1, 1, n, l, r, x);
        } else {
            cout << query_sum(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}