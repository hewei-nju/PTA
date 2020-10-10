#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 1001;
struct UNode {  //用户节点
    int isVIP;
    int arrival_time;
    int start_time;
    int need_time;
    int end_time;
    bool isSovlved;
};
using User = struct UNode *;

struct TNode {
    User Queue[MaxSize];
    int front = -1;
    int rear = -1;
};
using Team = struct TNode *;

struct WNode {
    int tag;
    User user;
    int user_cnt;
};
using Window = struct WNode *;

struct BNode {
    Window *windows;
    int vipWindow;
    int cnt;
};
using Bank = struct BNode *;

Team _init_Team(int n);  //获取初始队伍
Bank _init_Bank();  //获得银行及窗口编号
Bank _solve_problems_(Team team, Bank bank, double &ave_time, int &max_time, int &last_time);
int main()
{
    int n;
    cin >> n;
    double sum_time = 0;
    int tag = 0, max_time = 0, last_time = 0;
    Team team = _init_Team(n);
    Bank bank = _init_Bank();
    bank = _solve_problems_(team, bank, sum_time, max_time, last_time);
    cout << fixed << setprecision(1) << sum_time / n << " " << max_time << " " << last_time << endl;
    for (tag = 0; tag <= bank->cnt - 2; ++tag) {
        cout << bank->windows[tag]->user_cnt << " ";
    }
    cout << bank->windows[tag]->user_cnt << endl;
    return 0;
}

