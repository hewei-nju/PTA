#include <bits/stdc++.h>
using namespace std;

bool Process(string str, const int max)
{
    int cnt = 0;
    for (int i = 0; i <= str.length() - 1; ++i) {
        if (str[i] == 'S') {
            cnt += 1;
            if (cnt > max) {
                return false;
            }
        } else if (str[i] == 'X') {
            cnt -= 1;
            if (cnt < 0) {
                return false;
            }
        }
    }
    if (cnt != 0) {
        return false;
    }
    return true;
}
int main ()
{
    int n, m;
    string str;
    cin >> n >> m;
    bool out[n];
    for (int i = 0; i <= n - 1; ++i) {
        cin >> str;
        out[i] = Process(str, m);
    }
    for (int i = 0; i <= n - 1; ++i) {
        if (out[i] == false) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}