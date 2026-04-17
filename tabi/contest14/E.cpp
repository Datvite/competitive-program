#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<int,3>> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        queries[i][0]--; queries[i][1]--;
    }

    vector<int> a(n, 0);

    // Xử lý từng bit
    for (int bit = 0; bit < 30; bit++) {
        vector<int> diff(n + 1, 0);

        for (auto &q : queries) {
            int l = q[0], r = q[1], val = q[2];
            if (val & (1 << bit)) {
                diff[l]++;
                diff[r + 1]--;
            }
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            if (cur > 0) a[i] |= (1 << bit);
        }
    }

    // Kiểm tra lại
    for (auto &q : queries) {
        int l = q[0], r = q[1], val = q[2];
        int cur = a[l];
        for (int i = l + 1; i <= r; i++) {
            cur &= a[i];
        }
        if (cur != val) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
