#include<iostream>
#include<vector>
#define MaxSize  10

using namespace std;

void push(vector<int>&st, int &top){
    if(top == MaxSize-1){
        cout<< "OVERFLOW !!";
        return;
    }
    
    int item;
    cout<< "\nEnter Number : ";
    cin >> item;
    top++;
    st[top]= item;
}

void pop( vector<int>&st, int &top){

    if( top == -1) {
        cout << "UNDERFLOW!!";
        return;
    }
    int item = st[top] ;
    top--;
    cout<< "Item : " << item<< " is DELETED!!";

}
void popMiddle( vector<int>&st , int&top ){
    if( top == -1) {
        cout << "UNDERFLOW!!";
        return;
    }
    cout<<"\n Enter item to delete : ";
    int i= st.size()/2 ;
    int item =st[i];
    int e = 0;
    while (e<top){
         
            st[e+i] = st[e+i+1];
            e++;
    }
    top--;
}



    


void show( vector<int> &st, int &top){
    if( top == -1) {
        cout << "UNDERFLOW!!";
        return;
    }
    cout<< " STACK \n" ;
    int i=top;
    while( i> -1){
        cout<<" "<<st[i]<<endl;
        i--;
    }

}
 
 
int main()
{
    vector<int> st(MaxSize,0);
    int top=-1;char ch = 'n';

    do{

        cout << "\n==========STACK===========\n";
        cout << "Choose Operation\n";
        
        cout<<"1. PUSH\n";
        cout<<"2. POP\n";
        cout<<"3. SHOW\n";
        cout<<"4. Delete Middle Element\n";
    cout<<"5. EXIT\n";
    gourav:
    cout<<" Enter Choice :  ";

    int choice;
    cin>> choice;
    switch( choice){
        
        case 1 : push(st, top);
                break;
        case 2 : pop(st,top);
                break;
        case 3 : show(st,top);
                break;
        case 4 : popMiddle(st,top);
                break;
        case 5 :    ch = 'y';
                    exit(-1);
                    break;
        default: 
                cout<< "Enter Valid Number : ";
                goto gourav;
                break;
                
    }
    
}while( ch != 'y' || ch!= 'Y');


    
return 0;
}