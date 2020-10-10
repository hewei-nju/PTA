#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 1000;
char Data[MaxSize];
int len = 0;

char c_stack[MaxSize];
int Top = -1;  // 简陋版本的栈， 操作就直接码算了，不弄函数了，giao~~~

int main()
{
    string s;
    while (getline(cin, s)) {
        //cout << s << endl;
        if (s[0] == '.') {
            break;
        }
        int s_len = s.length();
        for (int i = 0; i <= s_len - 1; ++i) {
            char cfront = s[i], crear = s[i+1];
            if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' || s[i] == ']' || s[i] == '}') {
                Data[len++] = s[i];
            } else if (cfront == '/' && crear == '*') {
                Data[len++] = '<';
                ++i;
            } else if (cfront == '*' && crear == '/') {
                Data[len++] = '>';
                ++i;
            }
        }
    }


    for (int i = 0; i <= len -1; ++i) {
        if (Data[i] == '(' || Data[i] == '[' || Data[i] == '{' || Data[i] == '<') {
            c_stack[++Top] = Data[i]; 
        } else if (Data[i] == ')') {
            if (Top < 0) {
                cout << "NO" << endl;
                cout << "?-)" << endl;
                return 0;
            } else if (c_stack[Top] == '(') {
                Top -= 1;
            } else {
                cout << "NO" << endl;
                if (c_stack[Top] == '<') {
                    cout << "/*-?" << endl;
                } else {
                    cout << c_stack[Top] << "-?" << endl;
                }
                return 0;
            }
        } else if (Data[i] == ']') {
            if (Top < 0) {
                cout << "NO" << endl;
                cout << "?-]" << endl;
                return 0;
            } else if (c_stack[Top] == '[') {
                Top -= 1;
            } else {
                cout << "NO" << endl;
                if (c_stack[Top] == '<') {
                    cout << "/*-?" << endl;
                } else {
                    cout << c_stack[Top] << "-?" << endl;
                }
                return 0;
            }
        } else if (Data[i] == '}') {
            if (Top < 0) {
                cout << "NO" << endl;
                cout << "?-}" << endl;
                return 0;
            } else if (c_stack[Top] == '{') {
                Top -= 1;
            } else {
                cout << "NO" << endl;
                if (c_stack[Top] == '<') {
                    cout << "/*-?" << endl;
                } else {
                    cout << c_stack[Top] << "-?" << endl;
                }
                return 0;
            }
        } else if (Data[i] == '>') {
            if (Top < 0) {
                cout << "NO" << endl;
                cout << "?-*/" << endl;
                return 0;
            } else if (c_stack[Top] == '<') {
                Top -= 1;
            } else {
                cout << "NO" << endl;
                if (c_stack[Top] == '<') {
                    cout << "/*-?" << endl;
                } else {
                    cout << c_stack[Top] << "-?" << endl;
                }
                return 0;
            }
        }
    }
    if (Top >= 0) {
        cout << "NO" << endl;
        if (c_stack[Top] == '<') {
            cout << "/*-?" << endl;
            return 0;
        } else {
            cout << c_stack[Top] << "-?" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
