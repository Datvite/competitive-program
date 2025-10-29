#include<bits/stdc++.h>
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define fi first
#define se second
using namespace std;
long long n,dem=1,maxn=LLONG_MIN;
struct gg
{
    long long first;
    long long second;
};
gg a[1000068];
bool check(gg a,gg b)
{
    return a.fi<b.fi;
}
int main()
{
    file("SLINE")
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].fi>>a[i].se;
    }
    sort(a+1,a+n+1,check);
    long long l=a[1].fi;
    long long r=a[1].se;
    for (int i=2; i<=n; i++)
    {
        if (a[i].fi<=r)
            {
                if (a[i].se>r)
                r=a[i].se;
            }
        else
        {
            l=a[i].fi;
            r=a[i].se;
        }
        maxn=max(maxn,r-l);
    }
    maxn=max(maxn,r-l);
    cout<<maxn;
}
