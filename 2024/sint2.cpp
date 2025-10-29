#include <bits/stdc++.h>
using namespace std;
long long a,ans,b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    if (a<0&&b<0)
    {
        b++;
        if (a%2!=0)
            a++;
        a=a/2;
        if (b%2!=0)
            b++;
        b=b/2;
        a=a*(a-1);
        b=b*(b-1);
        ans=-a+b;
        cout<<ans;
    }
    else
    {
        a--;
        if (b%2!=0)
            b=b--;
        b=b/2;
        if (a%2!=0)
            a--;
        a=a/2;
        a=a*(a+1);
        b=b*(b+1);
        ans=b-a;
        cout<<ans;
    }
}
