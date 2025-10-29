#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SORTMER.INP","r",stdin);
    freopen("SORTMER.OUT","w",stdout);
    long long m,n,d,a[1000068],b[1000068],x,y;
    map<long long,long long>c;
    cin>>m>>n;
    d=m+n;
    x=1;y=1;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for (long long i=1;i<=d+1;i++)
    {
            if (a[x]<b[y]&&x<=m)
                {
                    c[i]=a[x];
                    x++;
                }
            else if (a[x]>b[y]&&y<=n)
                {
                    c[i]=b[y];
                    y++;
                }
            else
                {
                    c[i]=b[y];
                    y++;
                }
        }
        d=m+n;
        for (long long i=1;i<=d;i++)
            cout<<c[i]<<" ";
}
