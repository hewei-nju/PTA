
#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 101;
const int INF = 65535;
struct GNode{
    int G[MaxSize][MaxSize];
    int numVertex;
    int numEdge;
};
using Graph = struct GNode *;
Graph _init_Graph(int numVertex, int numEdge);
Graph Floyd(Graph MyGraph);
void _show_Result(Graph MyGraph);
int main()
{
    int numVertex, numEdge;
    cin >> numVertex >> numEdge;
    Graph MyGraph = _init_Graph(numVertex, numEdge);
    MyGraph = Floyd(MyGraph);
    _show_Result(MyGraph);
    return 0;
}
Graph _init_Graph(int numVertex, int numEdge)
{
    Graph MyGraph = new (struct GNode);
    MyGraph->numVertex = numVertex;
    MyGraph->numEdge = numEdge;
    for (int v = 1; v <= numVertex; ++v) {
        for (int w = 1; w <= numVertex; ++w) {
            MyGraph->G[v][w] = v == w ? 0 : INF;
        }
    }
    int v, w, length;
    for (int e = 1; e <= numEdge; ++e) {
        cin >> v >> w >> length;
        MyGraph->G[v][w] = length;
        MyGraph->G[w][v] = length;
    }
    return MyGraph;
}
Graph Floyd(Graph MyGraph)
{
    for (int k = 1; k <= MyGraph->numVertex; ++k) {
        for (int v = 1; v <= MyGraph->numVertex; ++v) {
            for (int w = 1; w <= MyGraph->numVertex; ++w) {
                MyGraph->G[v][w] = min(MyGraph->G[v][w], MyGraph->G[v][k] + MyGraph->G[k][w]);
            }
        }
    }
    return MyGraph;
}
void _show_Result(Graph MyGraph)
{
    int Animal, MaxDist, MinDist = INF;
    for (int v = 1; v <= MyGraph->numVertex; ++v) {
        MaxDist = 0;
        for (int w = 1; w <= MyGraph->numVertex; ++w) {
            if (MyGraph->G[v][w] == INF) {
                cout << 0 << endl;
                return;
            } else if (MaxDist < MyGraph->G[v][w]) {
                MaxDist = MyGraph->G[v][w];
            }
        }
        if (MinDist > MaxDist) {
            MinDist = MaxDist;
            Animal = v;
        }
    }
    cout << Animal << " " << MinDist << endl;
}