#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int N = 1e6;

double a[N+5], b[N+5];

void MergeSort(int l, int r) {
    int mid = l + r >> 1;
    if(l < mid)MergeSort(l, mid);
    if(mid+1 < r)MergeSort(mid+1, r);
    int i = l, j = mid+1, cur = 0;
    while(i <= mid || j <= r){
        if(i <= mid && j <= r){
            if(a[i] <= a[j])
                b[++cur] = a[i++];
            else b[++cur] = a[j++];
        }
        else if(i <= mid)b[++cur] = a[i++];
        else b[++cur] = a[j++];
    }
    for(int i = l, j = 1; i <= r; ++i, ++j)
        a[i] = b[j];
}

signed main(){
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
///    freopen("MergeSortResult.out", "w", stdout);
    for(int i = 1; i <= 10; ++i){
        string filename = "TEST/test";
        filename = filename + to_string(i) + ".inp";
        const char* filename_cstr = filename.c_str();
        freopen(filename_cstr, "r", stdin);

        for(int j = 1; j <= N; ++j)cin >> a[j];

        /// calculate time
        auto start = chrono::high_resolution_clock::now();
        MergeSort(1, N);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> elapsed = end - start;

        /// check for sorted
        for(int j = 1; j < N; ++j)if(a[j] > a[j+1]){
            cout << fixed << setprecision(6) << j << ' ' << a[j] << ' ' << a[j+1] << endl;
            return 0;
        }

        cout << "Test " << i << ": " << elapsed.count() << " ms" << endl;

    }
}
