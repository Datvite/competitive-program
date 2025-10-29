#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("INSULT.INP","r",stdin);
    freopen("INSULT.OUT","w",stdout);
    int n,a[1000009],dem=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++)
    {
        dem=dem+a[i];
    }
    for (int i=1; i<=n/2; i++)
    {
        dem=dem+(a[n-i+1]-a[i]);
    }
    cout<<dem;
}
