#include <bits/stdc++.h>
using namespace std;
long long a[100009], f[100009], KQ[100009];
int n, j;
vector<long long> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen("LIS.INP", "r"))
    {
        freopen("LIS.INP", "r", stdin);
        freopen("LIS.OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        j = lower_bound(KQ + 1, KQ + m + 1, a[i]) - KQ; // Tim vi tri dau tien KQ[j]>=a[i]
        if (j > m)
        {
            m++;
            KQ[m] = a[i];
            f[i] = m;
        }
        else
        {
            KQ[j] = a[i];
            f[i] = j;
        }
    }

    long long tmp = LLONG_MAX;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < tmp && f[i] == m)
        {
            ans.push_back(i);
            m--;
            tmp = a[i];
        }
    }
    reverse(ans.begin(), ans.end()); // Dao nguoc vector ket qua
    cout << ans.size() << '\n';
    for (auto t : ans)
    {
        cout << t << " ";
    }
}
