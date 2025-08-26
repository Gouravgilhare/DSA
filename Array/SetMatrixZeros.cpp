// SetMatrixZeros.cpp

#include<bits/stdc++.h>

using namespace std;


int main(){


	vector<vector<int>>arr ={
		{1,1,1},{1,0,1},{1,1,1}
	};


	int m =arr.size();
	int n = arr[0].size();

	vector<int>row(m,-1);
	vector<int>col(n,-1);
	


	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j <n ; j++){
			if(arr[i][j]==0){
				row[i]=0;
				col[j]=0;		
			}
		}
	}	


	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j <n ; j++){
			if(row[i] == 0 || col[j] == 0 ){
				arr[i][j]= 0;
			}
		}
	}	


	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j <n ; j++){
				cout<<arr[i][j]<<" , ";
		}
		cout<<" \n";
	}	

	
	


	return 0;
}