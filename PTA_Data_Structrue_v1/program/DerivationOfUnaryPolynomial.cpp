#include <bits/stdc++.h>
using namespace std;
void Derivation();

int main()
{
    Derivation();
    return 0;
}
void Derivation()
{
    int coe, index;
    int flag = 0;
    while(cin.peek() != '\n') {
        cin >> coe >> index;
        if (index != 0) {
            if (flag == 1) {
                cout << " ";
            }
            cout << coe * index << " " << index - 1;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "0 0";
    }
    cout << endl;
}