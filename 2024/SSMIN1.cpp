#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("SSMIN1.INP","r",stdin);
    //freopen("SSMIN1.OUT","w",stdout);
    int n;
    long long minn=LLONG_MAX,sum=0;
    cin>>n;
    int a[1000000];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        sum=sum+a[i];
        minn=min(minn,sum);
        if (sum>0)
            sum=0;
    }
    cout<<minn;
}
