#include<bits/stdc++.h>
using namespace std;
long long x,n,m,s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(cin>>x>>n>>m)
    {
        s=1;
        for(long long i=1;i<=n;i++)
        {
            s=s*x%m;
        }
        cout<<s%m<<'\n';
    }
}
