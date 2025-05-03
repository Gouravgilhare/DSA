// Question 1:  Given two integers s and d, find the smallest possible number that has exactly d digits and a sum of digits equal to s.
// Return the number as a string. If no such number exists, return “-1”.
// Examples : 
 
// Input  : s = 9, d = 2
// Output : 18
  
// Code:
// Greedy Technique
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
 

string SmallestNum( int s, int d){

    if(s < 0 || s > 9*d) return "-1";  // s is too large and too small

    string result(d,'0');

    s--; //reserve 1 place for last value

    for(int i = d-1; i>0 ;i--){
        if(s>9){
            result[i] = '9';   // if s > 9 then it possible that last value will be 9
            s -= 9;     //subtracting s by 9;
        }else{
            result[i]='0'+s;   // s < 9 then the problity is single digit so we can directly add in result
            s=0;   // now s is complete zero
        }
    }
    result[0]= '1'+s;  // if s is  not completely zero then s will be 1 + s;
    return result;
}
 
int main()
{
    int d = 5;
    int s = 45;

    cout<<SmallestNum(s,d);
 
 
return 0;
}
