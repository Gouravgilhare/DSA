#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
void printArr(vi&subarr ){
    cout<< " [";
    for(auto a : subarr)
        cout<<a<<" ";
    cout<< " ]";
    cout<<endl;
}

void subset(vi&arr, vi&subarr, int index){
    if(index == arr.size()){
        printArr(subarr);
        return;
    }

    subarr.push_back(arr[index]);
    subset(arr,subarr,index+1);
    subarr.pop_back();
    subset(arr,subarr,index+1);   

}


void gen(vi&arr){

    vi subarr;

    subset(arr,subarr, 0);

}
 
 
int main()
{
vi arr;
arr= {1,2,3,4};

gen(arr);
 
 
 
return 0;
}