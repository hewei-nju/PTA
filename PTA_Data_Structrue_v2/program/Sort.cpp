#include <bits/stdc++.h>
using namespace std;

void Shell_sort(int arr[], int n)
{
    int gap = n / 3;
    while (gap >= 1) {
        for (int i = gap; i <= n - 1; ++i) {
            for (int j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap) {
                swap(arr[j], arr[j - gap]);
            }
        }
        gap = gap / 3;
    }
}

int main ()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n - 1; ++i) {
        cin >> arr[i];
    }

    Shell_sort(arr, n);
    for (int i = 0; i <= n - 1; ++i) {
        if (i == 0) {
            cout << arr[i];
        } else {
            cout << " " << arr[i];
        }
    }
    return 0;
}