#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DXB4.INP","r",stdin);
    freopen("DXB4.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,a[1000068],t=0,s=0;
    cin>>n;
    map<long long,long long>m;
    m[0]=1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]%2==0)
            t++;
        else
            t--;
        s=s+m[t];
        m[t]++;

    }
    cout<<s;
}
