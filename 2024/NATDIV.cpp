#include <bits/stdc++.h>
using namespace std;
struct er
{
    long long gt1;
    long long gt2;
};
er a[1000000],s[1000000];
long long x,y,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("NATDIV.inp","r",stdin);
    freopen("NATDIV.out","w",stdout);
    for (long long i = 1; i <= 1000000; i++)
        for (long long j = i; j <= 1000000; j += i)
        {
            a[j].gt1=a[j].gt1+1;
            a[j].gt2=a[j].gt2+i;
        }
    s[0].gt1=0;
    s[0].gt2=0;
    for (int i=1; i<=1000000; i++)
    {
        s[i].gt1=s[i-1].gt1+a[i].gt1;
        s[i].gt2=s[i-1].gt2+a[i].gt2;
    }
    s[0].gt1=0;
    s[0].gt2=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x>>y;
        cout<<s[y].gt1-s[x-1].gt1<<' '<<s[y].gt2-s[x-1].gt2<<'\n';
    }
}
