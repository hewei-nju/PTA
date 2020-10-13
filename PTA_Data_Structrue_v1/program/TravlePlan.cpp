#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 500;
const int INF = 65535;
int shortPath[MaxSize];
int minCost[MaxSize];
struct ENode {
    int w;
    int length;
    int cost;
};
using Edge = struct ENode *;
struct VNode {
    vector<Edge> Vertexs;
    int size;
};
using Vertex = struct VNode;
struct GNode {
    Vertex *G;
    int numVertex;
    int numEdge;
};
using Graph = struct GNode*;
Graph _init_Graph(int numVertex, int numEdge);
void _init_shortPath();
void _init_Visited();
void Dijkstra(Graph MyGraph, int vertex);
int main ()
{
    int numVertex, numEdge, start, dest;
    cin >> numVertex >> numEdge >> start >> dest;
    Graph MyGraph = _init_Graph(numVertex, numEdge);
    Dijkstra(MyGraph, start);
    cout << shortPath[dest] << " " << minCost[dest] << endl;
    return 0;
}
Graph _init_Graph(int numVertex, int numEdge)
{
    Graph MyGraph = new (struct GNode);
    MyGraph->numVertex = numVertex;
    MyGraph->numEdge = numEdge;
    MyGraph->G = new Vertex[numVertex];
    for (int i = 0; i <= numVertex - 1; ++i) {
        MyGraph->G[i].size = 0;
    }
    int v, w, length, cost;
    Edge newEdge;
    for (int e = 0; e <= numEdge - 1; ++e) {
        cin >> v >> w >> length >> cost;
        newEdge = new (struct ENode);
        newEdge->w = v;
        newEdge->length = length;
        newEdge->cost = cost;
        MyGraph->G[w].Vertexs.push_back(newEdge);
        MyGraph->G[w].size += 1;
        newEdge = new (struct ENode);
        newEdge->w = w;
        newEdge->length = length;
        newEdge->cost = cost;
        MyGraph->G[v].Vertexs.push_back(newEdge);
        MyGraph->G[v].size += 1;
    }
    return MyGraph;
}
void _init_shortPath()
{
    for (int i = 0; i <= MaxSize - 1; ++i) {
        shortPath[i] = INF;
    }
}
void _init_minCost()
{
    for (int i = 0; i <= MaxSize - 1; ++i) {
        minCost[i] = INF;
    }
}
void Dijkstra(Graph MyGraph, int vertex)
{
    _init_shortPath();
    _init_minCost();
    bool Visited[MyGraph->numVertex];
    for (int i = 0; i <= MyGraph->numVertex - 1; ++i) {
        Visited[i] = false;
    }
    shortPath[vertex] = 0;
    minCost[vertex] = 0;
    Visited[vertex] = true;
    for (int i = 1; i <= MyGraph->numVertex - 1; ++i) {
        int k = -1; // 用来选出一个距离初始顶点vertex最近的未标记的顶点
        int dmin = INF;
        int cost;
        for (int j = 0; j <= MyGraph->G[vertex].size - 1; ++j) {
            int v = MyGraph->G[vertex].Vertexs[j]->w;
            if (!Visited[v] && MyGraph->G[vertex].Vertexs[j]->length < dmin) {
                dmin = MyGraph->G[vertex].Vertexs[j]->length;
                cost = MyGraph->G[vertex].Vertexs[j]->cost;
                k = v;
            }
        }
        //!将选出的顶点标记为以求的最短路径、且到start的最短路径就是dmin
        if (k != -1) {
            if (dmin < shortPath[k]) {
                shortPath[k] = dmin;
                minCost[k] = cost;
            }
            Visited[k] = true;
            //^以k为中间点，修正从start到未访问各点的距离

            for (int j = 0; j <= MyGraph->G[k].size - 1; ++j) {
                int w = MyGraph->G[k].Vertexs[j]->w;
                int length = MyGraph->G[k].Vertexs[j]->length;
                int costJ = MyGraph->G[k].Vertexs[j]->cost;
                if (!Visited[w] && shortPath[k] + length < shortPath[w]) {
                    shortPath[w] = shortPath[k] + length;
                    minCost[w] = minCost[k] + MyGraph->G[k].Vertexs[j]->cost;
                } else if (!Visited[w] && shortPath[k] + length == shortPath[w]) {
                    if ((minCost[k] + costJ) < minCost[w]) {
                        minCost[w] = minCost[k] + costJ;
                    }
                }
            }
        }
    }
}