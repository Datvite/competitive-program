#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("DISNUM3.INP","r",stdin);
    freopen("DISNUM3.OUT","w",stdout);
    long long n,a[300000],gmax=0,nho;
    map<long long,int>M;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        M[a[i]]++;
    }
    for (auto x:M)
    {
        if (x.second>gmax)
        {
            gmax=x.second;
            nho=x.first;
        }
    }
    cout<<nho<<" "<<gmax;
}

