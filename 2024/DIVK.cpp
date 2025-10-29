#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    if(n==0)
    {
        cout<<k;
        goto h;
    }
    while (n>=0)
    {
        if (n%k==0)
            break;
        n++;
    }
    cout<<n;
    h:
    return 0;
}
