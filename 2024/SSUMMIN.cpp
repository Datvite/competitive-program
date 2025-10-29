#include<bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N=1000068;
ll n,k,m=LLONG_MIN;
ll a[N],s[N],g[N];
void f()
{
    long long i=g[n],j=n;
    while(i>=0)
    {
        while(i<=j&&s[j]-s[i]<0)
        {
            j--;
        }
        m=max(m,j-i);
        if(i==0)break;
        i=g[i-1];
    }
    if(m!=LLONG_MIN)
        cout<<m<<"\n";
    else
        cout<<0<<"\n";
}
int main()
{
    skibidi
    file("AVER")
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]-=k;
    }
    for(int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(s[i]<s[g[i-1]])
            g[i]=i;
        else
            g[i]=g[i-1];
    }
    f();
    return 0;
}
