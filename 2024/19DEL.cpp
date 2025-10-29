#include <bits/stdc++.h>
using namespace std;
long long n,b,a[1000068],m,gmin=LLONG_MAX,gmax=LLONG_MIN;
void sub1()
{
    sort(a+1,a+n+1);
    for (int i=b+1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if (j!=i)
                    m=abs(a[j]-a[i]);
                gmax=max(gmax,m);
                gmin=min(gmin,m);
            }
        }
    cout<<gmax+gmin;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin>>n>>b;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sub1();
}
