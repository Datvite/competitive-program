#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define N 1000068
#define for(i,l,r) for (long long i=l;i<=r;i++)
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
long long n,m;
long long b[N],ans=0,ans1=0,a1,id=0;
struct vt
{
    long long vt,gt;
};
vt a[N];
int main()
{
    skibidi;
    file("SWMIN2");
    cin>>n;
    for(i,1,n)
    {
        cin>>a[i].gt;
        a[i].vt=i;
    }
    a1=a[1].gt;
    for(i,1,n)
        if (a[i].gt>a[1].gt)
        {
            ans++;
            b[id]=i;
            id++;
        }
    if (ans!=0)
    {
        swap(a[1],a[ans+1]);
        ans1=1;
    }
    /*else
    {
        cout<<0<<endl;
        for(i,1,n)
            cout<<a[i].vt<<" ";
        return 0;
    }*/
    id--;
    for(i,1,ans)
        if (a[i].gt<=a1)
        {
            ans1++;
            swap(a[i],a[b[id]]);
            id--;
        }
    cout<<ans1<<endl;
    for(i,1,n)
        cout<<a[i].vt<<" ";
}
/*
4
5 3 4 6
*/
