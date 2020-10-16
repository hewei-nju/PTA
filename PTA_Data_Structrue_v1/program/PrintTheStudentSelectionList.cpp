#include <bits/stdc++.h>
using namespace std;
struct CNode{
    priority_queue<int, vector<int>, greater<int>> Courses;
};
using Course = struct CNode*;
struct HNode {
    unordered_map<string, Course> HashMap;
};
using HashTable = struct HNode*;
HashTable _init_HashMap(int numCourse);
void _Print_Courses(Course CourseList);
void _show_Result(HashTable H, int numStudent);

int main()
{
    int numStudent, numCourse;
    cin >> numStudent >> numCourse;
    HashTable CourseSelectedList = _init_HashMap(numCourse);
    _show_Result(CourseSelectedList, numStudent);
    return 0;
}

HashTable _init_HashMap(int numCourse)
{
    HashTable CourseSelectedList = new (struct HNode);
    int CourseNo, numStudent;
    string StudentName;
    for (int i = 0; i <= numCourse - 1; ++i) {
        cin >> CourseNo >> numStudent;
        for (int j = 0; j <= numStudent - 1; ++j) {
            cin >> StudentName;
            auto search = CourseSelectedList->HashMap.find(StudentName);
            if (search == CourseSelectedList->HashMap.end()) {
                Course CourseList  = new (struct CNode);
                CourseList->Courses.push(CourseNo);
                CourseSelectedList->HashMap.insert(make_pair(StudentName, CourseList));
            } else {
                CourseSelectedList->HashMap.at(StudentName)->Courses.push(CourseNo);
            }
        }
    }
    return CourseSelectedList;
}
void _Print_Courses(Course CourseList)
{
    while (!CourseList->Courses.empty()) { 
        // usighed 数据类型可能导致死循环
        cout << " " << CourseList->Courses.top();
        CourseList->Courses.pop();
    }
    cout << endl;
}
void _show_Result(HashTable H, int numStudent)
{
    string StudentName;
    for (int i = 0; i <= numStudent - 1; ++i) {
        cin >> StudentName;
        auto Result = H->HashMap.find(StudentName);
        if (Result != H->HashMap.end()) {
            Course CourseList = Result->second;
            cout << Result->first << " " << Result->second->Courses.size();
            _Print_Courses(CourseList);
        } else {
            cout << StudentName << " " << 0 << endl;
        }
    }
}