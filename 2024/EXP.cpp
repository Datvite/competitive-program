#include <bits/stdc++.h>
using namespace std;
long long n,a,b,ans,maxn=LLONG_MAX;
long long check(long long a,long long b)
{
    long long s=0,d=b;
    while (a>=d)
    {
        s=s+a/d;
        d=d*b;
    }
    return s;
}
long long check2(long long a,long long b)
{
    long long minn=LLONG_MAX,dem,k=sqrt(b);
    for (int i=2; i<=k; ++i)
    {
        dem=0;
        while (b%i==0)
        {
            dem++;
            b=b/i;
        }
        if (dem>=1)
            minn=min(minn,check(a,i)/dem);
    }
    if (b>=2)
        minn=min(minn,check(a,b));
    return minn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        {
        cin>>a>>b;
        cout<<check2(a,b)<<endl;
    }
}

