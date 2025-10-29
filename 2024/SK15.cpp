#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SK15.INP","r",stdin);
    freopen("SK15.OUT","w",stdout);
    long long n,q,k,a[1000068],dem=0,gmax=LLONG_MIN;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=q; i++)
    {
        gmax=LLONG_MIN;
        dem=0;
        cin>>k;
        for (int j=1; j<=n; j++)
        {
            gmax=max(gmax,dem);
            if (k>=a[j])
                dem++;
            else
                dem=0;
        }
        gmax=max(gmax,dem);
        cout<<gmax<<endl;
    }
}
