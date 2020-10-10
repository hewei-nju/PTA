#include <bits/stdc++.h>
using namespace std;
int len1, len2;
int data1[2][1001]; // 0:系数 1:指数
int data2[2][1001];
auto print_Add(int data1[][1001], int data2[][1001], int len1, int len2) -> void;  // 尾置返回类型
auto print_Plus(int data1[][1001], int data2[][1001], int len1, int len2) -> void;

int main()
{
    // 获取第一个多项式的输入
    cin >> len1;
    for (int i = 0; i <= len1 - 1; ++i) {
        cin >> data1[0][i] >> data1[1][i];
    }

    // 获取第二个多项式的输入
    cin >> len2;
    for (int i = 0; i <= len2 - 1; ++i) {
        cin >> data2[0][i] >> data2[1][i];
    }

    print_Plus(data1, data2, len1, len2);
    cout << endl;
    print_Add(data1, data2, len1, len2);
    
    return 0;
}

auto print_Add(int data1[][1001], int data2[][1001], int len1, int len2) -> void {
    int res[2][1001];
    int i = 0, j = 0, k = 0, len = 0;
    for (; i <= len1 - 1;) {
        for (; j <= len2 - 1;) {
            if (data1[1][i] == data2[1][j]) {  // 两者指数相等
                /**if (data1[1][i] == 0) {
                    //cout << data1[0][i] + data2[0][j] << " " << 0;
                    res[0][k] = data1[0][i] + data2[0][j];
                    res[1][k] = 0;
                    ++k;
                } else {
                    if (data1[0][i] + data2[0][j] != 0) {  // 系数和不为0
                        //cout << data1[0][i] + data2[0][j] << " " << data1[1][i] << " ";
                        res[0][k] = data1[0][i] + data2[0][j];
                        res[1][k] = data1[1][i];
                        ++k;
                    } /**else {
                        res[0][k] = data1[0][i] + data2[0][j];
                        res[1][k] = data1[1][i];
                        ++k;
                    }*/
                //}

                if (data1[0][i] + data2[0][j] != 0) {
                    res[0][k] = data1[0][i] + data2[0][j];
                    res[1][k] = data1[1][i];
                    ++k;
                }
                ++i, ++j;  
            } else if (data1[1][i] > data2[1][j]) {
                //cout << data1[0][i] << " " << data1[1][i] << " ";
                res[0][k] = data1[0][i];
                res[1][k] = data1[1][i];
                ++k;
                ++i;
            } else if (data1[1][i] < data2[1][j]) {
                //cout << data2[0][j] << " " << data2[1][j] << " ";
                res[0][k] = data2[0][j];
                res[1][k] = data2[1][j];
                ++k;
                ++j;
            }
        }
        if (j == len2) {  // 可能data2输出完了，但是data1还有数据，就会死循环，所以要特判一下
            break;
        }
    }

    // 两者谁还有没输出的就直接输出
    for (; i <= len1 - 1; ++i) {
        /**if (i == len1 - 1) {
            cout << data1[0][i] << " " << data1[1][i];
        } else {
            cout << data1[0][i] << " " << data1[1][i] << " ";
        }*/
        res[0][k] = data1[0][i];
        res[1][k] = data1[1][i];
        ++k;
    }

    for (; j <= len2 - 1; ++j) {
        /**if (j == len2 - 1) {
            cout << data2[0][j] << " " << data2[1][j];
        } else {
            cout << data2[0][j] << " " << data2[1][j] << " ";
        }*/
        res[0][k] = data2[0][i];
        res[1][k] = data2[1][i];
        ++k;
    }

     if (k == 0) {
        cout << 0 << " " << 0;
        return;
     }

    for (i = 0; i <= k - 1; ++i) {
        /*if (res[0][i] == 0 && res[1][i] != 0) {
            continue;
        }*/
        if (i != k - 1) {
            cout << res[0][i] << " " << res[1][i] << " ";
        } else {
            cout << res[0][i] << " " << res[1][i];
        }
    }
}

auto print_Plus(int data1[][1001], int data2[][1001], int len1, int len2) -> void {
    int res[2][1001];
    int len = 0;
    // 先一通乱乘，把所有项都乘一遍
    for (int i = 0; i <= len1 - 1; ++i) {
        for (int j = 0; j <= len2 - 1; ++j) {
            res[0][i*len2 + j] = data1[0][i] * data2[0][j];
            if (res[0][i*len2 + j] == 0){ 
                res[1][i*len2 + j] = 0;
            } else {
                res[1][i*len2 + j] = data1[1][i] + data2[1][j];
            }
        }
    }
    // 对其中相同指数的项进行求和，并把后者置为0
    for (int i = 0; i <= len1*len2 - 1; ++i) {
        for (int j = i + 1; j <= len1*len2 - 1; ++j) {
            if (res[1][i] == res[1][j]) {
                res[0][i] += res[0][j];
                res[0][j] = 0;
            }
        }
    }
    // 排序
    for (int i = 0; i <= len1*len2 - 1; ++i) {
        for (int j = i + 1; j <= len1*len2 - 1; ++j) {
            if (res[1][i] < res[1][j]) {
                int temp1 = res[1][i];
                int temp0 = res[0][i];
                res[1][i] = res[1][j];
                res[0][i] = res[0][j];
                res[1][j] = temp1;
                res[0][j] = temp0;
            }
        }
    }
    
    for (int i = len1*len2 - 1; i >= 0; --i) {
        if (res[0][i] != 0) {
            len = i;
            break;
        }
    }
    if (len == 0) {
        cout << res[0][0] << " " << res[1][0];
    } else {
        for (int i = 0; i <= len; ++i) {
            if (res[0][i] == 0) {
                continue;
            } else if (i == len) {
                cout << res[0][i] << " " << res[1][i];
            } else  {
                cout << res[0][i] << " " << res[1][i] << " ";
            }
        }
    }
    /**for (int i = 0; i <= len1*len2 - 1; ++i) {
        if (res[1][i] == 0 || i == len1*len2 - 1) {
            continue;
        } else if (res[1][i] != 0 && res[0][i] != 0) {
            cout << res[0][i] << " " << res[1][i] << " ";
        }
    }*/

}