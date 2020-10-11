#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i <= n - 1; ++i) {
        cin >> data[i];
    }

    int this_sum = 0, max_sum = data[0];
    for (int i = 0; i <= n - 1; ++i) {
        this_sum += data[i];
        if (this_sum > max_sum) {
            max_sum = this_sum;
        }

        if(this_sum < 0) {
            this_sum = 0;
        }
    }
    cout << max_sum << endl;

    return 0;
}
