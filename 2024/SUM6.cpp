#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long s=0;
    for (long long i=1;i<=n;i++)
        s=s+i*(i+1);
    cout<<s%2020;
}

