#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    int sq = sqrt(n);
    for (int i = 3; i <= sq; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

// Sinh số đối xứng từ nửa đầu
int createPalindrome(int half, bool oddLength)
{
    int res = half;
    if (oddLength)
        half /= 10;
    while (half > 0)
    {
        res = res * 10 + half % 10;
        half /= 10;
    }
    return res;
}

int main()
{
    int m, n;
    cin >> m >> n;
    bool found = false;

    // Sinh số đối xứng có độ dài từ 1 đến 8 chữ số
    for (int len = 1; len <= 8; ++len)
    {
        int start = pow(10, (len - 1) / 2);
        int end = pow(10, (len + 1) / 2);
        cout << "len=" << len << " start=" << start << " end=" << end << '\n';
        for (int half = start; half < end; ++half)
        {
            int pal = createPalindrome(half, len % 2);
            if (pal > n)
                break;
            if (pal >= m && isPrime(pal))
            {
                cout << pal << '\n';
                found = true;
            }
        }
    }

    if (!found)
        cout << "0\n";
    return 0;
}
