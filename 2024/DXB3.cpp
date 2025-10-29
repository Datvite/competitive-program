#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DXB3.INP","r",stdin);
    freopen("DXB3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,t,gmax=LLONG_MIN,luu=LONG_MAX;
    cin>>n;
    map<long long,long long>m;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        m[t]++;
        if (m[t]>gmax)
        {
            luu=t;
            gmax=max(gmax,m[t]);
        }
        if (m[t]==gmax&&t<luu)
            {
                luu=t;
                gmax=max(gmax,m[t]);
            }
    }
    cout<<luu;
}
