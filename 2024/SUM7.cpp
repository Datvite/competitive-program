#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int dau=1;
    cin>>n;
    long long s=0;
    for (int i=1;i<=n;i++)
        {s=s+dau*i;
         dau=-dau;
        }
    cout<<s;
    return 0;
}
