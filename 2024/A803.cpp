#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,s=1;
    cin>>a>>b;
    while (b>0)
    {
        s=s*a;
        b--;
    }
    cout<<s;
    return 0;
}
