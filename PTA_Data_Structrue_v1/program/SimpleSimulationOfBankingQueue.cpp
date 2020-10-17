#include <bits/stdc++.h>
using namespace std;
void Simulation();
int main()
{
    Simulation();
    return 0;
}

void Simulation()
{
    int n, m, curSizeA = 0, flag = 0, cnt = 0;
    cin >> n;
    queue<int> QueA;
    queue<int> QueB;
    for (int i = 0; i <= n - 1; ++i) {
        cin >> m;
        if (m % 2 == 0) {
            QueB.push(m);
        } else {
            QueA.push(m);
        }
    }
    if (!QueA.empty()) {
        cout << QueA.front();
        QueA.pop();
        curSizeA += 1;
        --n;
    } else {
        cout << QueB.front();
        QueB.pop();
        flag = 1;
        --n;
    }
    while (n > 0) {
        if (QueA.empty()) {
            if (!QueB.empty()) {
                cout << " " << QueB.front();
                QueB.pop();
                --n;
            }
        } else if (QueB.empty()) {
            if (!QueA.empty()) {
                cout << " " << QueA.front();
                QueA.pop();
                --n;
            }
        } else if (curSizeA % 2 == 0 && flag == 0) {
            cout << " " << QueB.front();
            QueB.pop();
            flag = 1;
            --n;
        } else {
            cout << " " << QueA.front();
            QueA.pop();
            curSizeA += 1;
            if (curSizeA % 2 == 0) {
                flag = 0;
            }
            --n;
        }
    }
}