#include <bits/stdc++.h>
#include <random>
using namespace std;

const int N = 1e6;

double a[N+5];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    /// setup random device
    random_device dev;
    mt19937 rng(dev());

    /// generate test
    for(int i = 1; i <= 10; ++i){

        string filename = "TEST/test";
        filename = filename + to_string(i) + ".inp";
        const char* filename_cstr = filename.c_str();
        freopen(filename_cstr, "w", stdout);

        if(i == 1)a[0] = -1e6;
        if(i == 2)a[0] = 1e6;

        for(int j = 1; j <= N; ++j){
            if(i == 1){
                uniform_real_distribution<double> dist(a[j-1]+1, a[j-1] + 1e3);
                a[j] = dist(rng);
                continue;
            }
            if(i == 2){
                uniform_real_distribution<double> dist(a[j-1]-1, a[j-1] - 1e3);
                a[j] = dist(rng);
                continue;
            }
            uniform_real_distribution<double> dist(-1e6, 1e6);
            a[j] = dist(rng);
        }

        for(int j = 1; j <= N; ++j)
            cout << fixed << setprecision(6) <<  a[j] << endl;
    }
}
