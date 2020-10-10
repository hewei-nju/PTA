#include <bits/stdc++.h>
using namespace std;

void printLongestIncreasingSub(int arr[], int n)
{
    int head = 0, tail = 0, posHead = 0, posTail = 0;
    int i = 0, j = 1;
    for ( ; i <= n - 1 && j <= n - 1; ) {
        if (arr[j] <= arr[i]) {
            if (j - 1 - posHead > tail - head) {
                head = posHead;
                tail = i;
            }
            posHead = j;
            i = j;
            j = i + 1;
        } else {
            posTail = j;
            if (posTail - posHead > tail - head) {
                head = posHead;
                tail = posTail;
            }
            ++i, ++j;
        }
    }
    for (i = head; i <= tail; ++i) {
        if (i == head) {
            cout << arr[i];
        } else {
            cout << " " << arr[i];
        }
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
    printLongestIncreasingSub(arr, n);

    return 0;
}