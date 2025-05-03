#include<iostream>
#include<vector>
using namespace std;

 
void Toh(int n , int a, int b , int c){
    if(n>0){
        Toh(n-1, a,c,b);
        cout<<"Move disk from "<<a<< " to "<<c<<endl;
        Toh(n-1,  b,a,c);
    }
}
int main()
{
    cout<<"Tower of Honoi  for 3 disk "<<endl;
    Toh( 3,1,2,3);
return 0;
}
