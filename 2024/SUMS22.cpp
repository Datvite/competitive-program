#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SUMS22.INP","r",stdin);
    freopen("SUMS22.OUT","w",stdout);
    long long n,s,a[1000068],k,tong=0;
    map<long long,long long>m;
    cin>>n>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for (int i=1;i<=n;i++)
    {
        k=s-a[i];
        tong=tong+m[k];
    }
    cout<<tong/2;
}
