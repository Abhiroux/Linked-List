#include <iostream>
using namespace std;


class Node{
  public:
  int data;
  Node *next;
};
void display(Node *p){
    while (p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

void CreateLoop(Node* &head_ref,int index){
    Node* temp=head_ref;
    Node* newNode;
    for(int i=1;i<index-1;i++){
        newNode=temp;
        temp=temp->next;
    }
    while (head_ref->next!=NULL)
    {
        head_ref=head_ref->next;
    }
    head_ref->next=newNode;
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
        }
        i++;
    }
    CreateLoop(head,3);
    // display(head);

    return 0;
}
