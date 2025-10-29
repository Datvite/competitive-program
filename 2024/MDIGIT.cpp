#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,last,max=0;
    cin>>n;
    while (n!=0)
    {
        last=n%10;
        n=n/10;
        if (last>max)
            max=last;
    }
    cout<<max;
    return 0;
}
