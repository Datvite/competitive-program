#include <bits/stdc++.h>
using namespace std;
long long n,a[1000068],b;
unordered_map<long long,long long>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>b;
    m[b]++;
        }
    for (auto& x : m)
        {
            if (x.second%2!=0)
             {
                 cout<<x.first;
                 break;
             }

        }
}
