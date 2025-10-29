#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("S02.INP","r",stdin);
    freopen("S02.OUT","w",stdout);
    long long n,m,t;
    cin>>n>>m;
    long long a[1000068];
    for (int i=1;i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=m; i++)
    {
        long long t;
        cin>>t;
        auto c=lower_bound(a+1,a+n+1,t);
        if (*c>=t)
                cout<<*c<<endl;
            else
                cout<<"NO";
    }
}
