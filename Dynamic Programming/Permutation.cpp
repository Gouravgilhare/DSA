#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
 

void printer(vi&arr){
    for(auto a : arr){
        cout<<a<<" ";
        
    }
    cout<<endl;
}
void permute(vi&arr, int start){


    if(start == arr.size()) {
        printer(arr);
        return;
    }
    for(int i=start ; i < arr.size(); i++){
        swap(arr[start], arr[i]);
        permute(arr, start+1);
        swap(arr[start], arr[i]);
    }


}
 
int main()
{

    vi arr;
    arr={1,2,3};
    permute(arr, 0);
 
 
return 0;
}