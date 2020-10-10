#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 1001;
static bool Visited[MaxSize];
struct GNode {
    int NumVertex;
    int NumEdge;
    vector<int> G[MaxSize];
};

using Graph = struct GNode *;

Graph BuildGraph(int numvertex, int numedge)
{
    Graph MyGraph = new (struct GNode);
    MyGraph->NumVertex = numvertex;
    MyGraph->NumEdge = numedge;
    int v, w;
    for (int e = 1; e <= MyGraph->NumEdge; ++e) {
        cin >> v >> w;
        MyGraph->G[v].push_back(w);
        MyGraph->G[w].push_back(v);
    }
    return MyGraph;
}

void InitializedVisted() 
{
    for (int i = 0; i <= MaxSize; ++i) {
        Visited[i] = false;
    }
}

int TraverseGraph(Graph MyGraph, int v)
{
    int cnt = 0, level = 0;
    queue<int> Q { };
    Q.push(v);
    int circle_times = 1;
    int helper = 0;
    while (Q.size() > 0 && level < 6) {
        v = Q.front();
        Q.pop();
        for (int w = 0; w <= MyGraph->G[v].size() - 1; ++w) {
            if (!Visited[MyGraph->G[v][w]]) {
                Q.push(MyGraph->G[v][w]);
                helper += 1;
                cnt += 1;
                Visited[MyGraph->G[v][w]] = true;
            }
        }
        circle_times -= 1;
        if (circle_times == 0) {
            ++level;
            circle_times = helper;
            helper = 0;
        }
    }
    return cnt;
}


int main ()
{
    int n, m;
    cin >> n >> m;
    Graph MyGraph = BuildGraph(n, m);
    for (int v = 1; v <= MyGraph->NumVertex; ++v) {
        InitializedVisted();
        int cnt = TraverseGraph(MyGraph, v);
        cout << v << ": " << fixed << setprecision(2) << double(cnt) * 100 / n << "%"  << endl;
    }
    return 0;
}