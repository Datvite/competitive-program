#include <bits/stdc++.h>
#define s ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

ll n, a[1000006], sum[1000006];
pair<int, int> f[1004];

int main() {
    s;
    cin >> n;
    ll m = LLONG_MIN, l = 0;
    sum[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        if (f[a[i]].first == 0) f[a[i]].first = i;
        f[a[i]].second = i;
    }

    for (int i = 0; i < 1004; i++) {
        if (f[i].first != 0) {
            ll k = f[i].second - f[i].first + 1;
            ll t = sum[f[i].second] - sum[f[i].first - 1];

            if (k >= l && t > m) {
                m = t;
                l = k;
            }
        }
    }

    cout << l << " " << m << endl;

}
