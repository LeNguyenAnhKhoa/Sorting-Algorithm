#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;

const int N = 1e6;

double a[N+5];

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

/// QuickSort
void QuickSort(int l, int r) {
    assert(l < r && 1 <= l && r <= N);
    int p = l + rand() % (r - l);
    assert(l <= p && p <= r);
    swap(a[p], a[r]);
    double pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; ++j){
        if(a[j] <= pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    if(l < i-1)QuickSort(l, i-1);
    if(i+1 < r)QuickSort(i+1, r);
}
signed main(){
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("QuickSortResult.out", "w", stdout);
    for(int i = 1; i <= 10; ++i){
        string filename = "TEST/test";
        filename = filename + to_string(i) + ".inp";
        const char* filename_cstr = filename.c_str();
        freopen(filename_cstr, "r", stdin);

        for(int j = 1; j <= N; ++j)cin >> a[j];

        /// calculate time
        auto start = chrono::high_resolution_clock::now();
        QuickSort(1, N);
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
