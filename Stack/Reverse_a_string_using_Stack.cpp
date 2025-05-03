#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str;
    getline(cin ,str);

    int size= str.size();
    
    char st[size];
    int top=-1,i=0;
    while(top<size){
        top++;
        st[top]= str[i];
        i++;
    }i=0;
    while(top>-1&& i < str.size()){
        top--;
        str[i]= st[top];
        i++;
    }

    for(int i =0; i<str.size(); i++){
        cout<<str[i];
    }


    

    return 0;
}
