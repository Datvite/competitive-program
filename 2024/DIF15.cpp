#include<bits/stdc++.h>
using namespace std;
long long a[1000068];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DIF15.INP","r",stdin);
    freopen("DIF15.OUT","w",stdout);
    long long n,gmin=LLONG_MIN,gmax=LLONG_MIN,k;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=n; i>=1; i--)
    {

        if (a[i]>gmin)
            gmin=a[i];
        else
           {
               k=gmin-a[i];
               gmax=max(gmax,k);
           }
    }
    cout<<gmax;
}
