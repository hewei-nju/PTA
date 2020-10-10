#include <bits/stdc++.h>
using namespace std;

int main () {
    string input_num_str;
    int nums[2][10] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // 用来统计0-9这些数字出现的个数
    int num1[30], num2[30];  // 存放字符串的数字
    cin >> input_num_str;
    int len1 = input_num_str.length(), len2 = 0;
    num1[0] = 0;  // 位最后一位进位考虑
    bool tag;
    for(int i = 1; i <= len1; ++i) {
        num1[i] = input_num_str[i-1] - '0';  // 将字符转换成数字，下面进行数乘
        ++nums[0][num1[i]];
    }

    int res = 0, carry = 0, standard = 0;  // 模拟手算乘法 2 x num;
    for(int i = len1, j = 0; i >= 0; --i, ++j, len2 = j) {
        res = 2 * num1[i] + carry;
        if(i == 0 && res == 0) {
            tag = false;
        } else if (i == 0 && res > 0) {
            tag = true;
        }
        carry = res / 10;  // 进位
        standard = res % 10;  // 本位
        num2[j] = standard;
        if(res == 0 && i == 0){
            continue;
        }
        ++nums[1][standard];

    }


    if (tag == false) {
        for (int i = 0; i <= 9; ++i) {
            if (nums[0][i] != nums[1][i]) {
                cout << "No" << endl;
                for (int i = len2 - 2; i >= 0; --i) {
                    cout << num2[i];
                }
                return 0;
            }
        }
        cout << "Yes" << endl;
        for (int i = len2 - 2; i >= 0; --i) {
            cout << num2[i];
        } 
    } else {
        for (int i = 0; i <= 9; ++i) {
            if (nums[0][i] != nums[1][i]) {
                cout << "No" << endl;
                for (int i = len2 - 1; i >= 0; --i) {
                    cout << num2[i];
                }
                return 0;
            }
        }
        cout << "Yes" << endl;
        for (int i = len2 - 1; i >= 0; --i) {
            cout << num2[i];
        }
    }

    return 0;
}