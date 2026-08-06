// ------------------------------------------------------------
//  gen_50_tests.cpp
//  Generate many test cases for the “longest increasing tree subsequence” problem.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// ------------------------------------------------------------------
// Options handling
// ------------------------------------------------------------------
struct Options {
    int count = 50;                // how many test files to create
    int n = -1;                     // fixed n for every test (‑1 ⇒ random per test)
    long long seedBase = chrono::high_resolution_clock::now()
                         .time_since_epoch().count();
};

Options parseArgs(int argc, char* argv[]) {
    Options opt;
    for (int i = 1; i < argc; ++i) {
        string a = argv[i];
        if (a == "-c" && i + 1 < argc) opt.count = stoi(argv[++i]);
        else if (a == "-n" && i + 1 < argc) opt.n = stoi(argv[++i]);
        else if (a == "-seed" && i + 1 < argc) opt.seedBase = stoll(argv[++i]);
        else {
            cerr << "Unknown/invalid argument: " << a << "\n";
            exit(1);
        }
    }
    if (opt.count <= 0) {
        cerr << "Count must be positive.\n";
        exit(1);
    }
    if (opt.n != -1 && (opt.n <= 0 || opt.n > 300000)) {
        cerr << "If -n is supplied it must satisfy 1 ≤ n ≤ 300000.\n";
        exit(1);
    }
    return opt;
}

// ------------------------------------------------------------------
// Random tree via Prüfer sequence (uniform over all trees)
// ------------------------------------------------------------------
vector<pair<int,int>> randomTree(int n, mt19937_64 &rng) {
    if (n == 1) return {};

    vector<int> prufer(n - 2);
    uniform_int_distribution<int> dist(1, n);
    for (int &x : prufer) x = dist(rng);

    vector<int> degree(n + 1, 1);
    for (int x : prufer) ++degree[x];

    priority_queue<int, vector<int>, greater<int>> leaves;
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 1) leaves.push(i);

    vector<pair<int,int>> edges;
    for (int x : prufer) {
        int leaf = leaves.top(); leaves.pop();
        edges.emplace_back(leaf, x);
        if (--degree[x] == 1) leaves.push(x);
    }
    // last two vertices
    int a = leaves.top(); leaves.pop();
    int b = leaves.top(); leaves.pop();
    edges.emplace_back(a, b);
    return edges;
}

// ------------------------------------------------------------------
// Write a single test case to a file named testXX.txt
// ------------------------------------------------------------------
void writeCase(const string& filename,
               int n,
               const vector<int64>& val,
               const vector<pair<int,int>>& edges) {
    ofstream out(filename);
    if (!out) {
        cerr << "Failed to open " << filename << " for writing.\n";
        exit(1);
    }
    out << n << "\n";
    for (int i = 0; i < n; ++i) {
        if (i) out << ' ';
        out << val[i];
    }
    out << "\n";
    for (auto [u, v] : edges) out << u << ' ' << v << "\n";
}

// ------------------------------------------------------------------
// Types of tests we rotate through
// ------------------------------------------------------------------
enum class TestType { Random, Line, Star, Increasing, Decreasing, AllSame };

string typeName(TestType t) {
    switch (t) {
        case TestType::Random:      return "random";
        case TestType::Line:        return "line";
        case TestType::Star:        return "star";
        case TestType::Increasing: return "increasing";
        case TestType::Decreasing:  return "decreasing";
        case TestType::AllSame:    return "allsame";
    }
    return "";
}

// ------------------------------------------------------------------
// Generate a single test file
// ------------------------------------------------------------------
void generateOne(int idx,
                 const Options& opt,
                 mt19937_64& rng) {

    TestType type = static_cast<TestType>(idx % 6);          // rotate

    int n = (opt.n == -1) ?
            uniform_int_distribution<int>(1, 300000)(rng) :
            opt.n;

    vector<int64> val(n);
    vector<pair<int,int>> edges;

    uniform_int_distribution<int64> valDist(1, 1'000'000'000LL);
    const int64 INF = 1'000'000'000LL;

    switch (type) {
        case TestType::Random: {
            edges = randomTree(n, rng);
            for (int i = 0; i < n; ++i) val[i] = valDist(rng);
            break;
        }
        case TestType::Line: {
            edges.reserve(n-1);
            for (int i = 1; i < n; ++i) edges.emplace_back(i, i+1);
            for (int i = 0; i < n; ++i) val[i] = valDist(rng);
            break;
        }
        case TestType::Star: {
            edges.reserve(n-1);
            for (int i = 2; i <= n; ++i) edges.emplace_back(1, i);
            for (int i = 0; i < n; ++i) val[i] = valDist(rng);
            break;
        }
        case TestType::Increasing: {
            edges.reserve(n-1);
            for (int i = 1; i < n; ++i) edges.emplace_back(i, i+1);
            int64 cur = 1;
            for (int i = 0; i < n; ++i) {
                val[i] = cur;
                cur += rng() % 1000 + 1;          // stay ≤ 1e9
            }
            break;
        }
        case TestType::Decreasing: {
            edges.reserve(n-1);
            for (int i = 1; i < n; ++i) edges.emplace_back(i, i+1);
            int64 cur = INF;
            for (int i = 0; i < n; ++i) {
                val[i] = cur;
                cur -= rng() % 1000 + 1;
            }
            break;
        }
        case TestType::AllSame: {
            edges = randomTree(n, rng);
            fill(val.begin(), val.end(), 42);
            break;
        }
    }

    char buf[32];
    snprintf(buf, sizeof(buf), "test%02d.txt", idx + 1);
    writeCase(buf, n, val, edges);
    cerr << "Generated " << buf << " (type=" << typeName(type)
         << ", n=" << n << ")\n";
}

// ------------------------------------------------------------------
// Main driver
// ------------------------------------------------------------------
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Options opt = parseArgs(argc, argv);
    mt19937_64 rng(opt.seedBase);

    for (int i = 0; i < opt.count; ++i) {
        rng.discard(10);                 // decorrelate successive tests
        generateOne(i, opt, rng);
    }
    return 0;
}
