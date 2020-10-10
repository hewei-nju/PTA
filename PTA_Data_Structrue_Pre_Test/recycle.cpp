#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    int data[n];
    for (int i = 0; i <= n - 1; ++i) {
    cin >> data[i];
    }

    for(int i = n - 1; m > 0;) {
        int temp = data[i];
        for (int j = i - 1; j >= 0; --j) {
            data[j+1] = data[j];
        }
        data[0] = temp;
        --m;
    }

    cout << data[0];
    for(int i = 1; i <= n - 1; ++i) {
        cout << " " << data[i];
    }

    return 0;
}