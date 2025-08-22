// trapping_rainwate.cpp

#include <bits/stdc++.h>
using namespace std;


int maxArea(int *a, int n){
	int l = 0 , r = n-1;

	int ans= 0;
	while(l < r){
		int h = min(a[l], a[r]);
		ans = max(ans, h*(r-l));

		if(a[l] < a[r]) l++;
		else r--;
	}

	return ans;
}


int main(){

	int n = 10;
	int a[n] ={1,8,6,2,5,4,8,3,7};
	
	cout <<"maxArea : "<<maxArea(a, n);


	return 0;
}