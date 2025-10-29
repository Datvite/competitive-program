#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define endl "\n"
using namespace std;
ll n,k,a[1000068],dem=0,sum[1000068];
void sub1()
{
    sum[0]=0;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
    for (int i=1; i<=n; i++)
        {
            for(int j=1;j<=i;j++)
                {
                    if ((sum[i]-sum[j-1])%k==0)
                        dem++;
                }
        }
    cout<<dem;
}
void sub2()
{
    ll m[1000068];
    sum[0]=0;
    m[0]=1;
    for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            ll x=sum[i]%k;
            if (m[x]>0)
                dem+=m[x];
            m[x]++;
        }
    cout<<dem;
}
int main()
{
    skibidi;
    file("CSDK")
    cin>>n>>k;
    if (n<=1e3)
        sub1();
    else
        sub2();

}
/*
4 2
2 2 2 2
*/
