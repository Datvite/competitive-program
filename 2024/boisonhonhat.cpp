#include <bits/stdc++.h>
using namespace std;
long long n,m,s;
bool a[1000068];
void tachso()
{
    while (m>0)
    {
        a[m%10]=true;
        m=m/10;
    }
}
bool kc(long long k)
{
    int t;
    while (k>0)
        {
            t=k%10;
            if (a[t]==false)
                return false;
            k=k/10;
        }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LM.INP","r",stdin);
    freopen("LM.OUT","w",stdout);
    cin>>n>>m;
    tachso();
    s=n;
    while (kc(n)==false)
    {
        n=n+s;
    }
    cout<<n;
}
