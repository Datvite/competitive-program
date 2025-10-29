#include <bits/stdc++.h>
using namespace std;
long long n,s[1000067],gmax[1000067],gmin[1000067],h,maxv=LLONG_MIN;
struct vt
{
    long long kt;
    long long gt;
};
vt a[1000067];
bool cm(vt a,vt b)
{
    return a.kt<b.kt||a.kt==b.kt&&a.gt>b.kt;
}
void sub1()
{
    for (int i=1; i<n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            h=(s[j]-s[i-1])-(a[j].kt-a[i].kt);
            maxv=max(maxv,h);
        }
    }
    cout<<maxv;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("21PIC.INP","r",stdin);
    //freopen("21PIC.OUT","w",stdout);
    cin>>n;
    s[0]=0;
    gmin[0]=LLONG_MAX;
    gmax[0]=LLONG_MIN;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].kt>>a[i].gt;
    }
    sort (a+1,a+n+1,cm);
   for (int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+a[i].gt;
    }
    if (n!=1)
        sub1();
    else
        cout<<a[1].gt;
}
