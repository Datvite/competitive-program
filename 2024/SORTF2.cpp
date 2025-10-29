#include<bits/stdc++.h>
using namespace std;
struct pta
{
    long long gt;
    int vt;
};
pta a[3000009];
bool cmp (pta x,pta y)
    {
        if (x.gt<y.gt)
            return true;
        if (x.gt==y.gt&&x.vt<y.vt)
            return true;
        return false;
    }
bool cmp2 (pta x,pta y)
    {
        if (x.gt>y.gt)
            return true;
        if (x.gt==y.gt&&x.vt<y.vt)
            return true;
        return false;
    }
int main()
{
    freopen("SORTF2.INP","r",stdin);
    freopen("SORTF2.OUT","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i].gt;
            a[i].vt=i;
        }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (a[i].gt%2==0)
            cout<<a[i].vt<<" ";
    }
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=n;i++)
    {
        if (a[i].gt%2!=0)
            cout<<a[i].vt<<" ";
    }
}
