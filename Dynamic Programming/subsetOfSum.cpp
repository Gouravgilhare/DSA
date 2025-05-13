<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
void printArr(vi&comb){

    for(int i =0; i<comb.size(); i++){
        cout<< comb[i]<<" ";
    } cout<<endl;
    return ;
}
void combsumback(vi&arr,int target,vi& comb,int start){
   if(target == 0){
    printArr(comb);
    return;
   } 

   for(int  i = start; i< arr.size(); i++){
        if(arr[i] > target){
            continue;
        }

        comb.push_back(arr[i]);
        combsumback(arr, target- arr[i],comb, i+1);
        comb.pop_back();


   }
}
 
void combSum(vi&arr, int target){
    sort(arr.begin(), arr.end());
    vi comb;
    combsumback(arr,target,comb,0);

}
 
int main()
{
    vi arr;
    int target;
    arr = {10, 1, 2, 7, 6, 1, 5};
    target = 8;
    combSum(arr, target);
 
 
 
return 0;
=======
#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
void printArr(vi&comb){

    for(int i =0; i<comb.size(); i++){
        cout<< comb[i]<<" ";
    } cout<<endl;
    return ;
}
void combsumback(vi&arr,int target,vi& comb,int start){
   if(target == 0){
    printArr(comb);
    return;
   } 

   for(int  i = start; i< arr.size(); i++){
        if(arr[i] > target){
            continue;
        }

        comb.push_back(arr[i]);
        combsumback(arr, target- arr[i],comb, i+1);
        comb.pop_back();


   }
}
 
void combSum(vi&arr, int target){
    sort(arr.begin(), arr.end());
    vi comb;
    combsumback(arr,target,comb,0);

}
 
int main()
{
    vi arr;
    int target;
    arr = {10, 1, 2, 7, 6, 1, 5};
    target = 8;
    combSum(arr, target);
 
 
 
return 0;
>>>>>>> b841c3d (dynamic)
}