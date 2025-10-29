#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxGifts(int N, int K, vector<int>& gifts) {
    // Tạo một mảng để lưu số lượng phần quà tối đa có thể chọn tại mỗi vị trí
    vector<int> max_gifts_count(N, 0);

    // Khởi tạo số lượng phần quà tối đa có thể chọn cho phần tử đầu tiên
    max_gifts_count[0] = 1;

    // Duyệt qua từng phần tử và tính số lượng phần quà tối đa có thể chọn tại mỗi vị trí
    for (int i = 1; i < N; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            // Kiểm tra điều kiện về số thứ tự và giá trị của phần quà
            if (gifts[i] - gifts[j] >= K) {
                max_gifts_count[i] = max(max_gifts_count[i], max_gifts_count[j] + 1);
                break; // Đã tìm được phần quà trước đó thỏa mãn điều kiện, thoát vòng lặp
            }
        }
        // Nếu không có phần quà nào trước đó thỏa mãn điều kiện, phần quà hiện tại chỉ được chọn một lần
        if (max_gifts_count[i] == 0)
            max_gifts_count[i] = 1;
    }

    // Tìm số lượng phần quà tối đa có thể chọn trong mảng max_gifts_count
    int max_gifts = *max_element(max_gifts_count.begin(), max_gifts_count.end());
    return max_gifts;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> gifts(N);
    for (int i = 0; i < N; ++i) {
        cin >> gifts[i];
    }

    int result = maxGifts(N, K, gifts);

    cout << result << endl;

    return 0;
}
