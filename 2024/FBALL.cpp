#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,q,r,s,u,v,a=0,b=0,c=0;
    cin>>p>>q>>r>>s>>u>>v;
    if (p>q)
        a+=3;
    else if (p==q)
    {
        a++;
        b++;
    }
    else
        b+=3;
    if (r>s)
        a+=3;
    else if (r==s)
        {
            a++;
            c++;
        }
    else
        c+=3;
    if (u>v)
        b+=3;
    else if (p==q)
        {
            b++;
            c++;
        }
    else
        c+=3;
        cout<<a<<" "<<b<<" "<<c;
}
