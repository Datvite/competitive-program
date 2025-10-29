#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum,d;
    sum = 0; //Khởi tạo biến sum
    while (n!=0)
    {
        d = n%10; //tách chữ số hàng đơn vị
        sum = sum + d; //cộng chữ số hàng đơ vị vừa tách ra vào tổng
        n = n/10; //thay đổi lại giá trị của n
    }
    cout << sum;
    return 0;
}
