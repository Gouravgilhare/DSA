#include<iostream>
#include<vector>
#define Max_size 5
using namespace std;

int main(){
        
        vector<int> st(Max_size,0);
        for(int i= 0 ; i< Max_size;i++){
            cin >> st[i];
        }

       for(int i= Max_size/2;i < Max_size-1;i++){
        st[i]=st[i+1];
       }
        
        for(int i=0; i<Max_size-1; i++){
            cout<<st[i]<<" ";
        }

        return 0;
}
