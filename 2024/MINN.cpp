#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin>>n>>m;
    for (int i=1; i>0; i++)
    {

        if (n%m!=0)
        {
            n++;
        }
        else
            break;
    }

    cout<<n;
    return 0;
}
