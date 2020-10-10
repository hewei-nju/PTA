#include <bits/stdc++.h>
using namespace std;

const int MaxSize = 50;
struct SNode {
    string Data[MaxSize];
    int Top;
};

struct LNode {
    string Data[MaxSize];
    int Front;
    int Rear;
};

using Stack = struct SNode*;
using List = struct LNode*;

Stack CreateStack()
{
    Stack S = new (struct SNode);
    S->Top = -1;
    return S;
}

bool StackIsFull(Stack S)
{
    return S->Top == MaxSize - 1;
}

bool StackIsEmpty(Stack S)
{
    return S->Top == -1;
}

void Push(Stack S, const string &str)
{
    if (StackIsFull(S)) {
        cout << "堆栈已满！" << endl;
        return;
    }
    S->Data[++S->Top] = str;
}

string Pop(Stack S)
{
    if (StackIsEmpty(S)) {
        return "Stack Is Empty!";
    }
    return S->Data[S->Top--];
}

List CreateList()
{
    List L = new (struct LNode);
    L->Front = -1;
    L->Rear = -1;
    return L;
}

bool ListIsFull(List L)
{
    return (L->Rear == (L->Front - 1 + MaxSize) % MaxSize);
}

bool ListIsEmpty(List L)
{
    return (L->Front == L->Rear);
}

void Add(List L, const string str)
{
    if (ListIsFull(L)) {
        cout << "List Is Full" << endl;
        return;
    }
    L->Rear = (L->Rear + 1) % MaxSize;
    L->Data[L->Rear] = str;
}

string Delete(List L)
{
    if (ListIsEmpty(L)) {
        return "List Is Empty!";
    }
    L->Front = (L->Front + 1) % MaxSize;
    return L->Data[L->Front];
}

vector<string> PreTreatment(string str)
{
    vector<string> res;
    for (int i = 0; i <= str.size() - 1; ) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (i == 0) {
                if (str[i] == '-') {
                    int j = i + 1;
                    for ( ; j <= str.size() - 1; ++j) {
                        if (str[j] == '(' || str[j] == ')' || str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/') {
                            break;
                        }
                    }
                    string s = "";
                    for (; i <= j - 1; ++i) {
                        s += str[i];
                    }
                    res.push_back(s);
                } else if (str[i] == '+') {
                    i += 1;
                    int j = i + 1;
                    for ( ; j <= str.size() - 1; ++j) {
                        if (str[j] == '(' || str[j] == ')' || str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/') {
                            break;
                        }
                    }
                    string s = "";
                    for (; i <= j - 1; ++i) {
                        s += str[i];
                    }
                    res.push_back(s);
                } else if (str[i] == '(') {
                    int j = i + 1;
                    if (str[j] == '-') {
                        i = j;
                        for (j += 1; j <= str.size() - 1; ++j) {
                            if (str[j] == ')') {
                                break;
                            }
                        }
                        string s = "";
                        for (; i <= j - 1; ++i) {
                            s += str[i];
                        }
                        res.push_back(s);
                    } else if (str[j] == '+') {
                        i = j + 1;
                        for (j += 1; j <= str.size() - 1; ++j) {
                            if (str[j] == ')') {
                                break;
                            }
                        }
                        string s = "";
                        for (; i <= j - 1; ++i) {
                            s += str[i];
                        }
                        res.push_back(s);
                    } else {
                        string s = "";
                        s += str[i];
                        res.push_back(s);
                        ++i;
                    }
                } 
            } else if (str[i] == '(') {
                int j = i + 1;
                if (str[j] == '-') {
                    i = j;
                    for (j += 1; j <= str.size() - 1; ++j) {
                        if (str[j] == ')') {
                            break;
                        }
                    }
                    string s = "";
                    for (; i <= j - 1; ++i) {
                        s += str[i];
                    }
                    res.push_back(s);
                } else if (str[j] == '+') {
                    i = j + 1;
                    for (j += 1; j <= str.size() - 1; ++j) {
                        if (str[j] == ')') {
                            break;
                        }
                    }
                    string s = "";
                       for (; i <= j - 1; ++i) {
                        s += str[i];
                    }
                    res.push_back(s);
                } else {
                    string s = "";
                    s += str[i];
                    res.push_back(s);
                    ++i;
                }
            } else {
                string s = "";
                s += str[i];
                res.push_back(s);
                ++i;
            }
        } else if (str[i] <= '9' && str[i] >= '0') {
            int j = i + 1;
            for ( ; j <= str.size() - 1; ++j) {
                if (str[j] == '(' || str[j] == ')' || str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/') {
                    break;
                }
            }
            string s = "";
            for (; i <= j - 1; ++i) {
                    s += str[i];
            }
            res.push_back(s);
        }
    }
    return res;
}

int main () 
{
    string in;
    //cin >> expression;
    getline(cin, in);
    Stack opStack = CreateStack();
    List reversepolish = CreateList();
    vector<string> expression = PreTreatment(in);
    int len = expression.size();
    for (int i = 0; i <= len - 1; ++i) {
        string str { expression[i] };
        if (expression[i] == "(") {
            Push(opStack, str);
        } else if (expression[i] == ")") {
            while (!StackIsEmpty(opStack)) {
                string op = Pop(opStack);
                if (op == "(") {
                    break;
                } else {
                    Add(reversepolish, op);
                }
            }
        } else if (expression[i] == "+" || expression[i] == "-" || expression[i] == "/" || expression[i] == "*"){
            while (!StackIsEmpty(opStack)) {
                string op = Pop(opStack);
                if (op == "(") {
                    Push(opStack, op);
                    Push(opStack, str);
                    break;
                } else if ((op == "+" || op == "-") && (str == "*" || str == "/")) {
                    Push(opStack, op);
                    Push(opStack, str);
                    break;
                } else {
                    Add(reversepolish, op);
                }
            }
            if(StackIsEmpty(opStack)) {
                Push(opStack, str);
            }
        } else {
            Add(reversepolish, str);
        }
    }

    while(!StackIsEmpty(opStack)) {
        Add(reversepolish, Pop(opStack));
    }

    int i = 1;
    while (!ListIsEmpty(reversepolish)) {
        string out = Delete(reversepolish);
        if (i == 1) {
            cout << out;
        } else {
        cout << " " << out;
        }
        ++i;
    }

    return 0;
}
