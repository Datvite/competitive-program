#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("EXP12.INP","r",stdin);
    freopen("EXP12.OUT","w",stdout);
    long long n,a[1000068],k,tong=0;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort (a+2,a+n+1,greater<long long>());
    tong=a[1];
    for (int i=2;i<=n;i++)
        {
            if (k>0)
            {
                tong=tong+a[i];
                k--;
            }
            else
            {
                   tong=tong-a[i];
            }
        }
    cout<<tong;
}
