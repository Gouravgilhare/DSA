#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int p = size;
    vector<int>arr;
    stack<int>st;
    int a=0;
    for(int i= 0; i<size; i++){
        cin>>a;
        arr.push_back(a);
        st.push(a);

        while(!st.empty() && st.top() == p){
            cout<<st.top()<<" "; 
            st.pop();
            p--;
        }
        cout<<endl;
    }
   
    return 0;
}
