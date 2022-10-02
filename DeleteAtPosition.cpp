#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void Display(Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void DeleteAtFront(Node **p){
    if(*p==NULL){
        cout<<"List is Empty";
        return;
    }
    Node* temp=*p;
    *p=temp->next;
    delete temp;
}
void DeleteAtPosition(Node **p,int index){
    if(*p==NULL){
        cout<<"List is empty ";
        return;
    }
    else if(index==1){
        DeleteAtFront(p);
        return;
    }
    Node *n=new Node;
    Node *temp=*p;
    for(int i=1;i<index-1;i++){
        temp=temp->next;
        if(temp==NULL){
            cout<<"Invalid Position!! Deletion Failed\n";
            return;
        }
    }
    n=temp->next;
    temp->next=n->next;
}


int main(){
    int n;
    cout<<"Enter the Number of Nodes ";
    cin>>n;
    Node *head=0,*temp,*newnode;
    n>0 ? cout<<"Enter Elemnets"<<endl : cout<<"";  //if n<=0 then print nothing 
    for(int i=0;i<n;i++){
        newnode=new Node();
        cin>>newnode->data;
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    int ind;
    cout<<"Enter index for deletion ";
    cin>>ind;
    DeleteAtPosition(&head,ind);
    Display(head);

    return 0;
}