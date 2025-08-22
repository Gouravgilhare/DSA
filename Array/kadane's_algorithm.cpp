// kadane's_algorithm.cpp
#include<bits/stdc++.h>

using namespace std;


int main(){


	int a[6] = {-1,2,7,-6,-4,3};

	int max_sum = 0;
	int curr_sum = 0 ;
	for(int i =0 ; i < 6; i++){
		curr_sum+=a[i];
		if(curr_sum > max_sum) 
			max_sum = curr_sum;
		else 
			curr_sum= 0;

	}

	cout<<max_sum;


	return 0;

}