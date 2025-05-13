#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
typedef vector<int>     vi;
typedef vector<ll>      vll;
typedef vector<vi>      vvi;
typedef vector<vll>      vvll;
typedef pair<int,int>   pii;
typedef pair<ll,ll>     pll;
typedef vector<pii>     vpii;
typedef vector<string>     vstr;
typedef vector<pll>     vpll;
 
 
 
int main()
{
    vi coins(4,0);
    coins = {1,2,5,10};
    int n ; 
    cout<<"Enter input number : ";
    cin>> n;
    int cnt=0;
    reverse(coins.begin(),coins.end());
    int i = 0;
    
    for(auto coin : coins){

        cnt += n/coin;
        n %=coin;
    }
    cout<<cnt;
 
 
 
return 0;
}