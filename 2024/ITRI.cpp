#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    if (a+b>c&&b+c>a&&c+a>b)
        cout<<"ITRI";
    else
        cout<<"NTR";
    return 0;
}
