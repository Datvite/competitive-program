#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if (a==0&&b==0)
        cout<<"VSN";
    else
        {
            if (a==0&&b!=0)
                cout<<"VN";
            else
                cout<<"CN";
        }
    return 0;
}
