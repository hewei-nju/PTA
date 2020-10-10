#include <bits/stdc++.h>
using namespace std;


int main()
{
  int a,b;
  char c;
  cin >> a >> c;
  while(c != '=') {
    cin >> b;
    if (c == '+') {
        a = a + b;
    } else if(c == '-') {
        a = a - b;
    } else if(c == '*') {
        a = a * b;
    } else if (c == '/') {
      if(b == 0) {
        cout << "ERROR" << endl;
        return 0;
      } else {
          a = a / b;
        }
    } else {
      cout << "ERROR" << endl;
      return 0;
    }
    cin >> c;
  }
  cout << a << endl;
  return 0;
}