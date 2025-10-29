#include<bits/stdc++.h>
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
using namespace std;
long long tonguoc (int a)
{
    long long s=0,j;
    for (int i=1; i<=sqrt(a); i++)
    {
        if (a%i==0)
        {
            j=a/i;
            s=s+i;
            if (i!=j)
                s=s+j;
        }
    }
    return s;
}
long long tonguoc1 (int a)
{
    long long s=0,j;
    for (int i=1; i<=sqrt(a); i++)
    {
        if (a%i==0)
        {
            j=a/i;
            s=s+i;
            if (i!=j)
                s=s+j;
        }
    }
    return s;
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("NFRIENDS.INP","r",stdin);
    freopen("NFRIENDS.OUT","w",stdout);
    int n,ans=0;
    cin>>n;
    for (int i=0; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            if (tonguoc(i)-i==j&&tonguoc1(j)-j==i&&i!=j)
                {
                    ans++;
                }
        }
    }
    cout<<ans;
}
