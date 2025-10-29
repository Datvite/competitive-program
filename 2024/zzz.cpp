#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s;
    double i;
    i=0.1;
    while (i>0)
    {
        s=(16 / (i * i)) + (i * i) + 16*i;
        if (s==42.0)
            break;
        i=i+0.1;
    }
    cout<<i;
    return 0;
}
