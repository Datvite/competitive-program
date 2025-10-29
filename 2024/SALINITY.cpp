#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SALINITY.INP","r",stdin);
    freopen("SALINITY.OUT","w",stdout);
    long long a,b,c,x=0,y=0,t=0;
    cin>>a>>b>>c;
    if (a<c&&b<c||a>c&&b>c)
    {
        cout<<0;
        return 0;
    }
    if (a==c||b==c)
    {
        cout<<1;
        return 0;
    }
    x=c-b;y=a-c;
    t=__gcd(x,y);
    x=x/t;y=y/t;
    cout<<x+y;
}
