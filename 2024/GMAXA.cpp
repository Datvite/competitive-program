#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("GMAXA.INP","r",stdin);
    freopen("GMAXA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,minv=LLONG_MAX,t;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        if (t>0)
            minv=min(minv,t);
    }
    if (minv!=LLONG_MAX)
        cout<<minv;
    else
        cout<<0;
}
