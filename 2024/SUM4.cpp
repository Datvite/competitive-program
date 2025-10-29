#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,s=0;
    cin>>n;
    for (int i = 0; i <= n; i++)
    {
        s+= 2 * i;
    }
    cout<<s+2020;
}
