#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;

const int N = 999;
long long dp[19][136][1005], trace[19][136][1005], tcs[N + 1], pw[19];

void createdp() {
    pw[0] = 1;
    for (int i = 1; i <= 18; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    for (int i = 0; i <= N; i++) {
        int res = i, T = 0;
        while (res) {
            T += res % 10;
            res /= 10;
        }
        tcs[i] = T;
    }
    for (int i = 3; i <= 18; i++) {
        if (i == 3) {
            for (int j = 0; j <= 162 - 9 * i; j++) {
                for (int k = N; k >= 0; k--) {
                    if ((N - k) - j - tcs[N - k] < 0) {
                        dp[i][j][k] = 1;
                        trace[i][j][k] = -((N - k) - j - tcs[N - k]);
                    } else {
                        dp[i][j][k] = dp[i][j][N - ((N - k) - j - tcs[N - k])] + 1;
                        trace[i][j][k] = trace[i][j][N - ((N - k) - j - tcs[N - k])];
                    }
                }
            }
        } else {
            for (int j = 0; j <= 162 - 9 * i; j++) {
                for (int k = 0; k <= 171 - 9 * i; k++) {
                    long long trc = k + 1, res = 0;
                    for (int l = 9; l >= 0; l--) {
                        res += dp[i - 1][j + l][trc - 1];
                        trc = trace[i - 1][j + l][trc - 1];
                    }
                    dp[i][j][k] = res;
                    trace[i][j][k] = trc;
                }
            }
        }
    }
}

long long gettcs(long long n) {
    long long ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

long long getans(long long n) {
    int k = 3;
    long long ans = 0;
    while (n) {
        long long x = n % pw[k + 1] / pw[k];
        for (int i = 0; i <= x; i++) {
            long long z = gettcs(n / pw[k]);
            ans += dp[k][z][pw[k] - n % pw[k] - 1];
            n = n - n % pw[k] - trace[k][z][pw[k] - n % pw[k] - 1];
        }
        k++;
    }
    return ans - 1;
}

int main() {
        cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    createdp();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << getans(n) << " ";
    }
    cout << endl;
}
