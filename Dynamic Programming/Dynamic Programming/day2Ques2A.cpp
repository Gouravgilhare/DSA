// Q2A: 
// Steph wants to improve her knowledge of algorithms over winter break. She has a total of X (1 ≤ X ≤ 10^4 ) minutes to dedicate to learning algorithms. There are N (1 ≤ N ≤ 100) algorithms, and each one of them requires ai (1 ≤ ai ≤ 100) minutes to learn. Find the maximum number of algorithms she can learn.
// Example:
// N = 6, X = 15
// a = {4, 3, 8, 4, 7, 3}
// Result = 4


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
    int X = 15, N = 6, cnt=0;
    vi a(N);
    a = {4,3,8,4,7,3};

    sort(a.begin(), a.end());

    for( int i = 0 ; i < N; i++){
        if( a[i] <= X){
            X -= a[i];
            cnt++;
        }else break;
    }
 
 
    cout<<"Total algo she can learn is  : "<< cnt;
return 0;   
}