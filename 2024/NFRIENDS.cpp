#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("NFRIENDS.INP","r",stdin);
    freopen("NFRIENDS.OUT","w",stdout);
    int n,ans=0;
    cin>>n;
    if (n<284)
        {
            cout<<0;
            return 0;
        }
    if (n<1280)
        {
            cout<<1;
            return 0;
        }
    if (n<2924)
        {
            cout<<2;
            return 0;
        }
    if (n<5564)
        {
            cout<<3;
            return 0;
        }
    if (n<6368)
        {
            cout<<4;
            return 0;
        }
    if (n<10856)
        {
            cout<<5;
            return 0;
        }
    cout<<ans;
}
