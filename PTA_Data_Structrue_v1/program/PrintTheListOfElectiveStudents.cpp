#include <bits/stdc++.h>
using namespace std;
struct node{
	char name[5];
}course[2501][40001];
int num[2501]; 
bool cmp(node a,node b)
{
	return strcmp(a.name, b.name) < 0;
}
int main()
{
	int n, k;	
    cin >> n >> k;
	int i, j;
	for(i = 0; i < n; i++) {
		char name[5];
        scanf("%s", name);
		int c;
		scanf("%d", &c);
		int id;
		for(j = 0; j < c; j++) {
			cin >> id;
            strcpy(course[id][num[id]++].name, name);
		}
	}
	for(i = 1; i <= k; i++) {
		sort(course[i], course[i] + num[i], cmp);
	}
	for(i = 1; i <= k; i++) {
		cout << i << " " << num[i] << endl;
		for(j = 0; j < num[i]; j++) {
			printf("%s\n", course[i][j].name);
		}
	}
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
struct SNode{
    priority_queue<string, vector<string>, greater<string>> StudentList;
};
using Student = struct SNode;
struct CNode{
    Student *CourseList;
};
using Course = struct CNode*;
Course _init_SelectedCourseList(int numStudent, int numCourse);
void PrintStudents(Student Students);
void _show_Result(Course SelectedCourseList, int numCourse);
int main()
{
    int numStudent, numCourse;
    cin >> numStudent >> numCourse;
    Course SelectedCourseList = _init_SelectedCourseList(numStudent, numCourse);
    _show_Result(SelectedCourseList, numCourse);
}

Course _init_SelectedCourseList(int numStudent, int numCourse)
{
    Course SelectedCourseList = new (struct CNode);
    SelectedCourseList->CourseList = new Student[numCourse + 1];
    string StudentName;
    int CourseNo, CourseNum;
    for (int i = 0; i <= numStudent - 1; ++i) {
        cin >> StudentName >> CourseNum;
        for (int j = 0; j <= CourseNum - 1; ++j) {
            cin >> CourseNo;
            SelectedCourseList->CourseList[CourseNo].StudentList.push(StudentName);
        }
    }
    return SelectedCourseList;
}
void PrintStudents(Student Students)
{
    while (!Students.StudentList.empty()) {
        cout << Students.StudentList.top() << endl;
        Students.StudentList.pop();
    }
}
void _show_Result(Course SelectedCourseList, int numCourse)
{
    for (int CourseNo = 1; CourseNo <= numCourse; ++CourseNo) {
        cout << CourseNo << " " << SelectedCourseList->CourseList[CourseNo].StudentList.size() << endl;
        PrintStudents(SelectedCourseList->CourseList[CourseNo]);
    }
}*/





/*#include <bits/stdc++.h>
using namespace std;
struct SNode{
    vector<string> Students;
};
using Student = struct SNode*;
struct HNode{
    unordered_map<int, Student> HashMap;
};
using HashMap = struct HNode*;
HashMap _init_HashMap(int numStudent);
void PrintStudents(Student StudentList);
void _show_Result(HashMap H, int numCourse);
int main()
{
    std::ios::sync_with_stdio(false);
    int numStudent, numCourse;
    cin >> numStudent >> numCourse;
    HashMap CourseSelectedList = _init_HashMap(numStudent);
    _show_Result(CourseSelectedList, numCourse);
    return 0;
}
HashMap _init_HashMap(int numStudent)
{
    HashMap CourseSelectedList = new (struct HNode);
    string StudentName;
    int numCourse, CourseNo;
    for (int i = 0; i <= numStudent - 1; ++i) {
        cin >> StudentName >> numCourse;
        for (int j = 0; j <= numCourse - 1; ++j) {
            cin >> CourseNo;
            auto search = CourseSelectedList->HashMap.find(CourseNo);
            if (search == CourseSelectedList->HashMap.end()) {
                Student StudentList = new (struct SNode);
                StudentList->Students.push_back(StudentName);
                CourseSelectedList->HashMap.insert(make_pair(CourseNo, StudentList));
            } else {
                CourseSelectedList->HashMap.at(CourseNo)->Students.push_back (StudentName);
            }
        }
    }
    return CourseSelectedList;
}
void PrintStudents(Student StudentList)
{
    sort(StudentList->Students.begin(), StudentList->Students.end());
    for(int i = 0; i <= StudentList->Students.size() - 1; ++i) {
        cout << StudentList->Students[i] << endl;
    }
}
void _show_Result(HashMap H, int numCourse)
{
    int CourseNo;
    for (CourseNo = 1; CourseNo <= numCourse; ++CourseNo) {
        auto Result = H->HashMap.find(CourseNo);
        if (Result != H->HashMap.end()) {
            cout << Result->first << " " << Result->second->Students.size() << endl;
            PrintStudents(Result->second);
        } else {
            cout << CourseNo << " " << 0 << endl;
        }
    }
}*/