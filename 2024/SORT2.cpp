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
int main()
{
    //freopen("SORT2.INP","r",stdin);
    //freopen("SORT2.OUT","w",stdout);
    int i=0;
    int t,n;
    while (cin>>t)
    {
        i++;
        a[i].gt=t;
        a[i].vt=i;
    }
    n=i;
    sort (a+1,a+n+1,cmp);
    for (int k=1;k<=n;k++)
    {
        cout<<a[k].vt<<" ";
    }
}
