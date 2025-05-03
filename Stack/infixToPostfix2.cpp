#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int precedence(char op){

    if( op == '^') return 3;
    if( op == '*' || op == '/'|| op == '%') return 2;
    if( op == '-' || op == '+') return 1;

    return 0;
}
int main(){
    int testcase;
    cin >> testcase;

    
    while(testcase >-1){
        string str;
        getline(cin, str);
        
        stack<char>st;
        for(auto c : str){

            if(c >= 'a' && c<= 'z') cout<<c;

            else if(c == '(') st.push(c);
            
            else if( c == ')'){
                while(st.top() != '('){
                    cout<<st.top();
                    st.pop();
                }
                st.pop();
            }else{
                 if(precedence(st.top()) >= precedence(c)){
                  while(!st.empty() && st.top() != '(' ){
                     cout<<st.top();st.pop();
                    }
                }
              st.push(c);

            }
        }
        
        cout<<endl;
        testcase--;
    }


    return 0;
}
