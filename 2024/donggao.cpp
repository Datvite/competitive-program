#include <bits/stdc++.h>
using namespace std;
long long n,dem=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n%5==0) dem=n/5;
    else
    {
        while (n%5!=0&&dem<=10&&n>0)
        {
            n=n-3;
            dem++;
        }
        if (n%5==0)
            dem=dem+n/5;
        else if (n%3==0)
            dem=dem+n/3;
        else
        {
            cout<<-1;
            return 0;
        }

    }cout<<dem;
}
