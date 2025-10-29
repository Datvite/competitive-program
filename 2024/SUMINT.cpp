#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,sum=0,sum1=0;
    cin>>a>>b;
    for (long long i=a;i<=b;i++)
    {
        sum+=i;
        if (i%2==0)
            sum1+=i;
    }
    cout<<sum<<endl<<sum1;
}
