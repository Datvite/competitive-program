#include <bits/stdc++.h>
using namespace std;
long long a,b,ans,k,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        if (a<b)
            swap(a,b);
        ans=__gcd(a,b);
        k=a*b/ans;
        k=k-a-b;
        if (a==b)
            cout<<a<<endl;
        else if (a%b==0)
            cout<<a-b<<endl;
        else
            cout<<k<<endl;
        }
}
