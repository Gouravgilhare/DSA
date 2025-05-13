#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        data = a;
        next = nullptr;
    }
};

void insertNode(Node **head, int data)
{

    Node *newNode = new Node(data);
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;

}
void display( Node *head){

     Node * temp= head;
     if(temp == nullptr) return;
    while( temp != nullptr){
        cout<< temp->data<<"->";
        temp= temp->next;
    }cout<<"NULL";
 }


void bubbleSort(Node** head){
    if(*head == nullptr && (*head)->next == nullptr) return;
  
    Node* lastswapped = nullptr;

    bool swapped = false;
    
   
        do{
            Node* ptr= *head;     //temp node for iteration
            swapped = false;
            while (ptr->next != lastswapped){  

                if(ptr->data > ptr->next->data){ //bubble sort condition
                    swap(ptr->data, ptr->next->data); //swapping
                    swapped= true;        // for  condition do-while
                }
                ptr = ptr->next; //moving to next node 
            }

            lastswapped = ptr; //for inner loop condition
        }while(swapped);

}
int main()
{
    Node *head = nullptr;
    cout<<"linkedList"<<endl;
    for (int i = 1; i <= 10; i++)
    {
        insertNode(&head, abs(rand()%90 + 10));

    }
    display(head);
    cout<<"\nAfter sorting:"<<endl;
    bubbleSort(&head);
    display(head);




    return 0;
}