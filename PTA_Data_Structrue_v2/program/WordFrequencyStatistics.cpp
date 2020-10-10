#include <bits/stdc++.h>

using namespace std;
/*用来存储单词和它的频数的节点*/
const int MaxSize = 1831;
static int wordcount = 0;
struct WordNode {
    string word;
    int count;
    struct WordNode *next;
};
using Word = struct WordNode *;

/*哈希表*/
struct HashTableNode {
    Word Table[MaxSize];
    int TableSize = MaxSize;
};

using HashTable = struct HashTableNode *;
using position = int;  //position是单词存储在哈希表中的位置
bool isIllegalChar(char ch);  //判断字符是否是下划线、数字、字母
string lowerConvert(string word); //将word中的字母字符转为小写
string fetch_word();  //从文本中获取一个单词
int wordcmp(string word1, string word2);  // 比较word1和word2的字典序,word1在前面是-1,

/*哈希表相应的操作集*/
HashTable Create();  // 创建一个Size大小的哈希表
position Hash(string word);  // 计算word的哈希码
Word Find(HashTable H, string word);  // 查找哈希表中是否有这个word的存在了
bool Insert(HashTable H, string word);  // 将word插入哈希表中
void ShowResult(HashTable H);  // 展现统计结果
void DestroyHashTable(HashTable H);  // 释放空间
int main()
{
    int div = 10;
    HashTable H = Create();
    while (cin.peek() != '#') {
        string word = fetch_word();
        if (word.length() > 0) {
            Insert(H, word);
        }
    }
    int num = wordcount / div;
    cout << wordcount << endl;
    while (num > 0) {
        ShowResult(H);
        num -= 1;
    }
    DestroyHashTable(H);
    return 0;
}

bool isIllegalChar(char ch)
{
    if ((ch <= 'z' && ch >= 'a' || ch <= 'Z' && ch >= 'A' || ch == '_' || ch <= '9' && ch >= '0')) {
        return false;
    } else {
        return true;
    }
}

string lowerConvert(string word)
{
    int len = word.length();
    for (int i = 0; i <= len - 1; ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = char(word[i] + 32);
        }
    }
    return word;
}

string fetch_word()
{
    stringstream word;
    word << "";
    char c;
    while (cin.peek() != '#') {
        c = cin.get();
        if (!isIllegalChar(c)) {
            word << c;
        } else {
            if (word.str().length() > 15) {
                return lowerConvert(word.str().substr(0, 15));
            } else if (word.str().length() > 0 && word.str().length() <= 15) {
                return lowerConvert(word.str());
            }
        }
    }
    if (word.str().length() > 15) {
        return lowerConvert(word.str().substr(0, 15));
    } else if (word.str().length() > 0){
        return lowerConvert(word.str());
    } else return "";
}

int wordcmp(string word1, string word2) // word1排在word2前面-1
{
    int len = word1.length() < word2.length() ? word1.length() : word2.length();
    for (int i = 0; i <= len - 1; ++i) {
        if (word1[i] < word2[i]) {
            return -1;
        } else if (word1[i] > word2[i]) {
            return 1;
        }
    }
    if (word1.length() < word2.length()) {
        return -1;
    } else if (word1.length() == word2.length()) {
        return 0;
    } else {
        return 1;
    }
}

HashTable Create()
{
    HashTable H = new (HashTableNode);
    for (int i = 0; i <= MaxSize - 1; ++i) {
        H->Table[i] = nullptr;
    }
    return H;
}

position Hash(string word)
{
    position pos = 0;
    for (auto c : word) {
        pos += c;
    }
    return pos;
}

Word Find(HashTable H, string word)
{
    position pos = Hash(word);
    int val = 1;
    Word resPos = H->Table[pos];
    while (resPos != nullptr) {
        val = wordcmp(resPos->word, word);
        if (val == 0) {
            break;
        }
        resPos = resPos->next;
    }
    return resPos;
}

bool Insert(HashTable H, string word)
{
    Word wordPos = Find(H, word);
    if (wordPos != nullptr) {
        wordPos->count += 1;
    } else {
        wordcount += 1;
        Word newWord = new (WordNode);
        newWord->word = word;
        newWord->count = 1;
        newWord->next = nullptr;
        position pos = Hash(word);
        if (H->Table[pos] == nullptr) {
            H->Table[pos] = newWord;
        } else {
            newWord->next = H->Table[pos]->next;
            H->Table[pos]->next = newWord;
        }
    }
    return true;
}


void ShowResult(HashTable H)
{
    int MaxCount = 0;
    Word res = nullptr;
    for (int i = 0; i <= H->TableSize - 1; ++i) {
        Word p = H->Table[i];
        while (p != nullptr) {
            if (p->count > MaxCount) {
                MaxCount = p->count;
                res = p;
            } else if (p->count == MaxCount && MaxCount > 0) {
                int val = wordcmp(p->word, res->word);
                if (val == -1) {
                    res = p;
                }
            }
            p = p->next;
        }
    }
    if (res != nullptr) {
        cout << res->count << ":" << res->word << endl;
        res->count = 0;
    }
}

void DestroyHashTable(HashTable H)
{
    delete H;
}
