// searchIn2DMatrix.cpp

#include<bits/stdc++.h>
using namespace std;

int main(){

	vector<vector<int>> arr ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	int target = 13;

	int m = arr.size();
	int n = arr[0].size();

	int low  = 0 ;
	int high = (m*n)-1;

	while(low <= high){
		int mid = (low+high)/2;

		int row = mid/n; 
		int col = mid%n;

	if(arr[row][col] == target) 
		{
			cout<< " row : "<<row<<"\t col : "<<col;
			break;
		}
		else if (arr[row][col ]< target) low = mid+1;
		else high = mid-1; 
	}


	return 0;
}