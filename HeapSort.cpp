#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int N = 1e6;

double a[N+5];

void heapify(int n, int i) {
    /// Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    /// Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(n, largest);
    }
}

void heapSort(int n){
    /// Build max heap
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    /// Heap sort
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);

    /// Heapify root element to get highest element at root again
        heapify(i, 0);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
///    freopen("HeapSortResult.out", "w", stdout);
    for(int i = 1; i <= 10; ++i){
        string filename = "TEST/test";
        filename = filename + to_string(i) + ".inp";
        const char* filename_cstr = filename.c_str();
        freopen(filename_cstr, "r", stdin);

        for(int j = 0; j < N; ++j)cin >> a[j];

        /// calculate time
        auto start = chrono::high_resolution_clock::now();
        heapSort(N);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        /// check for sorted
        for(int j = 1; j < N; ++j)if(a[j-1] > a[j]){
            cout << fixed << setprecision(6) << j << ' ' << a[j-1] << ' ' << a[j] << endl;
            return 0;
        }

        cout << "Test " << i << ": " << elapsed.count() << " ms" << endl;

    }
}
