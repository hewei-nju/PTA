#include <bits/stdc++.h>
using namespace std;

struct UNode {  //用户节点
    int arrival_Time;
    int start_time;
    int need_time;
    int end_time;
    //struct UNode *next;
};
using User = struct UNode *;

struct TNode {
    User *users;
    int cnt;
};
using Team = struct TNode *;

struct WNode {
    int TAG;
    User user;
    int user_cnt;
    //struct WNode *next;
};
using Window = struct WNode *;

struct BNode {
    Window *windows;
    int cnt;
};
using Bank = struct BNode *;

Team _init_Team();  //获取初始队伍
Bank _init_Bank();  //获得银行及窗口编号
Bank _solve_problems_(Team team, Bank bank, double &ave_time, int &max_time, int &last_time);
int main()
{
    double ave_time = 0;
    int tag = 0, max_time = 0, last_time = 0;
    Team team = _init_Team();
    Bank bank = _init_Bank();
    bank = _solve_problems_(team, bank, ave_time, max_time, last_time);
    cout << fixed << setprecision(1) << ave_time << " " << max_time << " " << last_time << endl;
    for (tag = 0; tag <= bank->cnt - 2; ++tag) {
        cout << bank->windows[tag]->user_cnt << " ";
    }
    cout << bank->windows[tag]->user_cnt << endl;
    return 0;
}

Team _init_Team()  //获取初始队伍
{
    int n;
    cin >> n;
    Team team = new (struct TNode);
    team->users = new User[n];
    team->cnt = n;
    for (int i = 0; i <= n - 1; ++i) {
        User user = new (struct UNode);
        cin >> user->arrival_Time >> user->need_time;
        team->users[i] = user;
    }
    return team;
}
Bank _init_Bank()  //获得银行及窗口编号
{
    int n;
    cin >> n;
    Bank bank = new (struct BNode);
    bank->windows = new Window[n];
    bank->cnt = n;
    for (int i = 0; i <= n - 1; ++i) {
        Window window = new (struct WNode);
        window->TAG = i + 1;
        window->user = nullptr;
        window->user_cnt = 0;
        bank->windows[i] = window;
    }
    return bank;
}
Bank _solve_problems_(Team team, Bank bank, double &ave_time, int &max_time, int &last_time)
{
    //assert(team->users[0]->arrival_Time == 0);
    for (int i = 0; i <= team->cnt - 1; ++i) {
        int wait_min = 1024;  // 超出处理时间，哈哈哈,为啥弄成61不行？刚好卡一个case？以后就往大了弄，giao~
        int Tag;
        bool isSolving = false;
        if (team->users[i]->need_time > 60) {
            team->users[i]->need_time = 60;
        }
        for (int j = 0; j <= bank->cnt - 1; ++j) {
            if (bank->windows[j]->user == nullptr || bank->windows[j]->user->end_time <= team->users[i]->arrival_Time) {
                team->users[i]->start_time = team->users[i]->arrival_Time;
                team->users[i]->end_time = team->users[i]->start_time + team->users[i]->need_time;
                bank->windows[j]->user = team->users[i];
                bank->windows[j]->user_cnt += 1;
                isSolving = true;
                break;
            } else {
                if (wait_min > (bank->windows[j]->user->end_time - team->users[i]->arrival_Time)) {
                    wait_min = bank->windows[j]->user->end_time - team->users[i]->arrival_Time;
                    Tag = bank->windows[j]->TAG;
                }
            }
        }
        if (!isSolving) {
            team->users[i]->start_time = team->users[i]->arrival_Time + wait_min;
            team->users[i]->end_time = team->users[i]->start_time + team->users[i]->need_time;
            bank->windows[Tag-1]->user = team->users[i];
            bank->windows[Tag-1]->user_cnt += 1;
            if (wait_min > max_time) {
                max_time = wait_min;
            }
            ave_time += wait_min;
        }
        if (last_time < team->users[i]->end_time) {
            last_time = team->users[i]->end_time;
        }
    }
    ave_time /= (double)team->cnt;
    return bank;
}