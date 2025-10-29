#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],luu=LLONG_MAX,dem=0,gmax=LLONG_MIN;
map<long long,long long>m;
void sub1()
{
    for (int i=1; i<=n; i++)
    {
        dem=0;
        for (int j=1; j<=n; j++)
        {
            if (a[i]==a[j])
                dem++;
        }
        if (dem>=gmax&&a[i]<luu)
        {
            gmax=dem;
            luu=a[i];
        }
    }
    cout<<luu<<" "<<gmax;
}
void sub2()
{
    for (auto x : m)
    {
        if (x.second>gmax)
        {
            gmax=x.second;
            luu=x.first;
        }
    }
    cout<<luu<<" "<<gmax;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("20APM.INP","r",stdin);
    freopen("20APM.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    if (n<=1000)
    {
        sub1();
    }
    else
    {
        sub2();
    }
}
