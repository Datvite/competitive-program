#include <bits/stdc++.h>
using namespace std;
long long n,b;
long long a[1000068];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("CTBIT.INP","r",stdin);
    //freopen("CTBIT.OUT","w",stdout);
    while (cin>>n)
    {
        b=0;
        while (n>0)
        {
            b++;
            a[b]=n%2;
            n=n/2;
        }
        for (int i=b; i>=1; i--)
            cout<<a[b];
        cout<<endl;
    }
}
