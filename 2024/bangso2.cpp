#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,ans=0,z;
    cin>>n;
    z=sqrt(n);
    for(int i = 1; i <=z ; i++)
        ans=ans+n/i;
    ans=ans*2;
    ans=ans-z*z;
    cout <<ans;
}
