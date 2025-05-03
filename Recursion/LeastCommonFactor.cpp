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
 
 
 
int gcd( int a, int b){
    if( b == 0 ) return a;
    return gcd(b,a%b);
}
int LCM(int a, int  b ) {
    return (a*b)/gcd(a,b);
}

int main()
{

    int a= 15,b = 25;
    cout<<"LCM : "<<LCM(a,b);


return 0;
}
