#include <iostream>
using namespace std;

// Hàm tính tổng S
double tinhTong(int n) {
  double S = 0; // Biến lưu kết quả
  for (int i = 1; i <= n; i++) {
    int mau = 0; // Biến lưu mẫu số của số hạng
    for (int j = 1; j <= i; j++) {
      mau += j; // Tính tổng từ 1 đến i
    }
    S += 1.0 / mau; // Cộng số hạng vào tổng
  }
  return S; // Trả về kết quả
}

int main() {
  int n; // Biến lưu số n nhập từ bàn phím
  cout << "Nhap n: ";
  cin >> n;
  cout << "Tong S = " << tinhTong(n) << endl; // In ra kết quả
  return 0;
}
