// Q2B:
// A cruise trip has gone horribly wrong, and passengers are in dire need of rescue. As part of the rescue team, your challenge is to determine the fewest number of life-saving boats needed to save everyone. However, there's a catch. Each boat can hold a maximum of two people and has a weight capacity of X (where 1 ≤ X ≤ 30,000).
// Here's how the input is structured:
// 1.	The first line provides an integer, X, indicating the boat's maximum weight capacity.
// 2.	The next line offers an integer, N (where 1 ≤ N ≤ 50,000), representing the number of passengers awaiting rescue.
// 3.	This is followed by N integers specifying the weight of each individual passenger. Note that each weight, Wi, will satisfy 1 ≤ Wi ≤ X.
// Example
// For X=100 and N=4 with weights:
// W = {100, 60, 60, 40}
// The solution is 3 boats. The most efficient arrangement is:
// {100} - Only this boat can carry a person weighing 100. {60, 40} - Together, these two don't exceed the boat's limit. {60} - The remaining passenger.

#include<bits/stdc++.h>
using namespace std;
typedef vector<int>     vi;
typedef vector<vi>      vvi;
typedef vector<string>     vstr;
 
 
 
int main()
{
    int X ,N;
    cin >> X>>N;
    vi wi(N);
    for(int i = 0 ; i<N; i++)
        cin >> wi[i];
    
        sort(wi.begin(), wi.end());
        int currentWeight = 0,cnt=0,numOfBoats=0;
    for( int i = 0 ; i< wi.size(); i++)
    {   
        int totalweight = currentWeight + wi[i];  
        if(totalweight <= X)
        {    
            currentWeight += wi[i];
            cnt++;
            if(cnt == 2) 
            {
                cnt = 0;   
                currentWeight =0; 
                numOfBoats++;
            }   
        }  else {
            totalweight = 0 ;
            currentWeight = wi[i];
        

        }            
    }
 cout<<numOfBoats;
 
return 0;
}