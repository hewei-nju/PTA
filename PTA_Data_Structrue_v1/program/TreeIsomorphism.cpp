#include <bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    int left;
    int right;
    bool isVisited;
};
using Vertex = struct Node *;
struct TNode {
    Vertex *vertex;
    int size;
};
using Tree = struct TNode *;
Tree _init_Tree();
void isSomorphism(Tree tree1, Tree tree2);
int main()
{
    Tree tree1 = _init_Tree();
    Tree tree2 = _init_Tree();
    isSomorphism(tree1, tree2);
    return 0;
}
Vertex FindRoot(Tree tree)
{
    for(int i = 0; i <= tree->size - 1; ++i) {
        bool find = true;
        for (int j = 0; j <= tree->size - 1; ++j) {
            if (tree->vertex[j]->left != -1) {
                if (tree->vertex[tree->vertex[j]->left]->data == tree->vertex[i]->data) {
                    find = false;
                }
            } else if (tree->vertex[j]->right != -1) {
                if (tree->vertex[tree->vertex[j]->right]->data == tree->vertex[i]->data) {
                    find = false;
                }
            }
        }
        if (find) {
            return tree->vertex[i];
        }
    }
}
Tree _init_Tree()
{
    int n;
    scanf("%d\n", &n);
    Tree tree = new (struct TNode);
    tree->size = n;
    tree->vertex = new Vertex[n];
    string line;
    char left, right;
    for (int i = 0; i <= n - 1; ++i) {
        Vertex v = new (struct Node);
        getline(cin, line);
        v->data = (char)line.c_str()[0];
        left = (char)line.c_str()[2];
        right = (char)line.c_str()[4];
        if (left == '-') {
            v->left = -1;
        } else {
            v->left = left - '0';
        }
        if (right == '-') {
            v->right = -1;
        } else {
            v->right = right - '0';
        }
        v->isVisited = false;
        tree->vertex[i] = v;
    }
    return tree;
}
void isSomorphism(Tree tree1, Tree tree2)
{
    if (tree1->size != tree2->size) {
        cout << "No" << endl;
        return;
    } else if (tree1->size == 0) {
        cout << "Yes" << endl;
        return;
    }
    queue<Vertex> que1 { };
    queue<Vertex> que2 { };
    que1.push(FindRoot(tree1));
    for (int i = 0; i <= tree2->size - 1; ++i) {
        if (tree2->vertex[i]->data == tree1->vertex[0]->data) {
            que2.push(tree2->vertex[i]);
            break;
        }
    }
    if (que2.empty()) {
        cout << "No" << endl;
        return;
    }
    while(!que1.empty()) {
        Vertex v1 = que1.front();
        que1.pop();
        Vertex v2 = que2.front();
        que2.pop();
        if (v1->left == -1 && v1->right == -1) {
            if (v2->left != -1 || v2->right != -1) {
                cout << "No" << endl;
                return;
            }
        } else if (v1->left != -1 && v1->right == -1) {
            if (v2->left == -1 && v2->right == -1 || v2->left != -1 && v2->right != -1) {
                cout << "No" << endl;
                return;
            } else if (v2->left == -1 && v2->right != -1) {
                if (tree1->vertex[v1->left]->data != tree2->vertex[v2->right]->data) {
                    cout << "No" << endl;
                    return;
                } else {
                    que1.push(tree1->vertex[v1->left]);
                    que2.push(tree2->vertex[v2->right]);
                }
            } else if (v2->left != -1 && v2->right == -1) {
                if (tree1->vertex[v1->left]->data != tree2->vertex[v2->left]->data) {
                    cout << "No" << endl;
                    return;
                } else {
                    que1.push(tree1->vertex[v1->left]);
                    que2.push(tree2->vertex[v2->left]);
                }
            }
        } else if (v1->left == -1 && v1->right != -1) {
            if (v2->left == -1 && v2->right == -1 || v2->left != -1 && v2->right != -1) {
                cout << "No" << endl;
                return;
            } else if (v2->left == -1 && v2->right != -1) {
                if (tree1->vertex[v1->right]->data != tree2->vertex[v2->right]->data) {
                    cout << "No" << endl;
                    return;
                } else {
                    que1.push(tree1->vertex[v1->right]);
                    que2.push(tree2->vertex[v2->right]);
                }
            } else if (v2->left != -1 && v2->right == -1) {
                if (tree1->vertex[v1->right]->data != tree2->vertex[v2->left]->data) {
                    cout << "No" << endl;
                    return;
                } else {
                    que1.push(tree1->vertex[v1->right]);
                    que2.push(tree2->vertex[v2->left]);
                }
            }
        } else if (v1->left != -1 && v1->right != -1) {
            if (v2->left == -1 || v2->right == -1) {
                cout << "No" << endl;
                return;
            } else {
                if (tree1->vertex[v1->left]->data == tree2->vertex[v2->left]->data && tree1->vertex[v1->right]->data == tree2->vertex[v2->right]->data) {
                    que1.push(tree1->vertex[v1->left]);
                    que2.push(tree2->vertex[v2->left]);
                    que1.push(tree1->vertex[v1->right]);
                    que2.push(tree2->vertex[v2->right]);
                } else if (tree1->vertex[v1->left]->data == tree2->vertex[v2->right]->data && tree1->vertex[v1->right]->data == tree2->vertex[v2->left]->data) {
                    que1.push(tree1->vertex[v1->left]);
                    que2.push(tree2->vertex[v2->right]);
                    que1.push(tree1->vertex[v1->right]);
                    que2.push(tree2->vertex[v2->left]);
                } else {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;   
}