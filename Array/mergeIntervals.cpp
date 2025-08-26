// mergeIntervals.cpp

#include<bits/stdc++.h>
using namespace std;


int main(){

	vector<vector<int>>arr ={
		{1,3},
		{2,5},
		{6,7},
		{8,10},
		{9,11}
	};


	sort(arr.begin(),arr.end(),[](const vector<int>&a, const vector<int>&b){return a[0] < b[0];});
	vector<vector<int>>result;
	vector<int>newIn = arr[0];

	for(auto a : arr){
		if(a[0] < newIn[1]){
			newIn[1] = max(a[1], newIn[1]); 
		}else{
			result.push_back(newIn);
			newIn = a;
		}
	}

	result.push_back(newIn);

	for(auto b : result){
		cout << "[ "<< b[0] <<" , "<<b[1]<<" ]"<<endl;
	}

	return 0;
}