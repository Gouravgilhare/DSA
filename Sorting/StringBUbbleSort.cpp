#include<iostream>
#include<string.h>
using namespace std;
 
 
 
int main()
{
    char *str[]  = {

        (char *)"HELLO", (char *)"MY",(char *)"NAME",(char *)"IS",(char *)"GOURAV",(char *)"GILHARE"
    };
    int size = sizeof(str)/sizeof(str[0]);
    char temp [50];
    for(int i = 0 ; i<size; i++){
        for(int j = 0 ;j<size-i-1; j++ ){
            if(strcmp(str[j] ,str[j+1])>0){
              strcpy(temp, str[j]);
              strcpy(str[j],str[j+1]);
              strcpy(str[j+1] ,temp);
            }
        }
    }

   
    
        for(int j = 0 ; j<size ;j++ )
        cout << str[j]<<" ";
        cout<<endl;



        return 0;
    
}