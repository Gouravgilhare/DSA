// MinCoin.cpp

#include<bits/stdc++.h>

using namespace std;

int minCoin(int amt, vector<int>&coins,vector<int>&dp){
	if (amt == 0) return 0;

	int ans = INT_MAX;
	for(int i = 0 ; i< coins.size(); i++){
		if(amt-coins[i] >= 0){

			int subAns = 0;
			if(dp[amt-coins[i]]!= -1) {
				subAns = dp[amt-coins[i]];
			} else 
				subAns =minCoin(amt-coins[i], coins ,dp);
			if(subAns != INT_MAX && subAns+1 < ans)
				ans =subAns+1;

		}


	}

dp[amt] =  ans;
	return ans;

}


int main(){

	int amt= 18;
	vector<int>coins = {1 ,5, 7};
	vector<int>dp(amt+1, -1);
	dp[0]=0;
	cout<<minCoin(amt, coins, dp);


	return 0;
}


