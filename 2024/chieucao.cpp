#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if (n==0)
        {
            cout<<m;
            return 0;
        }
    k=abs(n%m);
    ans=n+k;
    if (ans%m==0)
        cout<<ans;
    else
    {
        n=abs(n);
        m=abs(m);
        k=m-abs(n%m);
        ans=n+k;
        cout<<ans;
    }
}
