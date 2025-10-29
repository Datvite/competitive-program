#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum=0,d;
    while (n!=0)
    {
        d=n%10;
        sum=sum+d;
        n=n/10;
    }
    cout<<sum;
    return 0;
}
