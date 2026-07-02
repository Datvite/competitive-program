#include <bits/stdc++.h>
using namespace std;

struct State {
    int a, b, c;   // amounts in jug 0,1,2
    int dist;
    State(int a_, int b_, int c_, int d) : a(a_), b(b_), c(c_), dist(d) {}
};

/* returns amount to pour from src to dest according to the rules;
   returns 0 if nothing can be poured (should be ignored by caller). */
int pourAmount(int src, int dest, const vector<int>& mark, int V) {
    if (src == 0) return 0;               // nothing to pour
    int maxPour = min(src, V - dest);     // cannot exceed source or dest capacity
    int best = maxPour;                   // pour as much as possible (until one limit hits)

    // source marks: we can stop when src level equals a mark
    for (int p : mark) {
        if (p < src) {                     // mark below current level
            int need = src - p;            // amount to pour to reach that mark
            if (need <= maxPour)
                best = min(best, need);
        }
    }

    // destination marks: we can stop when dest level equals a mark
    for (int p : mark) {
        if (p > dest) {                    // need to raise dest to this mark
            int need = p - dest;
            if (need <= maxPour)
                best = min(best, need);
        }
    }

    // best is the amount we will pour; if it is zero, no valid pour.
    return best;
}

int solve() {
    int n, V, M;
    if (!(cin >> n >> V >> M)) return 0;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // Trivial cases
    if (M == 0) { cout << 0 << '\n'; return 0; }   // jug 2 or 3 already empty
    if (M == V) { cout << 0 << '\n'; return 0; }   // jug 1 already full

    const int MAX = V;
    vector<vector<vector<bool>>> vis(MAX+1, vector<vector<bool>>(MAX+1, vector<bool>(MAX+1, false)));
    queue<State> q;
    q.emplace(V, 0, 0, 0);
    vis[V][0][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        int a = cur.a, b = cur.b, c = cur.c, d = cur.dist;

        // check goal
        if (a == M || b == M || c == M) {
            cout << d << '\n';
            return 0;
        }

        int arr[3] = {a, b, c};
        // try all ordered pairs i -> j, i != j
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) continue;
                int src = arr[i];
                int dst = arr[j];
                int amount = pourAmount(src, dst, p, V);
                if (amount <= 0) continue;   // nothing changes
                int ns = src - amount;
                int nd = dst + amount;
                int na[3] = {a, b, c};
                na[i] = ns;
                na[j] = nd;
                if (!vis[na[0]][na[1]][na[2]]) {
                    vis[na[0]][na[1]][na[2]] = true;
                    q.emplace(na[0], na[1], na[2], d+1);
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}