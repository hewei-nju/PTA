#include <bits/stdc++.h>
using namespace std;
bool isPrimer(int n){
    if (n % 2 == 0) {
        return false;
    } else {
        int m = sqrt(n);
        for (int i = 2; i <= m; ++i) {
            if(n % i == 0) {
                return false;
                }
        }
        return true;
    }
};


int main () {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrimer(i) && isPrimer(i + 2)){
            cnt += 1;
        }
    }

    cout << cnt << endl;

    return 0;
}