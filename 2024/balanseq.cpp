#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, duong=0, gmax = LLONG_MIN,k,i;
    map<long long,long long>m;
    cin >> n;
    int A[1000068];
    for (i =1; i <=n; i++)
    {
        cin >> A[i];
    }
    m[0]=0;
    for (i = 1; i <=n; i++)
    {
        if (A[i] > 0) duong++;
        else duong--;
        if (m[duong]==0&&duong!=0)
            m[duong]=i;
        k=i-m[duong];
        gmax=max(gmax,k);
    }
    cout << gmax;
    return 0;
}
