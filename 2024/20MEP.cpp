#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],s=0,k=1;
void sub1()
{
    long long l=n;
    sort(a+1,a+n+1);
    for (int i=1;i<=2;i++)
        {
            if (a[k]*a[k+1]>a[l]*a[l-1])
                {
                    s=s+a[k]*a[k+1];
                    k=k+2;
                }
            else
                {
                    s=s+a[l]*a[l-1];
                    l=l-2;
                }
        }
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("20MEP.INP","r",stdin);
    freopen("20MEP.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sub1();
}
