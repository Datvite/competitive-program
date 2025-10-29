#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findCourseOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    // Bước 1: Xây dựng đồ thị và mảng in-degree
    vector<vector<int>> graph(numCourses);
    vector<int> in_degree(numCourses, 0);

    for (const auto& pre : prerequisites) {
        int a = pre.first - 1; // Chuyển sang chỉ số 0
        int b = pre.second - 1; // Chuyển sang chỉ số 0
        graph[a].push_back(b);
        in_degree[b]++;
    }

    // Bước 2: Tạo hàng đợi cho các khóa học có in-degree bằng 0
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    // Bước 3: Xử lý các khóa học từ hàng đợi
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course + 1); // Chuyển về chỉ số 1

        for (int neighbor : graph[course]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Bước 4: Kiểm tra xem có hoàn thành được tất cả các khóa học không
    if (order.size() == numCourses) {
        return order;
    } else {
        return {}; // Trả về danh sách rỗng nếu không khả thi
    }
}

int main() {
    int numCourses, numPrereqs;
    cin >> numCourses >> numPrereqs;

    vector<pair<int, int>> prerequisites(numPrereqs);
    for (int i = 0; i < numPrereqs; ++i) {
        cin >> prerequisites[i].first >> prerequisites[i].second;
    }

    vector<int> result = findCourseOrder(numCourses, prerequisites);

    if (result.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
