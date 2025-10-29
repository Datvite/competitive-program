#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
const int MOD = 123456789;
int n, x;
int a[N];
void solve(){
    cin >> n >> x;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 0, md=1e7*MOD;
    for (int i = 0; i < n; i++) {
        res += a[0] + ((a[i] - a[0] + x - 1) / x) * x - a[i];
    }
    cout << res << '\n';
}
int32_t main(){
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(fopen(task "TRIP.inp", "r"))
        {
            freopen(task "TRIP.inp", "r", stdin);
            freopen(task "TRIP.out", "w", stdout);
        }
    }
    solve();
}
