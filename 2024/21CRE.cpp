#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],dem=0;
map<long long,long long>m;
void sub1()
{
    for (int i=1;i<=n;i++)
        {
            m[a[i]]++;
        }

    for (int i=1;i<=n;i++)
        {
            if (m[a[i]]>=1)
                {
                    dem++;
                    m[a[i]]=0;
                }
        }
    cout<<dem;
}
void sub2()
{
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        {
            if (a[i]!=a[i+1])
                {
                    dem++;
                }
        }
    cout<<dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("21CRE.INP","r",stdin);
    freopen("21CRE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    if (n<=100000)
        sub1();
    else
        sub2();
}
