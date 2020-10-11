#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 1000;
//*-----------------------------------------------------------
struct VNode{
    int AdjVertexs[MAXSIZE];
    int Size;
    int MaxSize;
};
using VertexNode = struct VNode*;
struct UNode{
    VertexNode *Vertexs;
    int MaxSize;
};
using Union = struct UNode*;
Union makeSet(int size);
int Find(Union the_Set, int vertex);
Union Merge(Union the_Set, int vertex1, int vertex2);
//^------------------------------------------------------------
struct ENode{
    int v;
    int w;
    int weight;
    int isBuilt;
};
using Edge = struct ENode*;
struct GNode{
    Edge *G;
    int numVertex;
    int numEdge;
};
using Graph = struct GNode*;
Graph _init_Graph_(int numVertex, int numEdge);
void Shell_sort(Graph MyGraph);
void min_cost(Graph MyGraph);
//bool cmp(Edge edge1, Edge edge2);
//!-------------------------------------------------------------
int main()
{
    int numVertex, numEdge;
    cin >> numVertex;
    numEdge = numVertex * (numVertex - 1) / 2;
    Graph MyGraph = _init_Graph_(numVertex, numEdge);
    min_cost(MyGraph);
    return 0;
}


Union makeSet(int numVertex)
{
    Union set = new (struct UNode);
    set->Vertexs = new VertexNode[numVertex];
    for (int i = 0; i <= numVertex - 1; ++i) {
        set->Vertexs[i] = new (struct VNode);
        set->Vertexs[i]->MaxSize = numVertex;
        set->Vertexs[i]->Size = 0;
    }
    set->MaxSize = numVertex;
    return set;
}
int Find(Union set, int vertex)
{
    for (int i = 0; i <= set->MaxSize - 1; ++i) {
        for (int j = 0; j <= set->Vertexs[i]->Size - 1; ++j) {
            if (set->Vertexs[i]->AdjVertexs[j] == vertex) {
                return i;
            }
        }
    }
    return -1;
}
Union Merge(Union set, int vertex1, int vertex2)
{
    if (Find(set, vertex1) != Find(set, vertex2) && Find(set, vertex1) != -1 && Find(set, vertex2) != -1) {
        int i = Find(set, vertex1);
        int j = Find(set, vertex2);
        for (int k = 0; k <= set->Vertexs[j]->Size - 1; ++k) {
            set->Vertexs[i]->AdjVertexs[set->Vertexs[i]->Size++] = set->Vertexs[j]->AdjVertexs[k];
        }
        set->Vertexs[j]->Size = 0;
    } else if (Find(set, vertex1) == -1 && Find(set, vertex2) == -1) {
        set->Vertexs[vertex1]->AdjVertexs[set->Vertexs[vertex1]->Size++] = vertex1;
        set->Vertexs[vertex1]->AdjVertexs[set->Vertexs[vertex1]->Size++] = vertex2;
    } else if (Find(set, vertex1) == -1 && Find(set, vertex2) != -1) {
        int i = Find(set, vertex2);
        set->Vertexs[i]->AdjVertexs[set->Vertexs[i]->Size++] = vertex1;
    } else if (Find(set, vertex1) != -1 && Find(set, vertex2) == -1) {
        int i = Find(set, vertex1);
        set->Vertexs[i]->AdjVertexs[set->Vertexs[i]->Size++] = vertex2;
    }
    return set;
}
//~-----------------------------------------------------------------
Graph _init_Graph_(int numVertex, int numEdge)
{
    Graph MyGraph = new (struct GNode);
    MyGraph->numVertex = numVertex;
    MyGraph->numEdge = numEdge;
    MyGraph->G = new Edge[numEdge];
    for (int e = 0; e <= numEdge - 1; ++e) {
        Edge newEdge = new (struct ENode);
        cin >> newEdge->v >> newEdge->w >> newEdge->weight >> newEdge->isBuilt;
        newEdge->v -= 1;
        newEdge->w -= 1;
        MyGraph->G[e] = newEdge;
       
    }
    return MyGraph;
}
void Shell_sort(Graph MyGraph)
{
    int gap = MyGraph->numEdge / 3;;
    while (gap >= 1) {
        for (int i = gap; i <= MyGraph->numEdge - 1; ++i) {
            for (int j = i; j >= gap && MyGraph->G[j]->weight < MyGraph->G[j - gap]->weight; j -= gap) {
                swap(MyGraph->G[j], MyGraph->G[j - gap]);
            }
        }
        gap = gap / 3;
    }
}
void min_cost(Graph MyGraph)
{
    int res = 0;
    Shell_sort(MyGraph);
    //sort(MyGraph->G, MyGraph->G+MyGraph->numEdge, cmp);
    Union set = makeSet(MyGraph->numVertex);
    int v, w;
     for (int e = 0; e <= MyGraph->numEdge - 1; ++e) {
        v = MyGraph->G[e]->v;
        w = MyGraph->G[e]->w;
        if (MyGraph->G[e]->isBuilt) {
            Merge(set, v, w);
        }
    }//! 这一步至关重要！！！
    for (int e = 0; e <= MyGraph->numEdge - 1; ++e) {
        v = MyGraph->G[e]->v;
        w = MyGraph->G[e]->w;
        if ((Find(set, v) == -1 && Find(set, v) == Find(set, w)) || Find(set, v) != Find(set, w)) {
            res += MyGraph->G[e]->weight;
            Merge(set, v, w);
        }
    }
    cout << res << endl;
}
/*bool cmp(Edge edge1, Edge edge2)
{
    return edge1->weight < edge2->weight;
}*/