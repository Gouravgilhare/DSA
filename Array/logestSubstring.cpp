 // Longest Substring Without Repeating Characters.cpp

#include<bits/stdc++.h>

using namespace std;

int main(){

	vector<int> hash(256,-1);

	string s = "Gourav Gilhare";

	int n = s.length();

	int maxLen= 0, len= 0;

	int l= 0 , r= 0;


	while(r<n){

		if(hash[s[r]]!= -1 && hash[s[r]] >= l){
			l = hash[s[r]]+1;
		}

		hash[s[r]]=r;
		len = r - l +1;
		maxLen = max(len, maxLen);
		r++;
	}


	cout << maxLen;

	return 0;
}