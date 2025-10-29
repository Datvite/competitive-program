#include <bits/stdc++.h>
#define skibidi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(tenfile) if(fopen(tenfile".inp","r")) {freopen (tenfile".inp","r",stdin); freopen (tenfile".out","w",stdout);}
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
// Hàm thực hiện QuickSort
int partition(ll arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(ll arr[], int low, int high, int depthLimit)
{
    if (low < high)
    {
        // Nếu độ sâu đệ quy vượt quá giới hạn, chuyển sang HeapSort
        if (depthLimit == 0)
        {
            return;  // Nếu vượt quá độ sâu cho phép, ngừng QuickSort và sử dụng HeapSort
        }

        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1, depthLimit - 1); // Sắp xếp phần trái
        quickSort(arr, pivotIndex + 1, high, depthLimit - 1); // Sắp xếp phần phải
    }
}

// Hàm xây dựng Max Heap
void heapify(ll arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm HeapSort
void heapSort(ll arr[], int n)
{
    // Xây dựng heap từ dưới lên
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    // Sắp xếp phần tử
    for (int i = n; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}

// Hàm sử dụng InsertionSort cho phần mảng nhỏ
void insertionSort(ll arr[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm chính của IntroSort
void introSort(ll arr[], int low, int high, int depthLimit)
{
    int size = high - low + 1;

    // Sử dụng InsertionSort cho các phần mảng nhỏ
    if (size <= 16)
    {
        insertionSort(arr, low, high);
    }
    else
    {
        // Sử dụng QuickSort hoặc HeapSort dựa trên độ sâu đệ quy
        if (depthLimit == 0)
        {
            heapSort(arr, high);
        }
        else
        {
            quickSort(arr, low, high, depthLimit);
        }
    }
}
//int depthLimit = 2 * log(n) / log(2);
//introSort(arr, 1, n, depthLimit);  // Chú ý, chỉ số bắt đầu từ 1
const int N=1e6+69;
ll a[N],n,m,K,T;
void sol()
{
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    //int depthLimit = 2 * log(n) / log(2);
    //introSort(a, 1, n+1, depthLimit);
    sort(a+1,a+n+1);
    ll i=1,ans=0,j=1;
    a[0]=0;
    a[n+1]=m;
    for (int i=0;i<=n&&K>0;i++)
        {
            if (a[i+1]-a[i]>1)
            {
                ll s=a[i+1]-a[i]-1;
                if (K<=s)
                    s=K;
                ans+=s*T+s*(a[i]+1)+s*(s-1)/2;
                K=K-s;
            }
        }
    if (K>=1)
        cout<<-1;
    else
        cout<<ans;
}
int main()
{
    skibidi;
    file("SPASTA")
    cin>>m>>K>>n>>T;
    sol();
}

