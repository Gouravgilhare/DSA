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
 

 int composite(int n){

    int count = n/4;
    int rem = n%4;

    if(rem ==1 || rem ==2 || rem == 3)
    {
        count--;
        rem +=4;
    }
    return count+1;
}
 
int main()
{

    int n ; 
    // cout<< "ENter value : ";
    cin >> n;
    
    // cout<<"\nthe Maximum number of composite number used : ";
    cout<<composite(n);
 
return 0;
}