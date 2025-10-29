#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,ans,n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        ans=(a-b%a)%a;
        for (int j=2;j*j<=a;j++)
        {
            if (a%j==0)
            {
                ans=min(ans,(j-b%j)%j);
                int k=a/j;
                ans=min(ans,(k-b%k)%k);
            }
        }
        cout<<ans<<endl;
    }
}
