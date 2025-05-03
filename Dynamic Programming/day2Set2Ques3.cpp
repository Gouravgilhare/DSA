#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
 
 
int main()
{
    vi price;
    int k = 2;  price ={10,22,5,75,65,80};
    // price ={12,14,17,10,14,13,12,15}; k = 3;
    // price ={10,12,3,4,22,5,75,65,80}; k = 2;
    // price ={5,3,10,22,75,80}; int k = 1;

    int minp=price[0];int amt=0;

    for(int i = 1;i<price.size();i++)
    {
        
        if(price[i]> minp && price[i+1] < price[i] && k>0)
        {   
            int maxi=price[i];

            if(k ==1 ){
                for(int j = i+1 ; j<price.size(); j++)
                maxi = max( maxi, price[j]);
            }

                amt += maxi-minp;
                if(price[i+1] < price[i+2] )
                minp = price[i+1];
                else
                minp = price[i+2];
                k--;
        }

    }

    cout<<amt;
 
 
return 0;
}