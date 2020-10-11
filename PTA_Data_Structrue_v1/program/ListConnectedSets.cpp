#include <bits/stdc++.h>
using namespace std;
const int MaxSize = 10;
struct GNode{
    int G[MaxSize][MaxSize];
    int numVertex;
    int numEdge;
    bool *Visited;
};
using Graph = struct GNode*;
Graph _ini_Graph(int numVertex, int numEdge);
void PrintDFS(Graph MyGraph);
void PrintBFS(Graph MyGraph);
int main()
{
    int numVertex, numEdge;
    cin >> numVertex >> numEdge;
    Graph MyGraph = _ini_Graph(numVertex, numEdge);
    PrintDFS(MyGraph);
    for (int i = 0; i <= numVertex - 1; ++i) {
        MyGraph->Visited[i] = false;
    }
    PrintBFS(MyGraph);
    return 0;
}
Graph _ini_Graph(int numVertex, int numEdge)
{
    Graph MyGraph = new (struct GNode);
    MyGraph->numEdge = numEdge;
    MyGraph->numVertex = numVertex;
    MyGraph->Visited = new bool[numVertex];
    for (int v = 0; v <= numVertex - 1; ++v) {
        MyGraph->G[v][v] = 1;
        MyGraph->Visited[v] = false;
    }
    int v, w;
    for (int i = 0; i <= numEdge - 1; ++i) {
        cin >> v >> w;
        MyGraph->G[v][w] = 1;
        MyGraph->G[w][v] = 1;
    }
    return MyGraph;
}
void PrintDFS(Graph MyGraph)
{
    for (int v = 0; v <= MyGraph->numVertex - 1; ++v) {
        int vertexs[MyGraph->numVertex], size = 0;
        if (!MyGraph->Visited[v]) {
            stack<int> VStack { };
            VStack.push(v);
            MyGraph->Visited[v] = true;
            vertexs[size++] = v;
            while(!VStack.empty()) {
                int w = VStack.top();
                //VStack.pop();
                bool NeedPop = true;
                for (int i = 0; i <= MyGraph->numVertex - 1; ++i) {
                    if (!MyGraph->Visited[i] && MyGraph->G[w][i] == 1) {
                        NeedPop = false;
                        VStack.push(i);
                        MyGraph->Visited[i] = true;
                        vertexs[size++] = i;
                        break;
                    }
                }
                if (NeedPop) {
                    VStack.pop();
                }
            }
            cout << "{";
            for (int i = 0; i <= size - 1; ++i) {
                cout << " " << vertexs[i];
            }       
            cout << " }" << endl;
        }
    }
}
void PrintBFS(Graph MyGraph)
{
    for (int v = 0; v <= MyGraph->numVertex - 1; ++v) {
        int vertexs[MyGraph->numVertex], size = 0;
        if (!MyGraph->Visited[v]) {
            queue<int> que { };
            que.push(v);
            MyGraph->Visited[v] = true;
            vertexs[size++] = v;
            while (!que.empty()) {
                int w = que.front();
                que.pop();
                for (int i = 0; i <= MyGraph->numVertex - 1; ++i) {
                    if (!MyGraph->Visited[i] && MyGraph->G[w][i] == 1) {
                        que.push(i);
                        MyGraph->Visited[i] = true;
                        vertexs[size++] = i;
                    }
                }
            }
            cout << "{";
            for (int i = 0; i <= size - 1; ++i) {
                cout << " " << vertexs[i];
            }
            cout << " }" << endl;
        }
    }
}
