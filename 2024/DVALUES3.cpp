#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DVALUES3.INP","r",stdin);
    freopen("DVALUES3.OUT","w",stdout);
    long long n,a[1000068];
    map<long long,long long>M;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        M[a[i]]++;
    }
    sort(a+1,a+n+1,greater<int>());
    int i=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!=a[i+1])
            cout<<a[i]<<" "<<M[a[i]]<<endl;
    }
}

