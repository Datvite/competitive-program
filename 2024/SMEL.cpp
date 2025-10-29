#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define N 1000068
#pragma GCC optimize(3)
using namespace std;
long long n,m;
long long a[1000068],b[1000068],c[1000068];
void sub1()
{
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
    long long ans;
    sort (b+1,b+n+1);
    for (int i=1;i<=n;i++)
        {
            ans=lower_bound(b+1,b+n+1,a[i])-b-1;
            cout<<ans<<"\n";
        }
}
void sub2()
{
    long long maxn=LLONG_MIN;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
            maxn=max(maxn,a[i]);
        }
    c[0]=0;
    for (int i=1;i<=maxn;i++)
        {
            c[i]=c[i-1]+b[i-1];
        }
    long long ans;
    for (int i=1;i<=n;i++)
        {
            cout<<c[a[i]]<<"\n";
        }
}
int main()
{
    skibidi;
    file("SMEL");
    cin>>n;
    if (n<=1e5)
        sub1();
    else
        sub2();
}
