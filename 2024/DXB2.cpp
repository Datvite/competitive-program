#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("DXB2.INP","r",stdin);
    freopen("DXB2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,t,gmax=LLONG_MIN,luu=0;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>t;
        if (t<0&&t>gmax)
        {
            gmax=t;
            luu=i;
        }
    }
    if (luu!=0)
        cout<<luu;
    else
        cout<<-1;
}