Team _init_Team(int n)  //获取初始队伍
{
    Team team = new (struct TNode);
    for (int i = 0; i <= n - 1; ++i) {
        User user = new (struct UNode);
        cin >> user->arrival_time >> user->need_time >> user->isVIP;
        user->isSovlved = false;
        if (user->need_time > 60) {
            user->need_time = 60;
        }
        team->Queue[++team->rear] = user;
    }
    return team;
}
Bank _init_Bank()  //获得银行及窗口编号
{
    int n, vip;
    cin >> n >> vip;
    Bank bank = new (struct BNode);
    bank->windows = new Window[n];
    bank->cnt = n;
    bank->vipWindow = vip;
    for (int i = 0; i <= n - 1; ++i) {
        Window window = new (struct WNode);
        window->tag = i;
        window->user = nullptr;
        window->user_cnt = 0;
        bank->windows[i] = window;
    }
    return bank;
}
Bank _solve_problems_(Team team, Bank bank, double &sum_time, int &max_time, int &last_time)
{
    while (team->front != team->rear) {
        int curPos = team->front + 1;
        if (team->Queue[curPos]->isSovlved) {
            team->front += 1;
            continue;
        } else {
            bool HasNullWindow = false;
            int NullWindow = -1;
            int wait_min = 2147483647;
            int min_end_time_window = -1;
            for (int i = 0; i <= bank->cnt - 1; ++i) {
                if (bank->windows[i]->user == nullptr || bank->windows[i]->user->end_time <= team->Queue[curPos]->arrival_time) {
                    HasNullWindow = true;
                    NullWindow = i;
                    break;
                } else {
                    if (wait_min > (bank->windows[i]->user->end_time - team->Queue[curPos]->arrival_time)) {
                        wait_min = bank->windows[i]->user->end_time - team->Queue[curPos]->arrival_time;
                        min_end_time_window = i;
                    }
                }
            }
            if (HasNullWindow) {
                int Pos = curPos;
                if (!team->Queue[Pos]->isVIP) {
                    for (int i = 0; i <= team->rear - 1; ++i) {
                        if (team->Queue[i]->isSovlved) {
                            continue;
                        }else if (team->Queue[i]->arrival_time != team->Queue[i+1]->arrival_time) {
                            break;
                        } else if (team->Queue[i]->isVIP) {
                            Pos = i;
                            break;
                        }
                    }
                }
                if (Pos != curPos) {
                    if (bank->windows[bank->vipWindow]->user == nullptr || bank->windows[bank->vipWindow]->user->end_time <= team->Queue[Pos]->arrival_time) {
                        team->Queue[Pos]->start_time = team->Queue[Pos]->arrival_time;
                        team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                        team->Queue[Pos]->isSovlved = true;
                        if (last_time < team->Queue[Pos]->end_time) {
                            last_time = team->Queue[Pos]->end_time;
                        }
                        bank->windows[bank->vipWindow]->user = team->Queue[Pos];
                        bank->windows[bank->vipWindow]->user_cnt += 1;
                    }
                    Pos = curPos;
                } else {
                    if (team->Queue[Pos]->isVIP && (bank->windows[bank->vipWindow]->user == nullptr || bank->windows[bank->vipWindow]->user->end_time <= team->Queue[Pos]->arrival_time)) {
                        team->Queue[Pos]->start_time = team->Queue[Pos]->arrival_time;
                        team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                        team->Queue[Pos]->isSovlved = true;
                        if (last_time < team->Queue[Pos]->end_time) {
                            last_time = team->Queue[Pos]->end_time;
                        }
                        bank->windows[bank->vipWindow]->user = team->Queue[Pos];
                        bank->windows[bank->vipWindow]->user_cnt += 1;
                    } else {
                        team->Queue[Pos]->start_time = team->Queue[Pos]->arrival_time;
                        team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                        team->Queue[Pos]->isSovlved = true;
                        if (last_time < team->Queue[Pos]->end_time) {
                            last_time = team->Queue[Pos]->end_time;
                        }
                        bank->windows[NullWindow]->user = team->Queue[Pos];
                        bank->windows[NullWindow]->user_cnt += 1;
                    }
                }
            } else {
                if (wait_min == (bank->windows[bank->vipWindow]->user->end_time - team->Queue[curPos]->arrival_time)) { //*****
                    int Pos = curPos;
                    for (int i = Pos; i <= team->rear - 1; ++i) {
                        if (team->Queue[i]->isSovlved) {
                            continue;
                        }else if (bank->windows[bank->vipWindow]->user->end_time < team->Queue[i]->arrival_time) {
                            break;
                        } else if (team->Queue[i]->isVIP) {
                            Pos = i;
                            break;
                        }
                    }
                    if (team->Queue[Pos]->isVIP) {
                        wait_min = bank->windows[bank->vipWindow]->user->end_time - team->Queue[Pos]->arrival_time;
                        team->Queue[Pos]->start_time = bank->windows[bank->vipWindow]->user->end_time;
                        team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                        team->Queue[Pos]->isSovlved = true;
                        if (last_time < team->Queue[Pos]->end_time) {
                            last_time = team->Queue[Pos]->end_time;
                        }
                        bank->windows[bank->vipWindow]->user = team->Queue[Pos];
                        bank->windows[bank->vipWindow]->user_cnt += 1;
                    } else {
                        team->front += 1;
                        team->Queue[Pos]->start_time = bank->windows[min_end_time_window]->user->end_time;
                        team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                        team->Queue[Pos]->isSovlved = true;
                        if (last_time < team->Queue[Pos]->end_time) {
                            last_time = team->Queue[Pos]->end_time;
                        }
                        bank->windows[min_end_time_window]->user = team->Queue[Pos];
                        bank->windows[min_end_time_window]->user_cnt += 1;
                    }
                } else {
                    team->front += 1;
                    int Pos = curPos;
                    team->Queue[Pos]->start_time = bank->windows[min_end_time_window]->user->end_time;
                    team->Queue[Pos]->end_time = team->Queue[Pos]->start_time + team->Queue[Pos]->need_time;
                    team->Queue[Pos]->isSovlved = true;
                    if (last_time < team->Queue[Pos]->end_time) {
                        last_time = team->Queue[Pos]->end_time;
                    }
                    bank->windows[min_end_time_window]->user = team->Queue[Pos];
                    bank->windows[min_end_time_window]->user_cnt += 1;
                }
                if (max_time < wait_min) {
                    max_time = wait_min;
                }
                sum_time += wait_min;
            }
        }
    }
    return bank;
}