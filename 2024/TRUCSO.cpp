#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b < c || d < a)
        cout<<b-a+d-c;
    else
    {
        a= a<c?a:c;
        b= b>d?b:d;
        cout<<b-a;
    }
}

