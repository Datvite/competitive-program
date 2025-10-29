#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    cin>>a;
    if (a>0&&a%2==0)
        cout<<"1";
    else
    {
        if (a>0&&a%2!=0)
            cout<<"2";
        else
        {
            if (a<0&&a%2==0)
                cout<<"3";
            else
            {
                if (a<0&&a%2!=0)
                    cout<<"4";
            }
        }
    }
   return 0;
}
