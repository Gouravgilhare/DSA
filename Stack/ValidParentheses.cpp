#include <iostream>
#include <stack>
using namespace std;

int main() {
  string str;
  getline(cin, str);

  stack<char> st;
  for (char s : str) {
    if (s == '[' || s == '{' || s == ')')
      st.push(s);
    else
      st.pop();
  }
  if (st.empty())
    cout << "Balanced";
  else
    cout << "Not Balanced";
  return 0;
}