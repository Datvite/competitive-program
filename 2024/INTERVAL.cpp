#include<bits/stdc++.h>
using namespace std;
long long n, i, gmax = LLONG_MIN, lc, ld;
struct pta
{
    long long d;
    long long c;
};
pta a[10000009];
bool cmp(pta a,pta b)
{
    return a.d<b.d;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].d >> a[i].c;
    }
    sort(a + 1, a + n + 1, cmp);
    ld = a[1].d;
    lc = a[1].c;
    for(int i = 2; i <= n; i++)
    {
        if(a[i]. d <= lc)
        {
            if (a[i].c>lc)
                lc = a[i].c;
        }
        else
        {
            ld = a[i].d;
            lc = a[i].c;
        }
        if(gmax < lc - ld)
            gmax = lc - ld;
    }
    if(gmax < lc - ld)
            gmax = lc - ld;
    cout << gmax;
}
