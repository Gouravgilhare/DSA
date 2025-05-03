#include<iostream>
#include<vector>
#define  MaxSize 10

using namespace std;
 
void push( vector<int>& queue, int &f ,int &r){

    if(  r == MaxSize -1){
        cout<< "\nOVERFLOW!!";
        return; 
    }
    if( f== -1) f=0;
    r++;
    cout<<"\nEnter Number : ";
    int item;
    cin >> item;
    queue[r]= item;
    return;

}
void show( vector<int>&queue, int &f, int &r){
    if( f == -1 ){
        cout<<"UNDERFLOW";
        return;
    }
    int i =f;
    while(i<=r){
        cout<< queue[i]<< " "; i++;
    }

    cout<<endl;
    return;
}


void pop( vector<int>&queue, int &f, int &r){
    if( f == -1 || f>r ){
        cout<<"UNDERFLOW";
        return;
    }

    int item= queue[f];
    if( f == r){
        f= -1;
        r= -1;
    }
    f++;
    cout<< "Item  :  "<<item<< " is DELETED"; 
}
 
int main()
{
int f=-1,r=-1;char ch = 'n';
vector<int> queue( MaxSize, 0);

do{

    cout << "\n==========QUEUE===========\n";
    cout << "Choose Operation\n";
    
    cout<<"1. PUSH\n";
    cout<<"2. POP\n";
    cout<<"3. SHOW\n";
cout<<"4. EXIT\n";
gourav:
cout<<" Enter Choice :  ";

int choice;
cin>> choice;
switch( choice){
    
    case 1 : push(queue, f, r);
            break;
    case 2 : pop(queue,f, r);
            break;
    case 3 : show(queue,f, r);
            break;
    case 4 :    ch = 'y';
                exit(-1);
                break;
    default: cout<< "Enter Valid Number : ";
            goto gourav;
            break;
            
}

}while( ch != 'y' || ch!= 'Y');



return 0;
}