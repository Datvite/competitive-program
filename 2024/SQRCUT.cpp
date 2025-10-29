#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("SQRCUT.INP","r",stdin);
    freopen("SQRCUT.OUT","w",stdout);
    long long a,b,t=1,dem=0;
    cin>>a>>b;
    if (b>a)
        switch(a,b);
    while (t!=0)
    {
        dem=dem+a/b;
        t=a%b;
        a=b;
        b=t;
    }
    cout<<dem;
}
