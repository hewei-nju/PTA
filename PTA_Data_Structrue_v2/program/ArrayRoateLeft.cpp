#include <bits/stdc++.h>
using namespace std;

void RotateLeft(int arr[], int n, int m)
{
    if (m % n == 0) {
        m = 0;
    } else if (m > n) {
        m %= n;
    }
    for (int i = m; i <= n - 1; ++i) {
        if (i == m) {
            cout << arr[i];
        } else {
            cout << " " << arr[i];
        }
    }

    for (int i = 0; i <= m - 1; ++i) {
        cout << " " << arr[i];
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i <= n - 1; ++i) {
        cin >> arr[i];
    }

    RotateLeft(arr, n, m);

    return 0;
}