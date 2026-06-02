#include <bits/stdc++.h>
using namespace std;
#define ii pair<ll, ll>
#define fi first
#define se second
const long N = 1e6 + 7;
char s[N];
int n, m, q, sum[N];
int query(int l, int r)
{
    if (sum[r] - sum[l - 1] <= m)
        return 0;
    int cnt = sum[r] - sum[l - 1], ans = 0;
    for (int i = l + 1; i <= r; i++)
    {
        if (s[i - 1] == 'L' && s[i + 1] == 'L' && s[i] == 'L')
        {
            cnt -= 2;
            s[i - 1] = s[i + 1] = 'D';
            ans++;
        }
        if (cnt <= m)
            return ans;
    }
    for (int i = l + 1; i <= r; i++)
    {
        if (s[i - 1] == 'L')
            for (int j = i; j <= r; j++)
            {
                if (s[j - 1] == 'L' && s[j + 1] == 'L' && s[j] == 'L')
                {
                    cnt -= 2;
                    s[j - 1] = s[j + 1] = 'D';
                    ans++;
                    // cout << j << endl;
                }
                while (s[j + 1] == 'L' && j < r)
                {
                    if (s[j - 1] == 'L' && s[j + 1] == 'L' && s[j] == 'L')
                    {
                        cnt -= 2;
                        s[j - 1] = s[j + 1] = 'D';
                        ans++;
                        // cout << j << endl;
                    }
                    j = j + 1;
                }
                if (s[j - 1] == 'L' && s[j + 1] == 'D' && s[j] == 'L')
                {
                    s[j - 1] = 'D';
                    s[j + 1] = 'L';
                    ans++;
                }
                if (j == r)
                {
                    if (s[j] == 'L' && s[j - 1] == 'L')
                    {
                        cnt -= 1;
                        s[j - 1] = 'D';
                        ans++;
                    }
                }

                if (cnt <= m)
                    return ans;
            }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("LEDST.INP", "r", stdin);
    freopen("LEDST.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] == 'L')
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}
/*
8 3
L L D L D L L L
3
3 5
2 7
1 8
*/
