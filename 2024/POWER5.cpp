#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("POWER5.INP","r",stdin);
    freopen("POWER5.OUT","w",stdout);
    long long x,n,m,s;
    cin>>x>>n>>m;
    s=x;
    x=x%10;
    for (long long i=2;i<=n;i++)
        {
            x=x*s;
            x=x%10;
        }
    cout<<x%m;
}
