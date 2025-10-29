#include<bits/stdc++.h>
using namespace std;
long long fibo (long long n)
{
    long long fib1=0;
    long long fib2=1;
    long long fib3;
    while (fib1+fib2<=n)
    {
        fib3=fib1+fib2;
        fib1=fib2;
        fib2=fib3;
    }
    return fib3;
}
int main()
{
    long long n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}
