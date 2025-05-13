// Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for maximizing the total value of the knapsack.
// Input: arr[] = {60, 10, 
//                 100,20
//                 120,30}, 
//                 W=50
// Output: 240 
 



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

    int n = 3;

    vi value(n,0);
    vi weight(n,0);
    value ={ 60,100,120};
    weight ={ 10,20,30,};
    int W = 50;
    vector<float>price(n,0);
    for(int i = 0 ; i< n; i++)
    {
        price[i] = (float)(value[i]/weight[i]);
        
    }

    for(int  i = 0 ; i <n; i++)
    for(int  j = 0 ; j <n; j++)
    {
        if(price[i] > price[j]){
            swap(value[i], value[j]);
            swap(weight[i], weight[j]);
            swap(price[i], price[j]);
        }
    }
    vi sol(n);
    int i = 0;
    float total=0;
    while(W>0 && i<n){
        if( weight[i] <= W) {

            total += value[i];
            int amt = min(W, weight[i]);
            W -= amt;
        }else {

            // float frac = W/weight[i];
            total += value[i];
        }
        i++; 
    }
    cout<<"TOTAL SUM : "<<total;
 
return 0;
}
