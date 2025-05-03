#include<iostream>
using namespace std;

int fact(int n){

    if( n ==0 ) return 1;

    return n*fact(n-1);
}
 
 int combi(int n, int r){

    return fact(n)/(fact(r)*fact(n-r));

 }
 
int main()
{   int n =5,r=3;
cout<<combi(n,r);
return 0;
}