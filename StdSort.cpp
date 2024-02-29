#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int N = 1e6;

double a[N+5];

signed main(){
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
///    freopen("StdSortResult.out", "w", stdout);
    for(int i = 1; i <= 10; ++i){
        string filename = "TEST/test";
        filename = filename + to_string(i) + ".inp";
        const char* filename_cstr = filename.c_str();
        freopen(filename_cstr, "r", stdin);

        for(int j = 1; j <= N; ++j)cin >> a[j];

        /// calculate time
        auto start = chrono::high_resolution_clock::now();
        sort(a + 1, a + 1 + N);
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
