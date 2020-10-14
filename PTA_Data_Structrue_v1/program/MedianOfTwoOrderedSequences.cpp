#include <bits/stdc++.h>
using namespace std;
void Median(int n);
int main()
{
    int n;
    cin >> n;
    Median(n);
    return 0;
}
void Median(int n)
{
    vector<int> list1;
    vector<int> list2;
    vector<int> Union;
    int pos1 = 0, pos2 = 0;
    int num;
    for (int i = 0; i <= n - 1; ++i) {
        cin >> num;
        list1.push_back(num);
    }
    for (int i = 0; i <= n - 1; ++i) {
        cin >> num;
        list2.push_back(num);
    }
    while (pos1 != list1.size() || pos2 != list2.size()) {
        if (pos1 == list1.size()) {
            Union.push_back(list2[pos2]);
            pos2 += 1;
        } else if (pos2 == list2.size()) {
            Union.push_back(list1[pos1]);
            pos1 += 1;
        } else if (list1[pos1] < list2[pos2]) {
            Union.push_back(list1[pos1]);
            pos1 += 1;
        } else if (list2[pos2] < list1[pos1]) {
            Union.push_back(list2[pos2]);
            pos2 += 1;
        } else if (list1[pos1] == list2[pos2]) {
            Union.push_back(list1[pos1]);
            Union.push_back(list2[pos2]);
            pos1 += 1;
            pos2 += 1;
        }
    }
    cout << Union[(Union.size()-1)/2] << endl;
}
/*#include <bits/stdc++.h>
using namespace std;
void Median(int n);
int main()
{
    int n;
    cin >> n;
    Median(n);
    return 0;
}
void Median(int n)
{
    int list1[100001];
    int list2[100001];
    int Union[200001];
    int pos1 = 0, pos2 = 0, pos3 = 0;
    for (int i = 0; i <= n - 1; ++i) {
        cin >> list1[i];
    }
    for (int i = 0; i <= n - 1; ++i) {
        cin >> list2[i];
    }
    while (pos1 != n || pos2 != n) {
        if (pos1 == n) {
            Union[pos3++] = list2[pos2];
            pos2 += 1;
        } else if (pos2 == n) {
            Union[pos3++] = list1[pos1];
            pos1 += 1;
        } else if (list1[pos1] < list2[pos2]) {

            Union[pos3++] = list1[pos1];
            pos1 += 1;
        } else if (list2[pos2] < list1[pos1]) {
            Union[pos3++] = list2[pos2];
            pos2 += 1;
        } else if (list1[pos1] == list2[pos2]) {
            Union[pos3++] = list1[pos1];
            Union[pos3++] = list2[pos2];
            pos1 += 1;
            pos2 += 1;
        }
    }
    cout << Union[(pos3-1)/2] << endl;
}*/