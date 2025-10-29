#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double s=0;
    cin>>n;
    cout<<fixed<<setprecision(3);
    for (int i=1;i<=n;i++)
        s=s+1.0/pow(i,2);
    cout<<s;
    return 0;
}
