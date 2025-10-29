#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SUBZERO.INP","r",stdin);
    freopen("SUBZERO.OUT","w",stdout);
    long long n;
    long long a[1000068],s[1000068],l=0,r=0;
    cin>>n;
    s[0]=0;
    map<long long,long long>md;
    map<long long,long long>mc;
    md[0]=0;
    mc[0]=0;
    for (long long i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if (md[s[i]]==0&&s[i]!=0)
            md[s[i]]=i;
        mc[s[i]]=i;
        if (mc[s[i]]-md[s[i]]>r-l)
        {
            l=md[s[i]];
            r=mc[s[i]];
        }
        if (mc[s[i]]-md[s[i]]==r-l&&l>md[s[i]])
        {
            l=md[s[i]];
            r=mc[s[i]];
        }
    }
    if (l!=0||r!=0)
        cout<<l+1<<" "<<r;
    else
        cout<<0;
}
