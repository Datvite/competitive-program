#include<bits/stdc++.h>
using namespace std;
long long tachso(long long n)
{
    int t=0;
    while (n>0)
    {
        t=t+n%10;
        n=n/10;
    }
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SLQ.INP","r",stdin);
    freopen("SLQ.OUT","w",stdout);
    long long n,x,m,v,minv=LLONG_MAX,luu=0;
    cin>>n;
    for (long long i=1; i<=1000;i++)
    {
        m=(pow(i,2)+(4*n));
        v=sqrt(m);
        if (v*v==m)
        {
            if ((v-i)%2==0&&(v-i)>=0)
            {
                x=(v-i)/2;
                  if (tachso(x)==i)
                      {
                          minv=min(x,minv);
                          luu=1;
                      }
            }
        }
    }
    if (luu!=0)
        cout<<minv;
    else
        cout<<-1;
}
