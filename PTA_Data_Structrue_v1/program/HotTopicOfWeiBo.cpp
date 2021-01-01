# include <bits/stdc++.h>
using namespace std;

bool cmp(string str1, string str2)
{
    for (int i = 0; i <= str1.length() - 1 && i <= str2.length() - 1; ++i) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        }
    }
    if (str1.length() < str2.length()) {
        return true;
    }
    return false;
}

int main()
{
    int n;
    scanf("%d\n", &n);
    //cin >> n;
    map<string, int> HashMap;
    string str;
    while (n > 0) {
        -- n;
        string forStr = ".";
        string curStr;
        bool start = false;
        bool end = false;
        bool blankEnd = false;
        while (cin.peek() != '\n') {
            char ch = cin.get();
            if (ch == '#') {
                if (!start) {
                    start = true;
                } else {
                    end = true;
                    start = false;
                }
            } else if (start && isalnum(ch)) {
                curStr += tolower(ch);
                blankEnd = false;
            } else if (start) {
                if (!blankEnd && curStr.length() > 0) {
                    curStr += ' ';
                    blankEnd = true;
                }
            }
            if (end && isalpha(curStr[0])) {
                curStr[0] = toupper(curStr[0]);
            }
            if (end && curStr != forStr) {
                if (blankEnd) {
                    curStr = curStr.substr(0, curStr.length() - 1);
                }
                end = false;
                auto search = HashMap.find(curStr);
                if (search != HashMap.end()) {
                    search->second += 1;
                } else {
                    HashMap.insert(make_pair(curStr, 1));
                }
                forStr = curStr;
                curStr = "";
            }
        }
        cin.get();// 读取最后一个换行符
    }

    auto begin = HashMap.begin();
    string res = begin->first;
    int cnt = begin->second;
    int nums = 0;
    ++ begin;
    while (begin != HashMap.end()) {
        if (begin->second > cnt) {
            res = begin->first;
            cnt = begin->second;
            nums = 0;
        } else if (begin->second == cnt) {
            if (cmp(begin->first, res)) {
                res = begin->first;
            }
            nums += 1;
        }
        ++ begin;
    }
    cout << res << endl;
    cout << cnt << endl;
    if (nums != 0) {
        cout << "And " << nums << " more ...";
    }
    return 0;
}