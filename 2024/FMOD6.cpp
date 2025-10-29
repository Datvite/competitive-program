#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("FMOD6.INP","r",stdin);
    //freopen("FMOD6.OUT","w",stdout);
    long long f[1000068];
    long long n,m,t=2,s;
    cin>>n>>m;
    f[0]=0;
    f[1]=1;
    f[2]=1;
    while (1==1)
    {
        t++;
        f[t]=(f[t-1]+f[t-2])%m;
        if (f[0]==f[t-2]&&f[1]==f[t-1]&&f[2]==f[t])
            break;

    }
    s=n%m;
    cout<<f[s];
}
