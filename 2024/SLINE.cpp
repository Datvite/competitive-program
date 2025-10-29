
#include<bits/stdc++.h>
using namespace std;
struct pta
{
    int dau;
    int cuoi;
};
pta a[300009],b[300009];
bool cmp (pta x,pta y)
    {
        if (x.dau<y.dau)
            return true;
        return false;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SLINE.INP","r",stdin);
    freopen("SLINE.OUT","w",stdout);
    int n,t,gmax=0,g;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t>>g;
        a[i].dau=t;
        a[i].cuoi=g;
    }
    sort(a+1,a+n+1,cmp);
    int l=a[1].dau,r=a[1].cuoi;
    for (int i=2;i<=n;i++)
    {
        if (a[i].dau<=r)
            {
                if (a[i].cuoi>r)
                r=a[i].cuoi;
            }
        else
        {
            l=a[i].dau;
            r=a[i].cuoi;
        }
        if (r-l>gmax)
                gmax=r-l;
    }
    if (r-l>gmax)
                gmax=r-l;
    cout<<gmax;
}
