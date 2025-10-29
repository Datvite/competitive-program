#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SD1EQ.INP","r",stdin);
    freopen("SD1EQ.OUT","w",stdout);
    int n;
    cin>>n;
    int a[3000000];
    long long tong=0;
    long long maxv=LLONG_MIN;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
            {
                tong=tong+a[j];
                maxv=max(maxv,tong);
            }
            tong=0;
    }
    cout<<maxv;
}
