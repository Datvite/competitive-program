#include <bits/stdc++.h>
using namespace std;
long long z,n,m,k,dem;
unsigned long long ans;
string a,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("FOLDING.INP","r",stdin);
    //freopen("FOLDING.OUT","w",stdout);
    cin>>k>>n>>m;
    z=m-n;
    ans=pow(2,1);
    while (m>10000)
    {
        while (m>ans)
        {
            ans=ans*2;
        }
        ans=ans/2;
        if (ans>n&&m>ans)
        {
            dem++;
        }
        ans=m-ans;
        ans=ans*2;
        if (m-ans<=0)
            break;
        m=m-ans;
        n=m+z;
        swap(m,n);
    }
cout<<m<<n;
}
