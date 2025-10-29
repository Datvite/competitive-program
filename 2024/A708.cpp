#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int z=1;
    cin>>n;
    for (int i=1 ;i<=n;i++)
        z*=i;
    cout<<z;
    return 0;
}
