#include <bits/stdc++.h>
using namespace std;
long long a,b,ans=0;
map<long long,int>da;
map<long long,int>db;
map<long long,bool>check;
void demuoca(long long a)
{
    for (int i=1;i<=sqrt(a);i++)
        {
            if (a%i==0&&a%(a/i)==0&&i!=a/i)
                {
                    da[i]++;
                    da[a/i]++;
                }
            else if (a%i==0)
                {
                    da[i]++;
                }
        }
}
void demuocb(long long a)
{
    for (int i=1;i<=sqrt(a);i++)
        {
            if (a%i==0&&a%(a/i)==0&&i!=a/i)
                {
                    db[i]++;
                    db[a/i]++;
                }
            else if (a%i==0)
                {
                    db[i]++;
                }
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    demuoca(a);
    demuocb(b);
    for (auto& i:da)
        {
            for (auto& j:db)
            {
                if (check[i.first*j.first]==false)
                    {
                        ans++;
                        check[i.first*j.first]=true;
                    }
            }
        }
    cout<<ans;
}
