#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
int n,x,y,ans,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
     for (int i=1;i<=n;++i)
        {
            cin>>x>>y;
            j=1;
            ans=0;
            while (j*j<=y)
                {
                    ans=ans+(int)((y)/(j*j)-(x-1)/(j*j));
                    j++;
                }
            cout<<ans<<endl;
        }

}
