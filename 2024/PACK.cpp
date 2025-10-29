#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,s;
    cin>>n>>k;
    s=n/k;
    if (n%k==0)
        cout<<s;
    else
        cout<<s+1;
    return 0;
}
