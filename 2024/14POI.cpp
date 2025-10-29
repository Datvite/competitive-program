#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],b[1000068],k,m=1,t=1,gmin,s=0;
char v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("14POI.INP","r",stdin);
    freopen("14POI.OUT","w",stdout);
    cin>>n;
    int i=1;
    while (i<=2*n)
        {
            cin>>v>>k;
            if ((int)v==66)
                {
                    a[m]=k;
                    m++;
                }
            else
                {
                    b[t]=k;
                    t++;
                }
            i++;
        }
    sort (a+1,a+m);
    sort (b+1,b+t);
    gmin=min(m,t);
    i=1;
    while (i<=gmin)
        {
            if (a[1]>=b[1])
                s=s+a[i]-b[i];
            else
                s=s-a[i]+b[i];
            i++;
        }
    cout<<s;
}
