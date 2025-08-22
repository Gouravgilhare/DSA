// pow(x,n).cpp


#include<bits/stdc++.h>

using namespace std;

double power(double x,int n){

	double ans = 1;
	long long m = n;

	if(m < 0 ){
		x = 1/x;
		m = -m;


	}
	while(m> 0 ){
		if(m%2 == 1){
			ans*=x;
			m--;
		}else{
			m/=2;
			x*=x;
		}
	}
return ans;
}


int main(){

	double x = 5 ;
	int n = 9;

	cout<<fixed<<setprecision(3)<<power(x,n);


	return 0;
}