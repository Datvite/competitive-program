#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DVALUES1.INP","r",stdin);
    freopen("DVALUES1.OUT","w",stdout);
    long long n;
    cin>>n;
    long long x[3000009];
    long long k[3000009];
    fill(k,k+n,0);
    for (long long i=0;i<n;i++)
    {
        cin>>x[i];
    }
    sort(x,x+n,greater<int>());
    for (long long i=0;i<n;i++)
    {
        if (k[x[i]]==0)
            {
                cout<<x[i]<<" ";
            }
        k[x[i]]++;
    }
}
