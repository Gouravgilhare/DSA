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
 
 
int digit(int s, int d){

    int ans=0;
    int k =1, l =d;
    int temp = s;
    while(d>1){
        temp *= 10; temp += s;
   
        k *=10;
        d--;
    }
    cout<<temp<<endl;
    // cout<<k;
    int t = l;
    int j= 0;
    
    while(temp--){
        l =t;
        int n = k;
        ans =0;
        k = k+1;
        // cout<<k<< " ";
        while(l>0){

            int e = n%10;
            ans = ans + e;
            // cout<<ans<< " ";
            n = n/10;
            l--;
        }
        cout<<ans<<" ";
        if(ans == s)         
           return k;

        
      




    }




    return -1;
} 

int main()
{
    int s,d;
    cin >>s>>d;

    cout<<digit(s,d);
 
 
 
return 0;
}