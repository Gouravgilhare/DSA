// Question2 : Given three stacks of the positive numbers, the task is to find the possible equal maximum sum of the stacks with the removal of top elements allowed. Stacks are represented as an array, and the first index of the array represent the top element of the stack.
// Examples: 
// Input : stack1[] = { 3, 10}
//   stack2[] = { 4, 5 }
//   stack3[] = { 2, 1 }
// Output : 0



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
 
 
 
int MaxSum( vi&stack1, vi&stack2, vi&stack3)
{
    //calculating size;
    int s1 = stack1.size();
    int s2 = stack2.size();
    int s3 = stack3.size();

   
    //initial element is top of stack so top = 0;
    int top1 =0,top2 = 0,top3=0;
 
    //calculating sum of every stack
    int sum1=0,sum2=0,sum3=0;
    for(int i=0; i<s1;i++) sum1 += stack1[i];
    for(int i=0; i<s2;i++) sum2 += stack2[i];
    for(int i=0; i<s3;i++) sum3 += stack3[i];

    while(1){


        //if any stack is empty then return 0
        if( s1 == top1||s2 ==top2||s3 ==top3) return 0;

        //if sum of every stack is equal  then sum 1 || sum2 || sum3 is answer 
        if(sum1 == sum2 && sum2==sum3)
            return sum1;


        //sum1 if largest then removing its first element
        if(sum1> sum2 && sum1> sum3) {
            sum1 -= stack1[top1++];
        }    
        
        //sum2 if largest then removing its first element
        else if(sum1< sum2 && sum2> sum3) {
            sum2 -= stack2[top2++];
        }    
        
        //sum3 if largest then removing its first element
        else if(sum3> sum2 && sum1 < sum3) {
            sum3 -= stack3[top3++];
        }    
    }
}

int main()
{
    vi stack1= {3,2,1,1,1};
    vi stack2= {4,3,2};
    vi stack3= {1,1,4,1};

    cout<< MaxSum(stack1, stack2,stack3);
 
return 0;
}
