#include <iostream>
const int MaxSize = 1000;

struct SNode {
    int num;
    char origin;
    char trans;
    char destination;
};


int main()
{
    /**clock_t start, end;
    start = clock();
    ofstream outfile;
    outfile.open("data.txt", ios::trunc);*/
    int n;
    std::cin >> n;
    struct SNode S[MaxSize];
    int Top = 0;
    S[0].num = n;
    S[0].origin = 'a';
    S[0].trans = 'b';
    S[0].destination = 'c';
    while(Top >= 0) {
        struct SNode tmp = S[Top--];
        if(tmp.num == 1) {
            std::cout << tmp.origin << " -> " << tmp.destination << std::endl;
        } else {
            Top += 1;
            S[Top].num = tmp.num - 1;
            S[Top].origin = tmp.trans;
            S[Top].trans = tmp.origin;
            S[Top].destination = tmp.destination;
            Top += 1;
            S[Top].num = 1;
            S[Top].origin = tmp.origin;
            S[Top].trans = tmp.trans;
            S[Top].destination = tmp.destination;
            Top += 1;
            S[Top].num = tmp.num - 1;
            S[Top].origin = tmp.origin;
            S[Top].trans = tmp.destination;
            S[Top].destination = tmp.trans;
        }
    }
    /**outfile.close();
    end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << endl;
    return 0;*/
}

