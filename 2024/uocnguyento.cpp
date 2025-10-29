#include <bits/stdc++.h>
using namespace std;
long long n,d,k;
long long dem (long long n)
{
    long long ans=0;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            ans++;
            while (n%i==0)
                n=n/i;
            }
    }
    if (n!=1)
        ans++;
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long b;
    for (int i=1; i<=n; i++)
    {
        cin>>b;
        cout<<dem(b)<<endl;
    }
}
