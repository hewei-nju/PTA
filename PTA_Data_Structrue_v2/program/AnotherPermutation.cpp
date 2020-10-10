#include <bits/stdc++.h>
using namespace std;

int visit[10];  // 0:不输出 1:输出
int nums[10];   // 存储我们要输出的数字
int n;          // 存储全排列n的大小

void print(int pos, int num)  // 表示在pos的位置上到期后面数字的全排列(数字按从小到大，也就是字典序)
{
    nums[pos]  = num;         // 要输出，就先存储一下
    if (pos == n) {           // 如果位置已经到了要输出的地方，开始输出
        for (int i = 1; i <= n; ++i) {
            cout << nums[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {  // 从第一个位置开始扫描
        if (visit[i] == 0) {        // 如果第一个位置不让输出，就让他的visit为1，进入下一个
            visit[i] = 1;
            print(pos + 1, i);
            visit[i] = 0;           // 然后在换回来
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {  // 依次输出1，2，... ，开头的全排列
        visit[i] = 1;
        print(1, i);
        visit[i] = 0;
    }

    return 0;
}