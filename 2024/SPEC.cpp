#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SPEC.INP","r",stdin);
    freopen("SPEC.OUT","w",stdout);
    long long n,d=0,maxv=LLONG_MIN,luu=1,t;
    cin>>n;
    for (long long i=1; i<=n; i++)
    {
        cin>>t;
        if (t>0)
        {
            if (t*luu>0)
            {
                d++;
                luu=t;
                maxv=max(maxv,d);
            }
            else
            {
                d=1;
                luu=t;
                maxv=max(maxv,d);
            }
        }
        else
        {
            if (t*luu>0)
            {
                d++;
                luu=t;
                maxv=max(maxv,d);
            }
            else
            {
                d=1;
                luu=t;
                maxv=max(maxv,d);
            }
        }
    }
    cout<<maxv;
}
