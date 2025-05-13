// Question 3:
// Given an amount, find the minimum number of notes of different denominations that sum up to the given amount. Starting from the highest denomination note, try to accommodate as many notes as possible for a given amount.
// We may assume that we have infinite supply of notes of values {2000, 500, 200, 100, 50, 20, 10, 5, 1} 
// Examples: 
 
// Input : 800
// Output : Currency  Count 
//          500 : 1
//          200 : 1
//          100 : 1



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
    vi notes ={ 2000,500,200,100,50,20,10,5,1};

    int target;
    cin >>target;

    int countNotes=0;

    int top=0;

    //bruteforce
    // while(target>0){
    //     if(target > notes[top]){
    //         int temp = top;
    //         target -= notes[top++];
    //         if(target > notes[temp]||  target == notes[temp]){
    //             top = temp;
    //         }
    //         countNotes++;
    //     }else if( target == notes[top])
    //     {
    //         countNotes++; 
    //         target -= notes[top];   
    //     } 
    //     else top++;
        
    // }
 
    //most optimal solution
    for(int note : notes)
    {
        if(target>= note)
            {
                countNotes += target / note;
                target %= note;
            
            }   

    }
    cout<< countNotes;
return 0;
}
