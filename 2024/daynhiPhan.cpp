#include <bits/stdc++.h>
using namespace std;
string n;
int a,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    n.resize(a,'0');
    i=pow(2,a);
    cout<<n<<endl;
    i--;
    while (i>0)
    {
        for (int j=a-1; j>=0; j--)
        {

            if (n[j]=='1')
            {
                n[j]='0';
            }
            else if (n[j-1]!='1')
            {
                n[j]='1';
                break;
            }
        if (j==0&&n[j]=='0')
            return 0;
        }
        cout<<n<<endl;
        i--;
    }
}
