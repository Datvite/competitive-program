#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum=0;
    while (n!=0)
    {
        sum=sum+1;
        n=n/10;
    }
    cout<<sum;
    return 0;
}
