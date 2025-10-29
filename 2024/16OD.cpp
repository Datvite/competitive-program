#include <bits/stdc++.h>
using namespace std;
long long n,dem=0,gmax=0,a[1000068],luu=0;
void sub1()
{
    a[n+1]=2;
    for (int i=1; i<=n+1; i++)
    {
        if (a[i]>0&&a[i]%2!=0)
            dem++;
        else
            dem=0;
        if (dem>gmax)
        {
            gmax=dem;
            luu=i-dem+1;
        }
    }
    cout<<gmax<<endl<<luu;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("16OD.INP","r",stdin);
    freopen("16OD.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sub1();
}
