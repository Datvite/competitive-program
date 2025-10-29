#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define N 2000000
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
struct vyy
{
    long long fi;
    int se;
};
bool cm(vyy a,vyy b)
{
    return a.fi>=b.fi;
}
vyy a[N];
long long n,m;
int main()
{
    skibidi;
    file("BALL");
    cin>>n>>m;

    for (int i=1; i<=n; ++i)
    {
        cin>>a[i].fi;
        a[i].se=1;
    }
    for (int i=n+1; i<=n+m; ++i)
    {
        cin>>a[i].fi;
        a[i].se=0;
    }
    sort(a+1,a+n+m+1,cm);
    long long demdo=0,demxanh=0,ans=0;
    for (int i=1; i<=n+m; ++i)
    {
        if (a[i].se==0)
        {
            if (demdo>=1&&demxanh>=1)
            {
                demdo+=1;
                demdo-=2;
                demxanh-=1;
                ans++;
            }
            else
                demdo++;
        }
        if (a[i].se==1&&demdo>=1)
            demxanh++;
    }
    cout<<ans;
}
