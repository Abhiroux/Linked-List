#include <iostream>

using namespace std;

class Node{
  public:
  int data;
  Node *next;
};

void Display(Node** p){
    Node* temp=*p;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while (temp!=*p);
    cout<<"Head";
}

// void Display(Node* p){
//     Node* temp=new Node;
//     temp=p->next;
//     cout<<p->data<<" ";
//     while (temp!=p)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }

void createCircular(Node** headRef){
    Node* temp=new Node;
    temp=*headRef;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*headRef;
}

int main()
{
    int i=0,n;
    cout<<"Enter Number of Elements ";
    cin>>n;
    Node *temp,*newnode,*head=0;
    while(i<n){
        newnode=new Node;
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
            temp->next=head;
        }
        i++;
    }
    Display(&head);
    


    return 0;
}
