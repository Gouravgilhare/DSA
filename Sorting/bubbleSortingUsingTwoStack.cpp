#include<stack>
#include<iostream>
using namespace std;
 
 
 
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
        arr[i]= abs(rand()%90+10); //generating random 2 digit number
     
    stack<int>st1;    
    stack<int>st2;
    
    for(auto a : arr)
        st1.push(a); //pushing in stack
    int i=1;
    
    for(auto a : arr) //printing
    cout<<a<<" ";
    cout<<endl;



    while(!st1.empty()){
        
        int temp = st1.top();
        st1.pop();

        while(!st2.empty() && st2.top() > temp){ //pushing elements st2 to st1 if st2 is greater than st1
            st1.push(st2.top()); 
            st2.pop();
        }
        
       st2.push(temp);  //pushing the smaller element in st2
    }
    i=9;
    while(!st2.empty()){//pushing back to array
        arr[i]= st2.top();
        st2.pop();
        i--;
    }
    for(auto a : arr) //printing
         cout<<a<<" ";


return 0;
}