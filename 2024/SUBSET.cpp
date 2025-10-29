#include <bits/stdc++.h>
using namespace std;
long long n, k, a[1000068], i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        a[i] = i;
        cout << a[i] << " ";
    }
    cout << endl;
    i = k;
    while (true)
    {
        i = k;
        while (a[i] == n - k + i)
        {
            i--;
        }
        if (i < 1)
            return 0;
        if (a[i] < n - k + i)
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
            for (int j = 1; j <= k; j++)
                cout << a[j] << " ";
            cout << endl;
        }
    }
}
