#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,m,k,q=0;
    cin>>n>>m;
    long long a[1000068],s[1000068],smin[1000068],f[1000068];
    s[0]=0;
    smin[0]=0;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            s[i]=a[i]+s[i-1];
            if (s[i]<smin[i-1])
                smin[i]=s[i];
            else
                smin[i]=smin[i-1];
                if (i>=m)
            f[i]=s[i]-smin[i-m];
        }
    long long maxv=LLONG_MIN;
    for (int i=m; i<=n; i++)
    {
        maxv=max(maxv,f[i]);
    }
    cout<<maxv;
}
