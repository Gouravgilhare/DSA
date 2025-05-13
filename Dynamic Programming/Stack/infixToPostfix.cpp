#include <iostream>
#include <stack>
#include <vector>
#include<string.h>

// #pragma execution_character_set("utf-8");

using namespace std;

int precedency(char op){
  
  if(op == '^')
   return 3;
  if(op == '*'|| op == '/')
   return 2;
  if(op == '+'|| op == '-') 
    return 1;

  return 0;
}
int main() {
  string str;
  getline(cin, str);
  int size = str.size();

  stack<char> st;

  for(int i = 0; i<size; i++){
  
    if(str[i] >='A' && str[i] <= 'Z'){
      cout<<str[i];
    }
    else if(str[i] == '(') st.push(str[i]);

    else if( str[i] == ')') {
      while(!st.empty() && st.top() != '(' ){
        cout<<st.top();
        st.pop();
      }
      if(!st.empty()) 
        st.pop();

    }else{

      if(precedency(st.top()) >= precedency(str[i])){
        while(!st.empty() && st.top() != '(' ){
          cout<<st.top();st.pop();
        }
      }
      st.push(str[i]);

    }


  }
       while(!st.empty()) {
          if(st.top()!='(')
            cout<<st.top();
        st.pop();
      }

  return 0;
}
