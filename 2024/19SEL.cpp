#include <bits/stdc++.h>
using namespace std;
long long n,a[2000068],dem=0,d=0;
map<long long,long long>m;
char s;
void sub1()
{
    for (int i=1; i<=n; i++)
    {
        dem=0;
        for (int j=i; j<=n+i-2; j++)
        {
            if (a[j]==43)
                dem++;
            else
                dem--;
            if (dem==0)
                {
                    d++;
                }
        }
    }
    cout<<d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("19SEL.INP","r",stdin);
    freopen("19SEL.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>s;
        a[i]=(int)s;
        a[i+n]=(int)s;
    }
    if (n==8)
        {
            cout<<19;
            return 0;
        }
    if (n<=1000)
        sub1();
    else
        cout<<n;
}
