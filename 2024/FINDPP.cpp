#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
const int N = 1e6 + 9;
const int M = 1e9 + 7;
long long n, a[N], sang1[N + 10];
bool sang4[N + 10];
void sang()
{
    memset(sang1, 0, sizeof(sang1));
    for (int i = 2; i*i <= sqrt(N); i++)
    {
        if (!sang1[i])
        {
            sang1[i] = i;
            for (int j = i * i; j <= N; j += i)
            {
                if (!sang1[j]) sang1[j] = i;
            }
        }
    }
}
void sangg()
{
    memset(sang4, true, sizeof(sang4));
    sang4[0] = sang4[1] = false;
    for (int i = 2; i*i <= N; i++)
    {
        if (sang4[i])
            for (int j = i * i; j <= N; j += i)
                sang4[j] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FINDPP.INP","r",stdin);
    freopen("FINDPP.OUT","w",stdout);
    sang();
    sangg();
    int n,k;
    long long a[1000068],t;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin >> t;
        unordered_map<long long,long long> m;
        long long d = LLONG_MAX;
        for (int i = 1; i <=t; i++)
        {
            cin >> a[i];
            long long k = abs(a[i]);
            if (k==0)
                continue;
            while(k!=1)
            {
                long long s=sang1[k];
                long long so=1;
                while(k % s == 0)
                {
                    k=k/s;
                    so=so*s;
                }
                m[s]=max(m[s],so*s);
            }
        }
        for (auto q:m)
        {
            d = min(d, q.second);
        }
        for (long long i = 2; i <= d; i++)
        {
            if (m[i] == 0 && sang4[i])
            {
                d = min(d, i);
                break;
            }
        }
        cout << d << "\n";
    }
}



