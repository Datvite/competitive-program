#include <bits/stdc++.h>
using namespace std;
long long a[1000068],n,k,dem,ans,x,y,z;
map<int,int>b;
int main()
{
    freopen("LOTTERY.INP","r",stdin);
    freopen("LOTTERY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    cin>>x>>y;
    for (int i=1;i<=n;++i)
        {
        z=x;
        if (z%a[i]!=0&&z%a[i]>0)
            z=z+a[i]-x%a[i];
        else if (z%a[i]!=0&&z%a[i]<0)
            z=z-x%a[i];
        while (z<=y)
            {
                if (x!=0)
                b[z]++;
                z=z+a[i];
            }
        }
        for (int i=x;i<=y;++i)
        {
            if (b[i]==k)
                ans++;
        }
    cout<<ans;
}
