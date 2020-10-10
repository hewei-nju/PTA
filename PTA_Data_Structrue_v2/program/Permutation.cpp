#include <bits/stdc++.h>
using namespace std;

int arr[362880];

int len = 0;

int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void Permutation(int data[], int low, int high)
{
    if (low == high) {
        int sum = 0;
        int base = 1;
        for (int i = high - 1; i >= 0; --i) {
            //cout << nums[i];
            sum += base * data[i];
            base *= 10;
        }
        arr[len++] = sum;
        //cout << endl;
    } else {
        for (int i = low; i <= high - 1; ++i) {
            swap(data, low, i);
            Permutation(data, low + 1, high);
            swap(data, low, i);
        }
    }
}

void Qsort(int data[], int low, int high){
    if (high <= low) { 
        return;
    }
    int i = low;
    int j = high + 1;
    int key = data[low];
    while (true) {
        while (data[++i] < key) {
            if (i == high){
                break;
            }
        }
        while (data[--j] > key) {
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
    int temp = data[low];
    data[low] = data[j];
    data[j] = temp;
    Qsort(data, low, j - 1);
    Qsort(data, j + 1, high);
}

int main()
{
    int n;
    cin >> n;
    Permutation(nums, 0, n);
    Qsort(arr, 0, len - 1);
    for (int i = 0; i <= len - 1; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}