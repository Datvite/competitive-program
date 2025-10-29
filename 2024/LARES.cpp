#include <bits/stdc++.h>
using namespace std;
long long m,n,k,dem=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("LARES.INP","r",stdin);
    freopen("LARES.OUT","w",stdout);
    cin>>m>>n>>k;
    if (m+k<=n||m/2<n)
        {
            dem=n-m/2;
            n=m/2;
        }
    else if (m+n+3<k)
        {
            cout<<0;
            return 0;
        }
    while (dem<k)
    {
        if (2*n>=m)
        {
            n--;
            dem++;
        }
        if (dem==k)
            break;
        if (2*n<m)
        {
            dem=dem+(m-2*n);
            m=2*n;
        }
    }
    if (2*n<=m)
        cout<<n;
    else
        cout<<m/2;
}
