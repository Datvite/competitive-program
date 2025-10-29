#include<bits/stdc++.h>
using namespace std;
struct tv
{
    long long so, benhat;
};
tv a[1000068];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DIFT15.INP","r",stdin);
    freopen("DIFT15.OUT","w",stdout);
    long long n,gmin=LLONG_MAX,gmax=LLONG_MIN,k;
    cin>>n;
    a[0].benhat=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i].so;
        if (a[i].so<gmin)
        {
                a[i].benhat=a[i].so;
                gmin=a[i].so;
        }
        else
        {
            a[i].benhat=a[i-1].benhat;
        }
    }
    for (int i=1; i<=n; i++)
    {
        k=a[i].so-a[i].benhat;
        if (k>gmax)
            gmax=k;
    }
    cout<<gmax;
}
