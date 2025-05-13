#include<iostream>
#include<vector>
using namespace std;
 
 
 
int main()
{
vector<int> arr = {2,3,4,5,7,11};
int n = arr.size();
int k =1;
int low = 0 ; int high = n-1;
    while(low <= high)
    {
        int mid =  low + ( high-low)/2;
        int missing= arr[mid] - (mid+1);
            
        if(missing < k) low = mid +1; 
        else  high = mid -1;

    }
    cout<<low+k;
return 0;
}