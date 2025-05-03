#include<iostream>
using namespace std;
 
 int hcf( int n , int r){

    if( r==0) return n;

    return hcf (r, n%r);
 }
 
int main()
{
int n = 125;
int r= 5;
cout<<hcf(n,r);

return 0;
}