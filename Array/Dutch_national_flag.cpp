// Dutch_national_flag.cpp

#include<bits/stdc++.h>
using namespace std;

int main(){


	vector<int> arr = {
		2,2,0,1,0,1,2,2
	};

	int mid = 0, low= 0, high = arr.size()-1;

	while(mid <= high){
		if(arr[mid]==1)mid++;
		else if(arr[mid]==0){
			swap(arr[mid], arr[low]);
			mid++;
			low++;
		}else{
			swap(arr[high], arr[mid]);
			high--;
		}
	}

	for(auto a : arr){
		cout << a <<" ";
	}


	return 0;
}