#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if (a>0&&b>0&&a%2==0&&b%2==0)
        cout<<"1";
    else
        {
            if (a<0&&b<0&&a%2!=0&&b%2!=0)
                cout<<"1";
            else
                cout<<"0";
        }
    return 0;

}
