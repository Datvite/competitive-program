#include <bits/stdc++.h>
using namespace std;
long long n,k=0,dem=1;
unsigned long long x;
long long ohno(unsigned long long n)
{
    long long ans=0;
    while (n>0)
    {
        if (n%2==0)
        {
            ans=ans;
            n=n/2;
        }
        else
        {
            if (ans==0)
                ans=1;
            else
                ans=0;
            n=n/2;
        }

    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        cout<<ohno(x)<<endl;
    }
}
