# include <bits/stdc++.h>
using namespace std;

map<string, int> InitHashMap(int n)
{
    string phoneNum1, phoneNum2;
    map<string, int> HashMap;
    for (int i = 0; i <= n - 1; ++i) {
        cin >> phoneNum1 >> phoneNum2;
        auto search = HashMap.find(phoneNum1);
        if (search == HashMap.end()) {
            HashMap.insert(make_pair(phoneNum1, 1));
        } else {
            HashMap.at(phoneNum1) += 1;
        }
        search = HashMap.find(phoneNum2);
        if (search == HashMap.end()) {
            HashMap.insert(make_pair(phoneNum2, 1));
        } else {
            HashMap.at(phoneNum2) += 1;
        }
    }
    return HashMap;
}

bool cmp(string phoneNum1, string phoneNum2)
{
    for (int i = 0; i <= phoneNum1.length() - 1 && i <= phoneNum2.length() - 1; ++i) {
        if (phoneNum1[i] < phoneNum2[i]) {
            return true;
        } else if (phoneNum1[i] == phoneNum2[i]) {
            continue;
        } else {
            return false;
        }
    }
    return false;
}

void solveProblem(map<string, int> HashMap)
{
    string res = HashMap.begin()->first;
    int cnt = HashMap.begin()->second;
    int nums = 1; // 并列人数
    auto begin = HashMap.begin();
    ++ begin;
    while (begin != HashMap.end()) {
        if (begin->second > cnt) {
            res = begin->first;
            cnt = begin->second;
            nums = 1;
        } else if (begin->second == cnt) {
            if (cmp(begin->first, res)) {
                res = begin->first;
            }
            nums += 1;
        }
        ++ begin;
    }
    if (nums == 1) {
        cout << res << " " << cnt << endl;
    } else {
        cout << res << " " << cnt << " " << nums << endl;
    }
}


int main()
{
    int n;
    cin >> n;
    map<string, int> HashMap = InitHashMap(n);
    solveProblem(HashMap);
    return 0;
}