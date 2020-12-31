# include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> HashMap;
    int n;
    cin >> n;
    char instr;
    string qq, password;
    while (n > 0) {
        --n;
        cin >> instr >> qq >> password;
        auto search = HashMap.find(qq);
        switch (instr) {
            case 'L':
                if (search != HashMap.end()) {
                    if (password == search->second) {
                        cout << "Login: OK" << endl;
                    } else {
                        cout << "ERROR: Wrong PW" << endl;
                    }
                } else {
                    cout << "ERROR: Not Exist" << endl;
                }
                break;
            case 'N':
                if (search != HashMap.end()) {
                    cout << "ERROR: Exist" << endl;
                } else {
                    HashMap.insert(make_pair(qq, password));
                    cout << "New: OK" << endl;
                }
                break;
        }
    }

    return 0;
}