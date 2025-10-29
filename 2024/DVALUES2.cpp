#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("DVALUES2.INP","r",stdin);
    //freopen("DVALUES2.OUT","w",stdout);
    long long n;
    cin>>n;
    long long x[3000009];
    long long k[3000009];
    fill(k,k+n,0);
    for (int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for (int i=0;i<n;i++)
    {
        if (k[x[i]]==0)
            {
                cout<<x[i]<<" ";
            }
        k[x[i]]++;
    }
}
