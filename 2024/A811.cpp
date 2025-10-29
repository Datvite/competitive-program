#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum,d;
    sum = 0;
    while (n!=0)
    {
        d = n%10;
        sum = sum + d;
        n = n/10;
    }
    cout << sum;
    return 0;
}
