#include <bits/stdc++.h>
using namespace std;
struct UNode{
    string name;
    int arrival_time;
    int need_time;
    int circle;
    bool isSolved;
};
using User = struct UNode*;
struct TNode{
    User *Queue;
    int front = -1;
    int rear = -1;
};
using Team = struct TNode*;
struct WNode{
    User user;
    int end_time;
    string *order;
    int front = -1;
    int rear = -1;
};
using Window = struct WNode*;

Team _init_Team_(int n, int m);
Window _init_Window(int n);
double _solve_Problems_(Team team, Window window);

int main()
{
    int n, m;
    cin >> n >> m;
    Team team = _init_Team_(n, m);
    Window window = _init_Window(n);
    double avg = _solve_Problems_(team, window);
    cout << fixed << setprecision(1) << avg << endl;
    return 0;
}

Team _init_Team_(int n, int m)
{
    Team team = new (struct TNode);
    team->Queue = new User[n];
    unordered_map<string, int> Circle{ };
    for (int i = 0; i <= m - 1; ++i) {
        int num;
        string name;
        cin >> num;
        for (int j = 0; j <= num - 1; ++j) {
            cin >> name;
            Circle.insert(make_pair(name, i));
        }
    }
    for (int i = 0; i <= n - 1; ++i) {
        User user = new (struct UNode);
        cin >> user->name >> user->arrival_time >> user->need_time;
        if (user->need_time > 60) {
            user->need_time = 60;
        }
        user->isSolved = false;
        auto search = Circle.find(user->name);
        if (search != Circle.end()) {
            user->circle = search->second;
        } else {
            user->circle = -1;
        }
        team->Queue[++team->rear] = user;
    }
    return team;
}
Window _init_Window(int n)
{
    Window window = new (struct WNode);
    window->order = new string[n];
    window->end_time = 0;
    window->user = nullptr;
    return window;
}
double _solve_Problems_(Team team, Window window)
{
    double sum_time = 0;
    while (team->front != team->rear) {
        int curPos = team->front + 1;
        if (team->Queue[curPos]->isSolved) {
            team->front += 1;
            continue;
        } else {
            if (window->user == nullptr || window->end_time <= team->Queue[curPos]->arrival_time) {
                team->Queue[curPos]->isSolved = true;
                window->end_time = team->Queue[curPos]->arrival_time + team->Queue[curPos]->need_time;
                window->user = team->Queue[curPos];
                window->order[++window->rear] = window->user->name;
            } else {
                for (int pos = curPos; pos <= team->rear; ++pos) {
                    if (!team->Queue[pos]->isSolved && team->Queue[pos]->circle != -1 && team->Queue[pos]->circle == window->user->circle && team->Queue[pos]->arrival_time <= window->end_time) {
                        sum_time += window->end_time - team->Queue[pos]->arrival_time;
                        team->Queue[pos]->isSolved = true;
                        window->end_time = window->end_time + team->Queue[pos]->need_time;
                        window->user = team->Queue[pos];
                        window->order[++window->rear] = window->user->name;
                    } else if (team->Queue[pos]->arrival_time >= window->end_time){
                        break;
                    }
                }
                if (!team->Queue[curPos]->isSolved) {
                    sum_time += window->end_time - team->Queue[curPos]->arrival_time;
                    team->Queue[curPos]->isSolved = true;
                    window->end_time = window->end_time + team->Queue[curPos]->need_time;
                    window->user = team->Queue[curPos];
                    window->order[++window->rear] = window->user->name;
                }
            }
        }
    }
    while (window->front != window->rear) {
        window->front += 1;
        cout << window->order[window->front] << endl;
    }
    return sum_time / (window->rear+1);
}