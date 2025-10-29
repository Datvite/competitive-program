#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SSDIV3.INP","r",stdin);
    freopen("SSDIV3.OUT","w",stdout);
    long long n,a[1000068],tong=0;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (a[i]%2!=0&&a[i]%3==0)
                tong=tong+a[i];
        }
    cout<<tong;
}
