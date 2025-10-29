#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,s=0;
    cin>>n;
    for (long long i=n;i>=1;i--)
        s=s+i;
    cout<<s;
}
